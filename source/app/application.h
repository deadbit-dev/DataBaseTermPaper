#pragma once

#include "../data_base/data_base.h"

class Application {
public:
	void run(int argc, const char* argv[]);

private:
	void init(int argc, const char* argv[]);
	void loadData();
	void connectToDatabase();
	void sendData();
	void close();

private:
	DataBase* database;
};