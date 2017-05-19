//
//  WriteInstr.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "WriteInstr.h"
#include <iostream>

WriteInstr::WriteInstr(Operand* input, std::string s)
{
    x = input;
    instr = s;
}

void WriteInstr::execute()
{
    mtx.lock();
    std::cout<<x->getValue()<<std::endl;
    mtx.unlock();
}

std::string WriteInstr::print()
{
    return instr;
}

std::mutex WriteInstr::mtx;
