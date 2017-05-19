//
//  MulInstr.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright � 2016 Farida Eid. All rights reserved.
//

#include "MulInstr.h"

MulInstr::MulInstr(Operand* input1, Operand* input2, AddressOperand* output, std::string s)
{
	in1 = input1;
	in2 = input2;
	out1 = output;
    instr = s;
}

void MulInstr::execute()
{
	out1->setValue(in1->getValue() * in2->getValue());
}

std::string MulInstr::print()
{
    return instr;
}
