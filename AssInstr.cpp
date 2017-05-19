//
//  AssInstr.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "AssInstr.h"

AssInstr::AssInstr(Operand* input, AddressOperand* output, std::string s)
{
    in1 = input;
    out1 = output;
    instr = s;
}

void AssInstr::execute()
{
    out1->setValue(in1->getValue());
}

std::string AssInstr::print()
{
    return instr;
}
