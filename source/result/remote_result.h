#pragma once

#include "result.h"

#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/prepared_statement.h>

class RemoteResult : public Result
{
	sql::PreparedStatement* prepared_statement;
	sql::ResultSet* result_set;

public:
	RemoteResult(sql::PreparedStatement* prepared_statement, sql::ResultSet * result);

	virtual SQL_TYPES getColumnType(uint32_t columnIndex) override;
	virtual uint32_t getColumnCount() override;
	virtual bool getBoolean(uint32_t columnIndex) override;
	virtual long double getDouble(uint32_t columnIndex) override;
	virtual int32_t getInt(uint32_t columnIndex) override;
	virtual uint32_t getUInt(uint32_t columnIndex) override;
	virtual int64_t getInt64(uint32_t columnIndex) override;
	virtual uint64_t getUInt64(uint32_t columnIndex) override;
	virtual const char* getString(uint32_t columnIndex) override;
};