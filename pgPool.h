#ifndef PGPOOL_H
#define PGPOOL_H

#include <mutex>
#include <pqxx/pqxx>
#include <memory>
#include <condition_variable>
#include <queue>

class PGPool
{
public:
  PGPool();
  std::shared_ptr<pqxx::lazyconnection> connection();
  void freeConnection(std::shared_ptr<pqxx::lazyconnection>);

private:
  void createPool();
  
  std::mutex m_mutex;
  std::condition_variable m_condition;
  std::queue<std::shared_ptr<pqxx::lazyconnection>> m_pool;

  const int POOL_SIZE = 10;
};

#endif
