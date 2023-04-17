#pragma once

#include "connection.h"
#include "local_connection.h"
#include "remote_connection.h"

using namespace std;

class DataBase {
    Connection* connection;

public:
    DataBase(const char* database);
    DataBase(const char* host, const char* user, const char* password, const char* database);
    ~DataBase();

    PreparedStatement* prepareStatement(const char* sql);
};