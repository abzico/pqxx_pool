#include "pgPool.h"
#include <iostream>
#include <thread>
#include <pqxx/pqxx>

void testConnection(std::shared_ptr<PGPool> pgPool, size_t id)
{
  auto conn = pgPool->connection();

  try {
    // create a transaction from a connection
    pqxx::work W(reinterpret_cast<pqxx::lazyconnection&>(*conn.get()));
    pqxx::result R = W.exec("SELECT max(id) FROM demo;");
    for (auto row: R) {
      std::cout << row[0] << std::endl;
    }
    std::cout << "ID: " << id << std::endl;
    W.commit();
    
    // free connection when things done
    pgPool->freeConnection(conn);
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    // free connection when error kicks in
    pgPool->freeConnection(conn);
  }
}

int main(int argc, char const *argv[])
{
  auto pgPool = std::make_shared<PGPool>();
  std::vector<std::shared_ptr<std::thread>> vec;

  // number of thread here should be number of thread available in your thread pool waiting for incoming job to execute
  // imagine X threads are waiting to execute task
  for (size_t i = 0; i<10; i++) {
    vec.push_back(std::make_shared<std::thread>(std::thread(testConnection, pgPool, i)));
  }

  for (auto &i : vec) {
    i.get()->join();
  }

  return 0;
}
