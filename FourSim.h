//
//  FourSim.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 12/11/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef FourSim_hpp
#define FourSim_hpp

#include "Simulator.h"
#include <string>
#include <fstream>
#include <thread>
#include "DataMemory.h"

class FourSim
{
    Simulator *simulatorOne, *simulatorTwo, *simulatorThree, *simulatorFour;
    Simulator* simulators[4];
    thread threads[4];
    std::string path;
    
    void initializeSimulators();
    
public:
    FourSim(std::string);       // constructor takes text file that contains the four file names
    void buildAndRun();
    void displayMemory();
};

#endif /* FourSim_hpp */
