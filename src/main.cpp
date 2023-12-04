#include "iostream"
#include "CPU.h"
#include "MemoryArea.h"

int main(int argc, char * argv [])
{
  MemoryArea CodeMemory;
  if(!CodeMemory.AddCommandsFromFile(argv[1]))
    return 0;

  CPU Cpu;
  Cpu.Init(&CodeMemory);

  while(Cpu)
    Cpu.Cycle();

  return 0;
}
