#pragma once

#include <string>
#include "DbConfig.hpp"

class DbConnection {
 public:
  virtual ~DbConnection(){};
  virtual void initialize(DbConfig& config) = 0;
  virtual int execute(std::string sqlQuery) = 0;
};
