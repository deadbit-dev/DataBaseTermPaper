#include "remote_result.h"

RemoteResult::RemoteResult(sql::PreparedStatement* statement, sql::ResultSet* result)
{
	prepared_statement = statement;
	result_set = result;
}

SQL_TYPES RemoteResult::getColumnType(uint32_t columnIndex)
{
	// TODO: convert to supported SQL_TYPES
	return (SQL_TYPES) prepared_statement->getMetaData()->getColumnType(columnIndex);
}

uint32_t RemoteResult::getColumnCount()
{
	return prepared_statement->getMetaData()->getColumnCount();
}

bool RemoteResult::getBoolean(uint32_t columnIndex)
{
	return result_set->getBoolean(columnIndex);
}

long double RemoteResult::getDouble(uint32_t columnIndex)
{
	return result_set->getDouble(columnIndex);
}

int32_t RemoteResult::getInt(uint32_t columnIndex)
{
	return result_set->getInt(columnIndex);
}

uint32_t RemoteResult::getUInt(uint32_t columnIndex)
{
	return result_set->getUInt(columnIndex);
}

int64_t RemoteResult::getInt64(uint32_t columnIndex)
{
	return result_set->getInt64(columnIndex);
}

uint64_t RemoteResult::getUInt64(uint32_t columnIndex)
{
	return result_set->getUInt64(columnIndex);
}

const char* RemoteResult::getString(uint32_t columnIndex)
{
	return result_set->getString(columnIndex).c_str();
}