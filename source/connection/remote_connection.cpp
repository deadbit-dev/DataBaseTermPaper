#include "remote_connection.h"

RemoteConnection::RemoteConnection(const char* host, const char* user, const char* password, const char* database)
{
    driver = get_driver_instance();
    connection = driver->connect(host, user, password);
    connection->setSchema(database);
}

RemoteConnection::~RemoteConnection()
{
    delete connection;
}

PreparedStatement* RemoteConnection::prepareStatement(const char* sql)
{
    return new RemotePreparedStatement(connection, sql);
}