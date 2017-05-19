//
//  AddressOperand.cpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#include "AddressOperand.h"
#include "DataMemory.h"
#include <mutex>

AddressOperand::AddressOperand(int v):val(v){};

int AddressOperand::getValue() const
{
    return  DataMemory::getInstance()->operator[](val);

}

int AddressOperand::getAddressValue() const
{
	return val;
}

void AddressOperand::setValue(const int& v)
{
    mtx.lock();
	DataMemory::getInstance()->operator[](val) = v;
    mtx.unlock();

}

std::mutex AddressOperand::mtx;
