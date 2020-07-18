/**
 * @file	dpmath.cpp
 * @brief	
 * @author	My name is SunWu
 * @version $Id$
 * @date	2020-04-16
 */

#include <iostream>  
#include <string.h>  
using namespace std;  

/***   
 * c[i][w]表示背包容量为w时，i个物品导致的最优解的总价值，大小为(n+1)*(w+1)   
 * v[i]表示第i个物品的价值，大小为n   
 * w[i]表示第i个物品的重量，大小为n   
 * ***/    

//n 总的物品数量  
//w 总的可容纳重量
//v 单个物品的价值
//weight 对应物品的重量
//c[i][j]  用来存储一个物品对应值 i表示物品数量  j表示价值
void DP(int n, int W, int c[][18], int *v, int *weight)  
{  
	memset(*c, 0, (W+1)*sizeof(int));  
	for (int i = 1; i <= n; i++)   //遍历n个物品数量
	{  
		c[i][0] = 0;  
		for (int w = 1; w <= W; w++)   //从1 遍历 只要没有超过总重量
		{  
			//3 > 1 2 
			if (weight[i-1] > w)    //此处比较是关键   //如果当前物品的重量大于当前的背包重量 直接用跟之前的最优解
			{  
				//物品idx			前一个物品idx  重量
				//c[1][1,2] = c[0][1,2]
				c[i][w] = c[i-1][w];  
			}  
			else   //如果当前物品可放入背包中了
			{  
				int temp = c[i-1][w-weight[i-1]] + v[i-1];//注意weight和v数组中的第i个应该为weight[i-1]和v[i-1]  
				if (c[i-1][w] > temp)  
				{  
					c[i][w] = c[i-1][w]; //
				}  
				else   
					c[i][w] = temp;  
			}  
		}  
	}  
}   

void findPath(int c[][18], int *x, int *weight, int n, int W)  
{     
	int w = W;  
	for (int i = n; i >= 2; i--)  //
	{  
		if (c[i][w] == c[i-1][w])  
		{  
			x[i-1] = 0;  
		}  
		else  
		{  
			x[i-1] = 1;  
			w = w - weight[i-1];  
		}  
	}  
	if (c[1][w] == 0)  
		x[0] = 0;  
	else  
		x[0] = 1;  
}  

int main()  
{  
	int n = 5;  
	int W = 17;  
	int w[] = {3, 4, 7, 8, 9};  
	int v[] = {4, 5, 10, 11, 13};  
	int c[6][18] = {0};  
	/*
	cout<<"请输入背包的最大容量:"<<endl;  
	cin>>W;
	cout<<"输入物品数:\n"<<endl;
	cin>>n;
	cout<<"请分别输入物品的重量:"<<endl;
	for(int i=0;i<n;i++)
		cin>>w[i];
	cout<<"请分别输入物品的价值:"<<endl;
	for(int i=0;i<n;i++)
		cin>>v[i];

		*/


	DP(n, W, c, v, w);  
	cout<<c[5][17]<<endl;  //最大价值
	int x[5];  
	findPath(c, x, w, n, W);  
	for (int i = 0; i < n; i++)  
		cout<<x[i]<<" ";  

	cout<<"\n------------------------------\n";
	for (auto& it : c) {
		for (auto& iter: it) {
			if (iter < 10)
				cout<<iter<<"   ";
			else
				cout<<iter<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}
