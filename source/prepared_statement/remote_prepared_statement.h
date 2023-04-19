#pragma once

#include "prepared_statement.h"
#include "remote_result.h"

#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/prepared_statement.h>

class RemotePreparedStatement : public PreparedStatement
{
	sql::PreparedStatement* prepared_statement;

public:
	RemotePreparedStatement(sql::Connection* connection, const char* sql);
	
	virtual Result* executeQuery() override;
	virtual void resetParametrs() override;
	virtual void setBoolean(unsigned int parameterIndex, bool value) override;
	virtual void setDateTime(unsigned int parameterIndex, const char* value) override;
	virtual void setDouble(unsigned int parameterIndex, double value) override;
	virtual void setInt(unsigned int parameterIndex, int32_t value) override;
	virtual void setUInt(unsigned int parameterIndex, uint32_t value) override;
	virtual void setInt64(unsigned int parameterIndex, int64_t value) override;
	virtual void setUInt64(unsigned int parameterIndex, uint64_t value) override;
	virtual void setNull(unsigned int parameterIndex) override;
	virtual void setString(unsigned int parameterIndex, const char* value) override;
};