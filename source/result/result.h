#pragma once

#include "sqltypes.h"

#include <stdint.h>

struct Result
{
public:
	virtual SQL_TYPES getColumnType(uint32_t columnIndex) = 0;
	virtual uint32_t getColumnCount() = 0;
	virtual bool getBoolean(uint32_t columnIndex) = 0;
	virtual long double getDouble(uint32_t columnIndex) = 0;
	virtual int32_t getInt(uint32_t columnIndex) = 0;
	virtual uint32_t getUInt(uint32_t columnIndex) = 0;
	virtual int64_t getInt64(uint32_t columnIndex) = 0;
	virtual uint64_t getUInt64(uint32_t columnIndex) = 0;
	virtual const char* getString(uint32_t columnIndex)  = 0;
};