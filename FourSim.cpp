//
//  FourSim.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 12/11/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "FourSim.h"

FourSim::FourSim(std::string pathParam)
{
    path = pathParam;
    
    simulators[0] = simulatorOne;
    simulators[1] = simulatorTwo;
    simulators[2] = simulatorThree;
    simulators[3] = simulatorFour;
    
    DataMemory::createInstance();

    initializeSimulators();

}

void FourSim::initializeSimulators()
{
    std::string s;
    ifstream inputFile;
    
    inputFile.open(path);
    
    for(int i=0; i<4; i++)
    {
        getline(inputFile, s);
        s.erase(remove(s.begin(), s.end(), '\n'), s.end());  // remove all the endlines

        simulators[i] = new Simulator(s);
        
        threads[i] = thread(&Simulator::buildAndRun, simulators[i]);
    }
}

void FourSim::buildAndRun()
{
    for(auto& thr: threads)
    {
        try {
            thr.join();
        } catch (invalid_argument e) {
            cerr<<"Error : "<<e.what();
        }
    }
}

void FourSim::displayMemory()
{
    simulatorOne->displayMemory();
}
