//
//  AssInstr.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef AssInstr_h
#define AssInstr_h

#include "Instruction.h"
#include "AddressOperand.h"

class AssInstr : public Instruction
{
    Operand* in1;
    AddressOperand* out1;
    std::string instr;

public:
    AssInstr(Operand*, AddressOperand*, std::string);
    void execute();
    std::string print();

};

#endif /* AssInstr_hpp */
