#pragma once

#include "DbConfig.hpp"
#include "DbConnection.hpp"

class Sqlite3Connection : public DbConnection {
public:
    Sqlite3Connection(DbConfig& config){
        this->initialize(config);
    }

  void initialize(DbConfig& config) override {
    try {
        _config = dynamic_cast<Sqlite3Config&>(config);
    }
    catch(const std::bad_cast error){
        std::cerr << error.what() << std::endl;
    }
    std::cout << "Sqlite3Connection initialized" << std::endl;
  }

  int execute(std::string sqlQuery){
    std::cout << "executig with sqlite3" << std::endl;
    std::cout << "executing " << sqlQuery << std::endl;
    // execution instructions here
    std::cout << sqlQuery << " executed" << std::endl;
    return 0;
  }
  private:
    Sqlite3Config _config;
};