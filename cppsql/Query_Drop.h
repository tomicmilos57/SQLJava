#ifndef Query_Drop_h
#define Query_Drop_h

#include "Query.h"
#include <algorithm>
#include <iostream> //delete later
#include <regex>
#include <string>
#include <vector>

class Query_Drop : public Query {
private:
  std::string tableName;

public:
  Query_Drop(std::vector<std::string> tokens);
  std::string execute(std::vector<Table> *tables);
};
#endif
