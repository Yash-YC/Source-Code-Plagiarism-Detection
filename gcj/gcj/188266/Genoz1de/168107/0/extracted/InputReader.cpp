// SAI [ 12 Sep 2009 ]
#include <fstream>
#include <stdlib.h>
#include "InputReader.h"
#include <cstring>
#include <iostream>

void ReadOneLine(std::ifstream& f, InputReader::EntryList& list);

InputReader::InputReader(std::string fileName)
{
  std::ifstream f;
  f.open(fileName.c_str());
  char buff[10000];

  uint32_t num = 0;

  while (!f.eof())
  {
    f.getline(buff, sizeof(buff));
    sscanf(buff, "%d", &num);
    for (uint32_t i = 0; i < num; i += 1)
    {
      ReadOneLine(f, list);
    }
    break;
  }
}

void 
ReadOneLine(std::ifstream& f, InputReader::EntryList& list)
{
  InputReader::Entry * entry = new InputReader::Entry();

  char buff[10000];
  f.getline(buff, sizeof(buff));
  char * ptr = strtok (buff, " ");
  uint32_t j = 0;
  while (ptr != NULL)
  {
    uint32_t base = atoi(ptr);
    entry->bases.push_back(base);
    ptr = strtok (NULL, " ");
  }

  list.push_back(entry);
}

InputReader::~InputReader()
{
  while (list.size() > 0)
  {
    InputReader::Entry * e = list.front();
    list.erase(list.begin());
    delete e;
  }
}

