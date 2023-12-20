#pragma once

#include <iostream>
#include <string>

class DbConfig {
public:
    virtual ~DbConfig(){}
};

struct Sqlite3Config : public DbConfig {
    std::string dbName;
    std::string dbPath;

    Sqlite3Config(std::string dbName = "test", 
                  std::string dbPath = "test.db") : 
                  
                  dbName(dbName), 
                  dbPath(dbPath) {}

    Sqlite3Config(DbConfig& config) {
        try {
            this->dbName = dynamic_cast<Sqlite3Config&>(config).dbName;
            this->dbPath = dynamic_cast<Sqlite3Config&>(config).dbPath;
        }
        catch (const std::bad_cast& error){
            std::cerr << error.what() << std::endl;
        }
    }

    Sqlite3Config(DbConfig&& config) {
        try {
            this->dbName = std::move(dynamic_cast<Sqlite3Config&>(config).dbName);
            this->dbPath = std::move(dynamic_cast<Sqlite3Config&>(config).dbPath);
        }
        catch (const std::bad_cast& error){
            std::cerr << error.what() << std::endl;
        }
    }
};

struct MySQLConfig : public DbConfig {
    std::string dbName;
    std::string hostName;
    unsigned short port;
    std::string userName;
    std::string password;

    MySQLConfig(std::string dbName = "test",
                std::string hostName = "127.0.0.1",
                unsigned short port = 3306,
                std::string userName = "root",
                std::string password = "") : 

                dbName(dbName), 
                hostName(hostName), 
                port(port), 
                userName(userName), 
                password(password) {}

    MySQLConfig(DbConfig& config) {
        try {
            this->dbName = dynamic_cast<MySQLConfig&>(config).dbName;
            this->hostName = dynamic_cast<MySQLConfig&>(config).hostName;
            this->port = dynamic_cast<MySQLConfig&>(config).port;
            this->userName = dynamic_cast<MySQLConfig&>(config).userName;
            this->password = dynamic_cast<MySQLConfig&>(config).password;
        }
        catch (const std::bad_cast& error){
            std::cerr << error.what() << std::endl;
        }
    }

    MySQLConfig(DbConfig&& config) {
        try {
            this->dbName = std::move(dynamic_cast<MySQLConfig&>(config).dbName);
            this->hostName = std::move(dynamic_cast<MySQLConfig&>(config).hostName);
            this->port = std::move(dynamic_cast<MySQLConfig&>(config).port);
            this->userName = std::move(dynamic_cast<MySQLConfig&>(config).userName);
            this->password = std::move(dynamic_cast<MySQLConfig&>(config).password);
        }
        catch (const std::bad_cast& error){
            std::cerr << error.what() << std::endl;
        }
    }
};

class DbConfigFactory {
public:
    virtual DbConfig* createDbConfig() = 0;
    virtual ~DbConfigFactory() {}
};

class Sqlite3ConfigFactory : public DbConfigFactory {
public:
    DbConfig* createDbConfig() override {
        return new Sqlite3Config();
    }
};

class MySQLConfigFactory : public DbConfigFactory {
public:
    DbConfig* createDbConfig() override {
        return new MySQLConfig();
    }
};