/**
 * @file	testtime.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-27
 */

#include <iostream>
#include <time.h>

int main()
{
	std::cout<<::timezone<<std::endl;
	time_t t = time(NULL); 
	tm *tp = localtime(&t); 
	
	// 北京时间
	printf("%d/%d/%d\n", tp->tm_mon+1, tp->tm_mday, tp->tm_year + 1900);  
	printf("%d:%d:%d\n", tp->tm_hour, tp->tm_min, tp->tm_sec); 

	time_t time_utc;
	struct tm tm_local, tm_gmt;
	time(&time_utc);
	localtime_r(&time_utc, &tm_local);

	printf("%d/%d/%d\n", tm_local.tm_mon+1, tm_local.tm_mday, tm_local.tm_year + 1900);  
	printf("%d:%d:%d\n", tm_local.tm_hour, tm_local.tm_min, tm_local.tm_sec); 

	time_t time_local = mktime(&tm_local);
	gmtime_r(&time_local, &tm_gmt);

	printf("%d/%d/%d\n", tm_local.tm_mon+1, tm_local.tm_mday, tm_local.tm_year + 1900);  
	printf("%d:%d:%d\n", tm_local.tm_hour, tm_local.tm_min, tm_local.tm_sec); 

	return 0;
}

