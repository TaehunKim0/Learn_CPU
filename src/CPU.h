/*
 * CPU [Risk]
 * Fetch -> Decode -> Execution
 * n command -> n + 2 clock
 * 
 * 1. Fetch command from code area memory
 *    Can fetch through bus interface
 * 2. Decoding command in control unit (ASM)
 * 3. Execute operation command in ALU
 */
#pragma once
#include "Assembler.h"
#include "string"

class CPU
{
public:
  CPU();

public:
  void Cycle();
  bool Init(class MemoryArea* InMemory);
  void Release();

  operator bool() const{
    return bIsActive;
  }

private:
  bool Run();

  bool Fetch();
  bool Decode();
  bool Execute();

private:
  Assembler Decoder;
  class MemoryArea* Memory;

  std::string Pc;
  bool bIsActive = true;
};
