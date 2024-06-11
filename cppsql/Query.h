#ifndef Query_h
#define Query_h

#include "Table.h"
#include <string>
#include <vector>
class Query {
protected:
  std::vector<std::string> tokens;

public:
  Query(std::vector<std::string> tokens) : tokens(tokens) {}
  std::string virtual execute(std::vector<Table> *tables) { return ""; }

protected:
  void read_columns(int &i, std::string lastToken,
                    std::vector<std::string> &columns, bool last, bool byValue);
  std::string lower(std::string str);
};
#endif
