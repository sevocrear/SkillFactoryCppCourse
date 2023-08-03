#include <iostream>
#include <tao/pq.hpp>

int main()
{
   // open a connection to the database
   const auto conn = tao::pq::connection::create("dbname=testdb user=postgres password=qwerty3215 host=localhost port=5432");

   // execute statements
   conn->execute( "DROP TABLE IF EXISTS users" );
   conn->execute( "CREATE TABLE users ( name TEXT PRIMARY KEY, age INTEGER NOT NULL )" );

   // prepare statements
   conn->prepare( "insert_user", "INSERT INTO users ( name, age ) VALUES ( $1, $2 )" );

   {
      // begin transaction
      const auto tr = conn->transaction();

      // execute previously prepared statements
      tr->execute( "insert_user", "Daniel", 42 );
      tr->execute( "insert_user", "Tom", 41 );
      tr->execute( "insert_user", "Jerry", 29 );

      // commit transaction
      tr->commit();
   }

   // query data
   const auto users = conn->execute( "SELECT name, age FROM users WHERE age >= $1", 40 );

   // iterate and convert results
   for( const auto& row : users ) {
      std::cout << row[ "name" ].as< std::string >() << " is "
                << row[ "age" ].as< unsigned >() << " years old.\n";
   }
}