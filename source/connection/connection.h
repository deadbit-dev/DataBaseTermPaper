#pragma once

#include "prepared_statement.h"

struct Connection
{
public:
	virtual PreparedStatement* prepareStatement(const char* sql) = 0;
};