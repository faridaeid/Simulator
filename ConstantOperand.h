//
//  ConstantOperand.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef ConstantOperand_hpp
#define ConstantOperand_hpp

#include "Operand.h"

class ConstantOperand : public Operand
{
    int val;
public:
    ConstantOperand(int v=0);
    int getValue() const;

};


#endif /* ConstantOperand_hpp */
