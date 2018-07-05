pool: pgPool.cpp pgPool.h main.cpp
	g++ -std=c++11 -o pool main.cpp pgPool.cpp -lpqxx -lpq -lpthread

