//
//  WriteInstr.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/28/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef WriteInstr_h
#define WriteInstr_h

#include "Instruction.h"
#include "Operand.h"
#include <mutex>


class WriteInstr : public Instruction
{
    Operand* x;
    std::string instr;
    static std::mutex mtx;
public:
    WriteInstr(Operand*, std::string);
    void execute();
    std::string print();

};

#endif /* WriteInstr_hpp */
