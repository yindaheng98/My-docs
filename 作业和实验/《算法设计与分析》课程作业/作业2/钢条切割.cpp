#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::map;
using std::pair;

int Process(int length, map<int, int>Price)
{
	vector<int>P(length + 1);
	for (int i = 0; i <= length; i++)
	{
		int max = 0;
		for (auto pr : Price) {
			int l = pr.first, p = pr.second;
			if (l <= i)
			{
				int price = p + P[i - l];
				if (price > max)max = price;
			}
			else break;
		}
		P[i] = max;
	}
	return P[length];
}

int main()
{
	int m;
	cin >> m;
	while (m-- > 0)
	{
		int n, k;
		cin >> n >> k;
		map<int, int>Price;
		for (int i = 0; i < k; i++)
		{
			int l, p;
			cin >> l >> p;
			Price.insert(pair<int, int>(l, p));
		}
		printf("%d\n", Process(n, Price));
	}
	system("pause");
	return 0;
}

/*正确*/