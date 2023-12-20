#pragma once

#include "DbConfig.hpp"
#include "DbConnection.hpp"

class MySQLConnection : public DbConnection
{
public:
    MySQLConnection(DbConfig &config)
    {
        this->initialize(config);
    }

    void initialize(DbConfig &config) override
    {
        try
        {
            _config = dynamic_cast<MySQLConfig &>(config);
        }
        catch (const std::bad_cast error)
        {
            std::cerr << error.what() << std::endl;
        }
        std::cout << "MySQLConnection initialized" << std::endl;
    }

    int execute(std::string sqlQuery)
    {
        std::cout << "executig with mysql" << std::endl;
        std::cout << "executing " << sqlQuery << std::endl;
        // execution instructions here
        std::cout << sqlQuery << " executed" << std::endl;
        return 0;
    }

private:
    MySQLConfig _config;
};