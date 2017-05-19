//
//  ReadInstr.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef ReadInstr_h
#define ReadInstr_h

#include "Instruction.h"
#include "AddressOperand.h"

class ReadInstr : public Instruction
{
    AddressOperand* x;
    std::string instr;
public:
    ReadInstr(Operand*, std::string);
    void execute();
    std::string print();

};
#endif /* ReadInstr_hpp */
