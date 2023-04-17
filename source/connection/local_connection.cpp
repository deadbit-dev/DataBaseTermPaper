#include "local_connection.h"

LocalConnection::LocalConnection(const char* fileName)
{
	sqlite3_open(fileName, &dataBase);
}

LocalConnection::~LocalConnection()
{
	delete dataBase;
}

PreparedStatement* LocalConnection::prepareStatement(const char* sql)
{
	return new LocalPreparedStatement(dataBase, sql);
}