#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
//#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;

int N;
int M;
int S[1000];

void sort(int* S, int n, int layer)
{
	if (layer > 2)return;
	if (n <= 1)return;
	int p = 0;
	for (int i = 1; i < n; i++)
	{
		if (S[0] > S[i])
		{
			int t = S[i];
			S[i] = S[p + 1];
			S[p + 1] = t;
			p++;
		}
	}
	int t = S[0];
	S[0] = S[p];
	S[p] = t;
	
	sort(S, p, layer + 1);
	sort(S + p + 1, n - (p + 1), layer + 1);
}

void Print3(int S[1000], int N)
{
	sort(&S[0], N, 1);
	for (int i = 0; i < N; i++)cout << S[i] << ' ';
	cout << endl;
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
	//system("pause");
	return 0;
}

/*正确*/