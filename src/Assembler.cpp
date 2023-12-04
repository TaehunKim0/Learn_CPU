#include "Assembler.h"
#include "sstream"
#include "DecodeMap.h"
#include "bitset"
#include "MemoryArea.h"

Assembler::Assembler()
{


}

std::string Assembler::Decode(std::string InCommand, MemoryArea* InMemory)
{
  std::stringstream stream(InCommand);
  std::string s;
  std::string decodeCommand;
  bool bIndirectMode = false;

  DecodeMap DecodingMap;
  enum CommandOrder { Operation = 0, Storage, Operand1, Operand2};
  int order = 0;

  while(stream >> s)
  {
    s.erase(remove(s.begin(), s.end(), ','), s.end());
    std::cout << "Decode s : " << s << std::endl;
    std::string decodeString;

    if(s == "PUSH")
    {
      stream >> s;
      std::cout << "Decode s : " << s << std::endl;
      InMemory->AddCommand("ADD r1, " + s + ", 0");
      InMemory->AddCommand("STORE sp, 0x40");
      InMemory->AddCommand("STORE r1, [0x40]");
      InMemory->AddCommand("ADD sp, sp, 4");

      return "";
    }
    else if (s == "POP")
    {
      InMemory->AddCommand("ADD sp, sp, -4");

      return "";
    }

    switch(order)
    { 
      case Operation:
      {
        decodeString = DecodingMap.Find(s);
        break;
      }
      case Storage:
      {
        decodeString = DecodingMap.Find(s);
        break;
      }
      case Operand1:
      case Operand2:
      {
        decodeString = DecodingMap.Find(s);
        if(decodeString == "")
        {
          if(s.size() >= 2)
          {
            if(s.substr(0,2) == "0x")
            {
              s = InMemory->GetMemory(s);
            }
            else if(s.substr(0,3) == "[0x")
            {
              auto temp = InMemory->GetMemory(s);
              s = InMemory->GetMemory(temp);
              bIndirectMode = true;
            }
          }

          int num = std::stoi(s);
          std::bitset<4> bit(num);
          std::string bin = bit.to_string();
          bin.replace(0,1,"0");
          decodeString = bin;
        }
        else
        {
          decodeString = "1" + decodeString;
        }
        break;
      }
    }

    order++;

    decodeCommand += decodeString;
  }

  decodeCommand = (bIndirectMode ? "11" : "00") + decodeCommand;
  return decodeCommand;
}
