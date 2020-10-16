#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;

int N;
int M;
int S[1000];

int find(int S[1000], int n)
{
	int s[2];
	if (S[0] < S[1])
	{
		s[0] = S[0];
		s[1] = S[1];
	}
	else
	{
		s[0] = S[1];
		s[1] = S[0];
	}
	for (int i = 2; i < n; i++)
	{
		if (S[i] < s[0])
		{
			s[1] = s[0];
			s[0] = S[i];
		}
		else if (S[i] < s[1])
			s[1] = S[i];
	}
	return s[1];
}

void Print3(int S[1000], int N)
{
	cout << find(S, N) << endl;
}

int main()
{
	cin >> M;
	while (M-- > 0)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> S[i];
		}
		Print3(S, N);
	}
	system("pause");
	return 0;
}

/*正确*/