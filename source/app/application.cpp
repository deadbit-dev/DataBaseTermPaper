#include "application.h"

void Application::run()
{
    connectToDatabase();
    loadData();
    sendData();
    close();
}

void Application::init(int argc, const char* argv[])
{
    // TODO: parse console arguments by flags
    // TODO: save data from arguments
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

void Application::connectToDatabase()
{
    // TODO: connect Database from local file or remote Server
    /*
        Local example:
            database = new DataBase("database.db");
        Remote example:
            database = new DataBase("localhost", "root", "password", "database");
    */
}

void Application::loadData()
{
    // TODO: load data from csv file
}

void Application::sendData()
{
    // TODO: proccess prepared statements with loaded data
    /*
        Example:
            PreparedStatement* prepared_statement = data_base->prepareStatement("SELECT * FROM users WHERE name = ?");
            preparedStatement->setString(1, "John");
            preparedStatement->executeQuery();
            delete prepared_statement;
    */
}

void Application::close()
{
    // TODO: clean resources
    /*
        Example:
            delete database;
    */
}