#include "remote_prepared_statement.h"

RemotePreparedStatement::RemotePreparedStatement(sql::Connection* connection, const char* sql)
{
	prepared_statement = connection->prepareStatement(sql);
}

Result* RemotePreparedStatement::executeQuery()
{
	sql::ResultSet* result = prepared_statement->executeQuery();
	return new RemoteResult(prepared_statement, result);
}

void RemotePreparedStatement::resetParametrs() {}

void RemotePreparedStatement::setBoolean(unsigned int parameterIndex, bool value)
{
	prepared_statement->setBoolean(parameterIndex, value);
}

void RemotePreparedStatement::setDateTime(unsigned int parameterIndex, const char* value)
{
	prepared_statement->setDateTime(parameterIndex, value);
}

void RemotePreparedStatement::setDouble(unsigned int parameterIndex, double value)
{
	prepared_statement->setDouble(parameterIndex, value);
}

void RemotePreparedStatement::setInt(unsigned int parameterIndex, int32_t value)
{
	prepared_statement->setInt(parameterIndex, value);
}

void RemotePreparedStatement::setUInt(unsigned int parameterIndex, uint32_t value)
{
	prepared_statement->setUInt(parameterIndex, value);
}

void RemotePreparedStatement::setInt64(unsigned int parameterIndex, int64_t value)
{
	prepared_statement->setInt64(parameterIndex, value);
}

void RemotePreparedStatement::setUInt64(unsigned int parameterIndex, uint64_t value)
{
	prepared_statement->setUInt64(parameterIndex, value);
}

void RemotePreparedStatement::setNull(unsigned int parameterIndex)
{
	prepared_statement->setNull(parameterIndex, NULL);
}

void RemotePreparedStatement::setString(unsigned int parameterIndex, const char* value)
{
	prepared_statement->setString(parameterIndex, value);
}