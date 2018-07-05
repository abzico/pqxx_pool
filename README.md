# pqxx_pool

This project works on top of great work by borisovs (https://github.com/borisovs/pool) which directly use libpq's API via `libpq-fe.h` but
now this project call APIs through [libpqxx](https://github.com/jtv/libpqxx).

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
