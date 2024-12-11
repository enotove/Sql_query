#include "Sql_query_builder.h"
#include "map"

Sql_query_builder& Sql_query_builder::AddFrom(std::string from)
{
	query.from = from;
	return *this;
}

Sql_query_builder& Sql_query_builder::AddWhere(std::string name, std::string value)
{
	query.wheres[name] = value;
	return *this;
}

Sql_query_builder& Sql_query_builder::AddColumn(std::string column)
{
	query.columns.push_back(column);
	return *this;
}

std::string Sql_query_builder::BuildQuery()
{
	if (query.from.empty())
	{
		throw std::exception("Query haven't named table");
		
	}
	std::string result = "SELECT ";
	if (query.columns.empty())
	{
		result += "* ";
	}
	else
	{
		for (unsigned i{}; i < query.columns.size(); i++)
		{
			result += query.columns[i];
			if (i != (query.columns.size() - 1))
			{
				result += ", ";
			}
			else
			{
				result += " ";
			}
		}
	}
	result += "FROM " + query.from;
	if (!query.wheres.empty())
	{
		result += " WHERE ";
		for (auto i{ query.wheres.begin() }; ;)
		{
			result += i->first + "=" + i->second;
			if ((++i) != query.wheres.end())
			{
				result += " AND ";
			}
			else
			{
				break;
			}
		}
	}
	
	return result;
}
