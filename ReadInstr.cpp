//
//  ReadInstr.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "ReadInstr.h"
#include <iostream>

ReadInstr::ReadInstr(Operand* input, std::string s)
{
    instr = s;
    
    if((x = dynamic_cast<AddressOperand*>(input)) == NULL)
        throw std::invalid_argument ("Operand must be a data address");
}

void ReadInstr::execute()
{
    int val;
    std::cin>>val;
    x->setValue(val);
}

std::string ReadInstr::print()
{
    return instr;
}
