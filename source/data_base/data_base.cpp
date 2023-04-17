#include "data_base.h"

DataBase::DataBase(const char* database)
{
    connection = new LocalConnection(database);
}

DataBase::DataBase(const char* host, const char* user, const char* password, const char* database)
{
    connection = new RemoteConnection(host, user, password, database);
}

DataBase::~DataBase()
{
    delete connection;
}

PreparedStatement* DataBase::prepareStatement(const char* sql)
{
    return connection->prepareStatement(sql);
}