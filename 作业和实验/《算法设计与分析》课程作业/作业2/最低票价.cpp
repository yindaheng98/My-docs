#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#include <string>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::map;
using std::pair;
using std::string;
int mincostTickets(vector<int>& days, vector<int>& costs)
{
	vector<int>f(366);
	int d = 0;
	for (int x = 1; x <= 365; x++)
	{
		if (d < days.size() && x == days[d])
		{
			d++;
			if (x >= 1)f[x] = f[x - 1] + costs[0];
			if (x >= 7)f[x] = min(f[x], f[x - 7] + costs[1]);
			else f[x] = min(f[x], costs[1]);
			if (x >= 30)f[x] = min(f[x], f[x - 30] + costs[2]);
			else f[x] = min(f[x], costs[2]);
		}
		else f[x] = f[x - 1];
	}
	return f[365];
}

int main()
{
	int m;
	cin >> m;
	while (m-- > 0)
	{
		int t;
		cin >> t;
		vector<int>days(t);
		for (int i = 0; i < t; i++)cin >> days[i];
		vector<int>costs(3);
		for (int i = 0; i < 3; i++)cin >> costs[i];
		printf("%d\n", mincostTickets(days, costs));
	}
	system("pause");
	return 0;
}

/*正确*/