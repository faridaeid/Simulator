//
//  main.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "FourSim.h"

int main()
{
    FourSim fourSim("TestFiles2.txt");
    
    fourSim.buildAndRun();
    fourSim.displayMemory();
    
}
