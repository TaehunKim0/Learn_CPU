#include "CPU.h"
#include "Assembler.h"
#include "MemoryArea.h"
#include "fstream"

CPU::CPU()
{


}

void CPU::Cycle()
{
  if(!Run())
    bIsActive = false;
}

bool CPU::Init(MemoryArea* InMemory)
{
  std::ofstream file("resource/source.mac", std::ios::trunc);
  if(file.is_open())
  {
    file.close();
  }

  if (InMemory)
      Memory = InMemory;
  else
      return false;

  return true;
}

bool CPU::Run()
{
  if(!Fetch())
    return false;

  if(!Decode())
    return false;

  if(!Execute())
    return false;

  return true;
}

bool CPU::Fetch()
{
  Pc = Memory->GetCommand();
  std::cout << "Fetch Result : " << Pc << std::endl;

  if(Pc == "")
  {
    return false;
  }

  return true;
}

bool CPU::Decode()
{
  std::string result = Decoder.Decode(Pc, Memory);
  std::cout << "Decode Result : " << result << std::endl;

  std::ofstream file("resource/source.mac", std::ios::app);
  if(file.is_open())
  {
    if(result != "")
      file << result << std::endl;
  }
  else 
  {
    std::cout << "Cannot Open File : resource/source.mac" << std::endl;
    return false;
  }

  return true;
}

bool CPU::Execute()
{

  return true;
}
