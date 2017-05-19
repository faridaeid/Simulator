//
//  NegInstr.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "NegInstr.h"

NegInstr::NegInstr(Operand* input, AddressOperand* output, std::string s)
{
    in1 = input;
    out1 = output;
    instr = s;
}

void NegInstr::execute()
{
    out1->setValue(-in1->getValue());
}

std::string NegInstr::print()
{
    return instr;
}
