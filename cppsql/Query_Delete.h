#ifndef Query_Delete_h
#define Query_Delete_h

#include "Query.h"
#include <algorithm>
#include <iostream> //delete later
#include <regex>
#include <string>
#include <vector>

class Query_Delete : public Query {
private:
  std::string tableName;
  Where where;

public:
  Query_Delete(std::vector<std::string> tokens);
  std::string execute(std::vector<Table> *tables);
};
#endif
