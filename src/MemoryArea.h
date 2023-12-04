/*
 *
 *
 *
 */
#pragma once
#include "string"
#include "iostream"
#include "fstream"
#include "queue"
#include "string"
#include "map"

class MemoryArea
{
public:
  MemoryArea()
  {
    MainMemory.emplace("0x11", "3");
    MainMemory.emplace("[0x11]", "0x70");
    MainMemory.emplace("0x70", "5");

    MainMemory.emplace("0x40", "4");
    MainMemory.emplace("[0x40]", "0x80");
    MainMemory.emplace("0x80", "6");
  }

  bool AddCommandsFromFile(std::string InFileName)
  {
    std::string FilePath = "resource/";
    std::ifstream in(FilePath + InFileName);
    std::string s;

    if(!in.is_open())
    {
      std::cout << "Can Find File : " << FilePath + InFileName << std::endl;
      return false;
    }

    std::string buff;
    while(in)
    {
      std::getline(in, buff);
      if(buff != "")
        Commands.push(buff);
      // std::cout << buff << std::endl;
    }

    return true;
  }

  std::string GetCommand()
  {
    std::string command = "";
    if(Commands.size())
    {
      command = Commands.front();
      Commands.pop();
    }

    return command;
  }

  std::string GetMemory(std::string Key)
  {
    return MainMemory[Key];
  }

  void AddCommand(std::string InCommand)
  {
    Commands.push(InCommand);
  }

private:
  std::queue<std::string> Commands;
  std::map<std::string, std::string> MainMemory;
};

