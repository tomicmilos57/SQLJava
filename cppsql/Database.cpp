#include "Database.h"
std::string Database::execute(std::string strQuery) {
  Query *query;
  std::string ret;
  try {
    auto tokens = tokenizer.tokenize(strQuery);
    query = parser.parse(tokens);
    try {
      ret = query->execute(&tables);
    } catch (std::string e) { /*std::cout << e << std::endl;*/
      ret = e;
    } catch (const std::runtime_error &re) { /*std::cerr << "Runtime error: " <<
                                                re.what() << std::endl;*/
      ret = std::string("Runtime error: ") + re.what() + "\n";
    } catch (const std::exception &ex) { /*std::cerr << "Error occurred: " <<
                                            ex.what() << std::endl;*/
      ret = std::string("Error occurred: ") + ex.what() + "\n";
    } catch (...) { /*std::cout << "Unknown Exception Cought" << std::endl;*/
      ret = std::string("Unknown Exception Cought\n");
    }
    if (query != nullptr)
      delete query;
  } catch (std::string e) { /*std::cout << e << std::endl;*/
    ret = e;
  }
  return ret;
}
std::string Database::printTable() {
  std::string ret = "";
  // std::for_each(tables.begin(), tables.end(),
  //               [ret](auto t) mutable { ret += t.print_Table(); });
  for (auto &table : tables) {
    ret += table.print_Table();
  }
  return ret;
}
std::string Database::save_sql(std::string path) {
  std::ofstream os;
  os.open(path + ".sql");
  for (Table &table : tables) {
    table.save_sql(os);
  }
  os.close();
  return "Saved Successfully";
}
std::string Database::save(std::string path) {
  std::ofstream os;
  os.open(path + ".sqlpp");
  os << tables.size() << std::endl;
  for (Table &table : tables) {
    table.save(os);
  }
  os.close();
  return "Saved Successfully";
}
std::string Database::load(std::string path) {
  // std::cout << "Loading" << std::endl;
  std::ifstream os;
  os.open(path);
  if (!os) {
    return "Failed to open";
  }
  int num_of_tables;
  os >> num_of_tables;
  for (int i = 0; i < num_of_tables; i++) {
    tables.push_back(Table(os));
  }
  os.close();
  return "Loaded Successfully";
}
std::string Database::tableNames() {
  std::string ret = "";
  int i = 1;
  for (auto &table : tables) {
    ret += std::to_string(i++) + ". " + table.getName() + "\n";
  }
  return ret;
}