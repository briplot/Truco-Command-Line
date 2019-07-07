//
//  Carta.hpp
//  Truco Command Line
//
//  Created by Brian Plotnik on 6/26/19.
//  Copyright © 2019 Brian Plotnik. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


struct Carta {
    unsigned mNumero;
    std::string mPalo;
    unsigned mRank;
    
    // Function: Carta Constructor
    // Purpose:
    // Parameters:
    // Returns: Nothing
    Carta(unsigned numero, std::string palo, unsigned rank)
    {
        mNumero = numero;
        mPalo = palo;
        mRank = rank;
    }
};

// Comparison operators for cards
bool operator<(const Carta& left, const Carta& right);
bool operator>(const Carta& left, const Carta& right);
bool operator==(const Carta& left, const Carta& right);


// Function: << operator for Carta
// Purpose: Prints out Carta
std::ostream& operator<<(std::ostream& os, const Carta carta);

// Creates Maso
std::vector<Carta> loadMaso();

class Mano {
private:
    std::vector<Carta> mMano;
    unsigned mEnvido;
    
public:
    // Constructor
    Mano(std::vector<Carta>& maso, int player);
    
    // Calculates Envido
    void calcEnvido();
    
    // Getter function for mano
    std::vector<Carta> getmMano();
    
    // Getter function for envido
    unsigned getEnvido();
    
    
};

// Function: << operator for Mano
// Purpose: Prints out Mano
std::ostream& operator<<(std::ostream& os, Mano mano);




// Function:
// Purpose:
// Parameters:
// Returns:
