#pragma once

#include "connection.h"
#include "local_prepared_statement.h"

#include <sqlite3.h>

class LocalConnection : public Connection
{
	sqlite3* dataBase;

public:
	LocalConnection(const char* fileName);
	~LocalConnection();

	virtual PreparedStatement* prepareStatement(const char* sql) override;
};