/**
 * @file logcxx.cpp
 * $Id$
 * @brief	
 * @author My name SunWu
 * @date 2019-05-04
 */

#include <iostream>
#include <stdarg.h>
#include <log4cxx/logger.h>
#include <log4cxx/dailyrollingfileappender.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/helpers/dateformat.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/helpers/loglog.h>
#include <log4cxx/helpers/system.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <log4cxx/rollingfileappender.h>
#include <log4cxx/rolling/rollingfileappender.h>

#define MSGBUF_MAX 4096
log4cxx::LoggerPtr logger;
char message[MSGBUF_MAX];


void addConsoleLog()
{
	log4cxx::helpers::Pool p;
	log4cxx::PatternLayoutPtr cpl = new log4cxx::PatternLayout("\%d{\%y\%m\%d-\%H:\%M:\%S }%c %5p: %m%n");
	cpl->activateOptions(p);

	log4cxx::ConsoleAppenderPtr carp = new log4cxx::ConsoleAppender(cpl);
	carp->activateOptions(p);
	carp->setName("console");
	logger->addAppender(carp);
}

void removeConsoleLog()
{
	auto ap = logger->getAppender("console");
	if (ap) {
		logger->removeAppender(ap);
		ap->close();
	}
}

void addLocalFileLog(const std::string& file)
{
	log4cxx::helpers::Pool p;
	log4cxx::PatternLayoutPtr cpl = new log4cxx::PatternLayout("\%d{\%y\%m\%d-\%H:\%M:\%S }%c %5p: %m%n");
	cpl->activateOptions(p);

	//log4cxx::RollingFileAppenderPtr rfa( new log4cxx::RollingFileAppender());
	log4cxx::DailyRollingFileAppenderPtr rfa( new log4cxx::DailyRollingFileAppender());
	rfa->setName("localfile" +file);
	rfa->setLayout(cpl);
	rfa->setAppend(false);
	rfa->setFile(LOG4CXX_STR("./ivylog.log"));
	rfa->setDatePattern(LOG4CXX_STR("'.'yyyy-MM-dd-HH-mm"));

	rfa->activateOptions(p);

	logger->addAppender(rfa);
}

void removeLocalFileLog(const std::string& file)
{
	auto ap = logger->getAppender("localfile:"+file);
	if (ap) {
		logger->removeAppender(ap);
		ap->close();
	}

}


#define getMessage(msg,msglen,pat)	\
	do	\
{	\
	va_list ap;	\
	bzero(msg, msglen);	\
	va_start(ap, pat);		\
	vsnprintf(msg, msglen - 1, pat, ap);	\
	va_end(ap);	\
}while(false)

bool debug(const char * pattern, ...)
{

	getMessage(message,MSGBUF_MAX,pattern);

	logger->debug(message);
	return true;
}

int main()
{
	logger = log4cxx::Logger::getLogger("Ivy");
	logger->setLevel(log4cxx::Level::getDebug());
	addConsoleLog();
	addLocalFileLog("testlog");

	int i = 0;
	while(true) {
		debug("hello world: %d", ++i);
		sleep(10);
	}
	removeLocalFileLog("testlog");
	removeConsoleLog();
	return 0;
}

