#pragma once

#include "DbConfig.hpp"
#include "DbConnection.hpp"
#include "Sqlite3Connection.hpp"
#include "MySQLConnection.hpp"

class DbConnectionFactory
{
public:
    virtual DbConnection *createConnection(DbConfig &config) = 0;
};

class Sqlite3ConnectionFactory : public DbConnectionFactory {
public:
  DbConnection *createConnection(DbConfig& config) override {
    return new Sqlite3Connection(config);
  }
};

class MySQLConnectionFactory : public DbConnectionFactory {
 public:
  DbConnection *createConnection(DbConfig& config) override {
    return new MySQLConnection(config);
  }
};