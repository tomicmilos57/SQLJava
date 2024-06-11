#ifndef Database_h
#define Database_h
#include "Parser.h"
#include "Tokenizer.h"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

class Database {
private:
  std::vector<Table> tables;
  Tokenizer tokenizer;
  Parser parser;

public:
  Database() {}
  std::string execute(std::string strQuery);
  std::string printTable();
  std::string save_sql(std::string path);
  std::string save(std::string path);
  std::string load(std::string path);
  std::string tableNames();
};
#endif
