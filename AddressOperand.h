//
//  AddressOperand.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef AddressOperand_hpp
#define AddressOperand_hpp

#include "Operand.h"
#include <mutex>

class AddressOperand : public Operand
{
    int val;
    static std::mutex mtx;
    
public:
    AddressOperand(int v =0);
    int getValue() const;
	int getAddressValue() const;
    void setValue(const int& v);
};

#endif /* AddressOperand_hpp */
