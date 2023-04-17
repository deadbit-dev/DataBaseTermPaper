#include "local_prepared_statement.h"

LocalPreparedStatement::LocalPreparedStatement(sqlite3* database, const char* sql)
{
	sqlite3_prepare_v2(database, sql, -1, &prepared_statement, nullptr);
}

void LocalPreparedStatement::executeQuery()
{
	sqlite3_step(prepared_statement);
	sqlite3_reset(prepared_statement);
}

void LocalPreparedStatement::setBoolean(unsigned int parameterIndex, bool value)
{
	sqlite3_bind_int(prepared_statement, parameterIndex, value);
}

void LocalPreparedStatement::setDateTime(unsigned int parameterIndex, const char* value)
{
	sqlite3_bind_text(prepared_statement, parameterIndex, value, -1, nullptr);
}

void LocalPreparedStatement::setDouble(unsigned int parameterIndex, double value)
{
	sqlite3_bind_double(prepared_statement, parameterIndex, value);
}

void LocalPreparedStatement::setInt(unsigned int parameterIndex, int32_t value)
{
	sqlite3_bind_int(prepared_statement, parameterIndex, value);
}

void LocalPreparedStatement::setUInt(unsigned int parameterIndex, uint32_t value)
{
	sqlite3_bind_int64(prepared_statement, parameterIndex, value);
}

void LocalPreparedStatement::setInt64(unsigned int parameterIndex, int64_t value)
{
	sqlite3_bind_int64(prepared_statement, parameterIndex, value);
}

void LocalPreparedStatement::setUInt64(unsigned int parameterIndex, uint64_t value)
{
	sqlite3_bind_int64(prepared_statement, parameterIndex, value);
}

void LocalPreparedStatement::setNull(unsigned int parameterIndex)
{
	sqlite3_bind_null(prepared_statement, parameterIndex);
}

void LocalPreparedStatement::setString(unsigned int parameterIndex, const char* value)
{
	sqlite3_bind_text(prepared_statement, parameterIndex, value, -1, nullptr);
}