#pragma once

#include "connection.h"
#include "remote_prepared_statement.h"

#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/prepared_statement.h>

class RemoteConnection : public Connection
{
	sql::Driver* driver;
	sql::Connection* connection;

public:
	RemoteConnection(const char* host, const char* user, const char* password, const char* database);
	~RemoteConnection();

	virtual PreparedStatement* prepareStatement(const char* sql) override;
};