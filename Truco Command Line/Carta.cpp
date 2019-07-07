//
//  Carta.cpp
//  Truco Command Line
//
//  Created by Brian Plotnik on 6/26/19.
//  Copyright © 2019 Brian Plotnik. All rights reserved.
//

#include "Carta.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>

// < operator for Cartas
bool operator<(const Carta& left, const Carta& right)
{
    return left.mRank > right.mRank;
}

// > operator for Cartas
bool operator>(const Carta& left, const Carta& right)
{
    return left.mRank < right.mRank;
}

// == operator for Cartas
bool operator==(const Carta& left, const Carta& right)
{
    return left.mRank == right.mRank;
}

// Prints out carta
std::ostream& operator<<(std::ostream& os, const Carta carta)
{
    if (carta.mNumero == 1) {
        os << "Ancho de " << carta.mPalo;
    }
    else
    {
        os << carta.mNumero << " de " << carta.mPalo;
    }
    
    return os;
}

// Creates the maso
std::vector<Carta> loadMaso()
{
    std::vector<Carta> maso;
    
    // Creates file stream with Maso
    std::ifstream fstream("Maso de Truco.txt");
    
    // Loops through file parsing Cartas
    while (true)
    {
        // Gets line
        std::string line;
        std::getline(fstream, line);
        
        // Exits at end of file
        if (line == "")
        {
            break;
        }
        // Creates Carta from line
        else
        {
            std::stringstream ss;
            ss << line;
            
            // Gets numero
            unsigned numero;
            ss >> numero;
            
            // Gets Palo
            std::string palo = "";
            ss >> palo;
            
            // Gets rank
            unsigned rank;
            ss >> rank;
            
            // Creates Carta
            Carta carta(numero, palo, rank);
            
            // Pushes Carta onto Maso
            maso.push_back(carta);
        }
    }
    return maso;
}


// Mano Constructor
Mano::Mano(std::vector<Carta>& maso, int player)
{
    // Shuffles Maso
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(maso.begin(), maso.end(), std::default_random_engine(seed));
    
    // Loads mano for first player
    if (player == 1) {
        mMano.push_back(maso[0]);
        mMano.push_back(maso[1]);
        mMano.push_back(maso[2]);
    } else {
        mMano.push_back(maso[3]);
        mMano.push_back(maso[4]);
        mMano.push_back(maso[5]);
    }
    
    // Calculates emvido
    calcEnvido();
}

void Mano::calcEnvido()
{
    std::string palo1 = mMano[0].mPalo;
    std::string palo2 = mMano[1].mPalo;
    std::string palo3 = mMano[2].mPalo;
    
    int numero1 = mMano[0].mNumero;
    int numero2 = mMano[1].mNumero;
    int numero3 = mMano[2].mNumero;
    
    // Assigns 0 to 10,11,12
    if (numero1 == 10 || numero1 == 11 || numero1 == 12)
    {
        numero1 = 0;
    }
    
    if (numero2 == 10 || numero2 == 11 || numero2 == 12)
    {
        numero2 = 0;
    }
    
    if (numero3 == 10 || numero3 == 11 || numero3 == 12)
    {
        numero3 = 0;
    }
    
    // Calculates Envido
    if ((palo1 == palo2) && (palo2 == palo3))
    {
        mEnvido = std::max({numero1 + numero2, numero1 + numero3, numero2 + numero3}) + 20;
    }
    else if ((palo1 == palo2) && (palo2 != palo3))
    {
        mEnvido = numero1 + numero2 + 20;
    }
    else if ((palo1 == palo3) && (palo1 != palo2))
    {
        mEnvido = numero1 + numero3 + 20;
    }
    else if ((palo2 == palo3) && (palo3 != palo1))
    {
        mEnvido = numero2 + numero3 + 20;
    }
    else
    {
        mEnvido = std::max({numero1, numero2, numero3});
    }
}

// Getter function for mano
std::vector<Carta> Mano::getmMano()
{
    return mMano;
}

// Getter function for envido
unsigned Mano::getEnvido()
{
    return mEnvido;
}

// Function: << operator for Mano
// Purpose: Prints out Mano
std::ostream& operator<<(std::ostream& os, Mano mano)
{
    for (Carta i : mano.getmMano()) {
        os << i << std::endl;
    }
    
    return os;
}















