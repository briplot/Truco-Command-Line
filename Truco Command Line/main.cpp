//
//  main.cpp
//  Truco Command Line
//
//  Created by Brian Plotnik on 6/26/19.
//  Copyright © 2019 Brian Plotnik. All rights reserved.
//

#include <iostream>
#include "Carta.h"
#include <thread>


int main() {
    std::vector<Carta> maso = loadMaso();
    
    std::string userInput;
    
    std::cout << "Bienvenido al Truco Braquero!!!" << std::endl;
    std::cout << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(4));
    
    
    
    do {
        // Reparte las cartas
        Mano manoJugador(maso, 1);
        Mano manoCPU(maso, 2);
        std::cout << "Repartiendo las cartas." << std::endl;
        std::cout << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(2));
        
        // Prints out Mano
        std::cout << "Esta es tu mano:" << std::endl;
        std::cout << manoJugador << std::endl;
        std::cout << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(3));
        
        // Pregunta por el envido
        std::string envidoInput;
        std::cout << "Queres jugar el envido?('Si' o 'No') ";
        std::cin >> envidoInput;
        std::cout << std::endl;
        
        // Se juega el envido
        if (envidoInput == "si" || envidoInput == "Si")
        {
            std::cout << "La CPU tiene " << manoCPU.getEnvido() << std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(1));
            std::cout << "Vos tenes " << manoJugador.getEnvido() << std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(1));
            
            // Prints who won
            if (manoCPU.getEnvido() >= manoJugador.getEnvido())
            {
                std::cout << "La puta madre! Perdiste! Como vas a cantar el envido con " << manoJugador.getEnvido() << "!" << std::endl;
            }
            else
            {
                std::cout << "Buena crack! Ganaste el envido!" << std::endl;
                std::cout << std::endl;
            }
        }
        
        std::cout << std::endl;
        std::cout << "Queres jugar devuelta? ";
        std::cin >> userInput;
        std::cout << std::endl;
    } while ((userInput != "No") && (userInput != "no"));
    
    
    
    return 0;
}
