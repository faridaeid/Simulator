//
//  NegInstr.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef NegInstr_h
#define NegInstr_h

#include "Instruction.h"
#include "AddressOperand.h"

class NegInstr : public Instruction
{
    Operand* in1;
    AddressOperand* out1;
    std::string instr;
    
public:
    NegInstr(Operand*, AddressOperand*, std::string);
    void execute();
    std::string print();
};

#endif /* NegInstr_hpp */
