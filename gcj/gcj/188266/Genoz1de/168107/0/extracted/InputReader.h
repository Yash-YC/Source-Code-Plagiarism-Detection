// SAI [ 12 Sep 2009 ]

#ifndef __SAIINPUTREADER__
#define __SAIINPUTREADER__

#include <string>
#include <vector>

class InputReader
{
public:
  typedef std::vector<uint32_t>           BaseList;
  typedef std::vector<uint32_t>::iterator BaseListIterator;

  typedef struct
  {
    BaseList bases;
  }Entry;

  typedef std::vector<Entry*>           EntryList;
  typedef std::vector<Entry*>::iterator EntryListIterator;

public:
  EntryList list;

public:
  InputReader(std::string fileName);
  ~InputReader();
};

#endif
