/*
 * Command Design
 * 16bit
 * [Reservation] [Operator] [Storage] [Operand1] [Operand2]
 *       2           3          3         4          4
 *
 * Design changes depending on command arguments
 *
 * Operand :
 *   register or number
 *   Use first bit for checking register or number
 * 
 */
#pragma once
#include "map"
#include "string"
#include "stdexcept"
#include "iostream"

struct DecodeMap
{ 
  DecodeMap()
  {
    FourOperationMap.emplace("ADD", "001");
    FourOperationMap.emplace("SUB", "010");
    FourOperationMap.emplace("MUL", "011");
    FourOperationMap.emplace("DIV", "100");
    FourOperationMap.emplace("STORE", "110");
    FourOperationMap.emplace("LOAD", "111");

    RegisterMap.emplace("r0", "000");
    RegisterMap.emplace("r1", "001");
    RegisterMap.emplace("r2", "010");
    RegisterMap.emplace("r3", "011");

    RegisterMap.emplace("r4", "100"); //ir
    RegisterMap.emplace("ir", "100"); //ir
                                      
    RegisterMap.emplace("r5", "101"); //sp
    RegisterMap.emplace("sp", "101"); //sp
                                      
    RegisterMap.emplace("r6", "110"); //lr
    RegisterMap.emplace("lr", "110"); //lr
                                      
    RegisterMap.emplace("r7", "111"); //pc
    RegisterMap.emplace("pc", "111"); //pc
  }

  std::map<std::string, std::string> FourOperationMap;
  std::map<std::string, std::string> RegisterMap;

  std::string Find(const std::string& Key)
  {
    auto op = FourOperationMap[Key];
    if (op == "")
    {
    }
    else
    {
      return op;
    }

    auto rs = RegisterMap[Key];
    if (rs == "")
    {
    }
    else
    {
      return rs;
    }

    return "";
  }
};


