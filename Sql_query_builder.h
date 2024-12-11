#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
struct Query
{
	std::string from;
	std::map<std::string, std::string> wheres;
	std::vector<std::string> columns;
};
class Sql_query_builder
{
private:
	Query query;
public:
	Sql_query_builder() = default;
	
	Sql_query_builder& AddFrom(std::string from);
	Sql_query_builder& AddWhere(std::string name, std::string value);
	Sql_query_builder& AddColumn(std::string column);

	std::string BuildQuery();

};
