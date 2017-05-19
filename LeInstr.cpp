//
//  LeInstr.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright � 2016 Farida Eid. All rights reserved.
//

#include "LeInstr.h"

LeInstr::LeInstr(Operand* input1, Operand* input2, AddressOperand* output, std::string s)
{
	in1 = input1;
	in2 = input2;
	out1 = output;
    instr = s;
}

void LeInstr::execute()
{
	if (in1->getValue() <= in2->getValue())
		out1->setValue(1);
	else out1->setValue(0);
}

std::string LeInstr::print()
{
    return instr;
}
