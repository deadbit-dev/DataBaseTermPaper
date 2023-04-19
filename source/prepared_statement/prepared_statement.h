#pragma once

#include "result.h"

#include <stdint.h>

struct PreparedStatement
{
public:
	virtual Result* executeQuery() = 0;
	virtual void resetParametrs() = 0;
	virtual void setBoolean(unsigned int parameterIndex, bool value) = 0;
	virtual void setDateTime(unsigned int parameterIndex, const char* value) = 0;
	virtual void setDouble(unsigned int parameterIndex, double value) = 0;
	virtual void setInt(unsigned int parameterIndex, int32_t value) = 0;
	virtual void setUInt(unsigned int parameterIndex, uint32_t value) = 0;
	virtual void setInt64(unsigned int parameterIndex, int64_t value) = 0;
	virtual void setUInt64(unsigned int parameterIndex, uint64_t value) = 0;
	virtual void setNull(unsigned int parameterIndex) = 0;
	virtual void setString(unsigned int parameterIndex, const char* value) = 0;
};