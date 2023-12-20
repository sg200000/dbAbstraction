#include <iostream>
#include <string>
#include "DbConfig.hpp"
#include "DbConnection.hpp"
#include "DbConnectionFactory.hpp"

void ClientCode(DbConnectionFactory& connectionFactory, DbConfigFactory& configFactory) {
    DbConfig* config = configFactory.createDbConfig();
    DbConnection *connection = connectionFactory.createConnection(*config);
    connection->execute("SELECT * FROM test");
    delete connection;
    delete config;
}

int main() {
  std::cout << "Client: Testing client code with the sqlite3:\n";
  DbConnectionFactory* connectionFactory = new Sqlite3ConnectionFactory();
  DbConfigFactory* configFactory = new Sqlite3ConfigFactory();
  ClientCode(*connectionFactory, *configFactory);
  delete configFactory,connectionFactory;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with mysql:\n";
  connectionFactory = new MySQLConnectionFactory();
  configFactory = new MySQLConfigFactory();
  ClientCode(*connectionFactory, *configFactory);
  delete configFactory,connectionFactory;
  return 0;
}