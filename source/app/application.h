#pragma once

#include "../data_base/data_base.h"

class Application {
public:
	void init(int argc, const char* argv[]);
	void run();

private:
	void connectToDatabase();
	void loadData();
	void sendData();
	void close();

private:
	DataBase* database;
};