//
//  ConstantOperand.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "ConstantOperand.h"


ConstantOperand::ConstantOperand(int v):val(v)
{
}

int ConstantOperand::getValue() const
{
    return val;
}
