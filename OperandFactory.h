//
//  OperandFactory.h
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef OperandFactory_h
#define OperandFactory_h

#include "AddressOperand.h"
#include "ConstantOperand.h"
#include <regex>

class OperandFactory
{
public:
    static Operand* createOperand(const std::string& s);
};

#endif /* OperandFactory_h */
