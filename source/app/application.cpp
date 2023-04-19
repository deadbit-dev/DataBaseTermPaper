#include "application.h"

void Application::run(int argc, const char* argv[])
{
    parseArguments(argc, argv);
    loadData();
    connectToDatabase();
    sendData();
    cleanup();
}

void Application::parseArguments(int argc, const char* argv[])
{
    // TODO: parse console arguments by flags
    // TODO: save data from arguments in class fields
    /*
        Arguments:
            --data path_to_data.csv         [REQUARED]
            -l (--local) or -r (--remote)   [REQUARED]
            -h (--host) host                [REQUARED FOR REMOTE]
            -u (--user) user                [REQUARED FOR REMOTE]
            -p (--password) password        [REQUARED FOR REMOTE]
            -d (--database) database        [REQUARED FOR LOCAL AND REMOTE]
    */
}

void Application::loadData()
{
    // TODO: load data from csv file
}

void Application::connectToDatabase()
{
    // TODO: connect Database from local file or remote Server
    // database = new DataBase("localhost", "root", "password", "database"); // REMOTE
    database = new DataBase("database.db"); // LOCAL
}

void Application::sendData()
{
    // TODO: proccess prepared statements with loaded data
    // Example

    PreparedStatement* prepared_statement = database->prepareStatement("SELECT * FROM order WHERE ? = ?");
    prepared_statement->setString(1, "cost");
    prepared_statement->setInt(2, 32);
            
    Result* result = prepared_statement->executeQuery();
            
    for(int i = 0; i < result->getColumnCount(); i++)
    {
        SQL_TYPES type = result->getColumnType(i);
        switch(type)
        {
            case TYPE_INTEGER:
                cout << result->getInt(i) << endl;
            break;
            case TYPE_FLOAT:
                cout << result->getDouble(i) << endl;
            break;
            case TYPE_TEXT:
                cout << result->getString(i) << endl;
            break;
            case TYPE_NULL:
                cout << "NULL" << endl;
            break;
        }
    }
            
    prepared_statement->resetParametrs();
            
    delete prepared_statement;
}

void Application::cleanup()
{
    delete database;
}