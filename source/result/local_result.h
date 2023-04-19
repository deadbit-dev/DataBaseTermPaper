#pragma once

#include "result.h"
#include <sqlite3.h>

class LocalResult : public Result
{
	sqlite3_stmt* prepared_statement;

public:
	LocalResult(sqlite3_stmt* prepared_statement);

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