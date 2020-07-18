/**
 * @file	testvec2.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-05-07
 */

#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUM 8	//MAX_NUM修改为8，其余地方不做任何修改

int main(){
	vector<int> vecInt;

	for(int i = 0; i != MAX_NUM; i++){
		vecInt.push_back(i);
	}

	vector<int>::iterator iter = vecInt.begin();
	cout << "the 1st element: " << *iter << endl;

	vecInt.push_back(123);

	while(iter != vecInt.end()){
		cout << *iter << " ";
		iter++;
	}

	return 0;
}
