#include <iostream>
#include "sLogger.h"

int main()
{
	auto logger = new sLogger("sw");
	logger->addLocalFileLog("./swtest.log");
	logger->removeConsoleLog();


	logger->debug("hello world");
	delete(logger);
	return 0;
}

