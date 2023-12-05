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

  void AddCommand(std::string InCommand)
  {
    Commands.push(InCommand);
  }

private:
  std::queue<std::string> Commands;
};

