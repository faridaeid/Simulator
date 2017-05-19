//
//  Instruction.h
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef Instruction_h
#define Instruction_h

#include <string>

class Instruction
{
public:
    virtual void execute()=0;       // execute the instruction, throws exception if sth wrong happened  
	virtual std::string print() = 0;
};

#endif /* Instruction_h */
