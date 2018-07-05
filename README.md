# pqxx_pool

This project works on top of great work by borisovs (https://github.com/borisovs/pool) which directly use libpq's API via `libpq-fe.h` but
now this project call APIs through [libpqxx](https://github.com/jtv/libpqxx).

# Tehnical

The implementation focuses on having connection pool which its number of available connection is set via `POOL_SIZE` in `PGPool.h` file. In `main.cpp`, it simulates creating a new 10 threads holding of each available connection from the pool to execute DB related task. Ideally, the concurrency model at this point is up to your app implementation. See more detail for possible ways at http://pqxx.org/development/libpqxx/wiki/Threading .

# What to do?

Create a database namely `demo` first by log in to your postgres console, and execute `create database demo`.
Then execute SQL statements from provided file (pool.sql) to insert necessary tables into such database as follows

`psql -U postgres demo < pool.sql`

Then compile, link and make executable file via the following

`make`

It will produce an executable called `pool` at the same directory.

Finally run with

`PGDATABASE=demo PGUSER=postgres PGPASSWORD="...your password if any..." ./pool`

# License

MIT, Abzi.co
