#include "local_result.h"

LocalResult::LocalResult(sqlite3_stmt* ps)
{
	prepared_statement = ps;
}

SQL_TYPES LocalResult::getColumnType(uint32_t columnIndex)
{
	// TODO: convert to supported SQL_TYPES
	return (SQL_TYPES) sqlite3_column_type(prepared_statement, columnIndex);
}

uint32_t LocalResult::getColumnCount()
{
	return sqlite3_column_count(prepared_statement);
}

bool LocalResult::getBoolean(uint32_t columnIndex)
{
	return sqlite3_column_int(prepared_statement, columnIndex);
}

long double LocalResult::getDouble(uint32_t columnIndex)
{
	return sqlite3_column_double(prepared_statement, columnIndex);
}

int32_t LocalResult::getInt(uint32_t columnIndex)
{
	return sqlite3_column_int(prepared_statement, columnIndex);
}

uint32_t LocalResult::getUInt(uint32_t columnIndex)
{
	return sqlite3_column_int64(prepared_statement, columnIndex);
}

int64_t LocalResult::getInt64(uint32_t columnIndex)
{
	return sqlite3_column_int64(prepared_statement, columnIndex);
}

uint64_t LocalResult::getUInt64(uint32_t columnIndex)
{
	return sqlite3_column_int64(prepared_statement, columnIndex);
}

const char* LocalResult::getString(uint32_t columnIndex)
{
	return (const char*) sqlite3_column_text(prepared_statement, columnIndex);
}