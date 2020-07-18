/**
 * @file testfunction.cpp
 * @brief	
 * @author My name SunWu
 * @version 
 * @date 2019-09-13
 */

#include <functional>
#include <iostream>
#include <time.h>
#include <stdio.h>

std::vector<int> vec = {10, 5};

void testfun(std::function<void(int)> func) {
	for (auto& it : vec){
		func(it);
	}
}

int main()
{
	/*
	testfun([](int i){ std::cout<<i<<std::endl; });

	*/
	//std::cout<<timezone<<std::endl;
	tzset();
	//daylight,timezone和tzname。
	std::cout<<"daylight:"<<daylight<<std::endl;
	std::cout<<"timezone:"<<timezone<<std::endl;
	std::cout<<"tzname:"<<tzname[0]<<std::endl;
	std::cout<<"tzname:"<<tzname[1]<<std::endl;

	time_t time_utc;
	struct tm tm_local;

	//Get the UTC time
	time(&time_utc);

	//Get the local time
	//Use localtime_r for threads safe
	localtime_r(&time_utc, &tm_local);

	//time_t time_local;
	struct tm tm_gmt;

	//Change tm to time_t 
	//time_local = mktime(&tm_local);

	//Change it to GMT tm
	gmtime_r(&time_utc, &tm_gmt);

	int time_zone = tm_local.tm_hour - tm_gmt.tm_hour;
	if (time_zone < -12) {
		time_zone += 24; 
	} else if (time_zone > 12) {
		time_zone -= 24;
	}

	char cur_time[256];
	strftime (cur_time,256, " %B %A %Y年%m月%d日  %H时%M分%S秒   %c  %x %X", &tm_local);
	printf("LOCAL TIME  :%s\n", cur_time);

	strftime(cur_time,256, " %B %A %Y年%m月%d日  %H时%M分%S秒   %c  %x %X", &tm_gmt);
	printf("GMT TIME    :%s\n", cur_time);

	printf("Your time zone is +%d. (- is west, + is east)\n", time_zone);
}
