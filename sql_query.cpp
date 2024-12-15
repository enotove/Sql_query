
#include <iostream>
#include "Sql_query_builder.h"
#include <map>
#include <cassert>

int main()
{
    std::map<std::string, std::string> kv{ { "name", "John" }, {"id", "42"} };

    Sql_query_builder query_builder;
    query_builder.AddFrom("students");
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddWhere(kv);

    std::cout << query_builder.BuildQuery();
    /*if()
    query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");*/
}

