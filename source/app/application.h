#pragma once

#include "data_base.h"
#include "sqltypes.h"

class Application {
public:
	void run(int argc, const char* argv[]);

private:
	void parseArguments(int argc, const char* argv[]);
	void loadData();
	void connectToDatabase();
	void sendData();
	void cleanup();

private:
	DataBase* database;
};