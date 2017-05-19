//
//  OperandFactory.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 12/2/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "OperandFactory.h"
#include <string>

using namespace std;

Operand* OperandFactory::createOperand(const string& s)
{
    std::regex syntax("^\\$?-?([0-9]+)*$", std::regex_constants::icase);
    int x;
    
    if(regex_match(s, syntax))
    {
        if(s[0] == '$')        // This is an address
        {
            x = std::stoi(s.substr(1));
            
            if( x < 0 || x > 1023)
                throw std::invalid_argument("Address is out of range");
            
            else return new AddressOperand(std::stoi(s.substr(1)));
        }
        
        else
            return new ConstantOperand(std::stoi(s));
        
        
    }
    else throw std::invalid_argument("Wrong Syntax in operand " + s);

}

