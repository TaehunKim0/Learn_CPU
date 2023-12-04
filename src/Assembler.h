/*
* Decoding command in control unit (ASM)
*/
#pragma once
#include "DecodeMap.h"
#include "string"

class Assembler 
{
public:
  Assembler();

public:
  std::string Decode(std::string InCommand, class MemoryArea* InMemory);

private:
  DecodeMap DecodingMap;
};
