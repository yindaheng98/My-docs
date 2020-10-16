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

int* f(vector<int>a, int target)
{
	if (a.size() <= 0)return new int[2] {0, 0};
	int i = 0, j = a.size() - 1;
	while (i < j)
	{
		if (i == j - 1)
		{
			if (a[i] < target&&target < a[j])break;
			else if (target < a[i] && target < a[j])return new int[2] {i, i};
			else if (a[i] < target&& a[j] < target)return new int[2] {j, j};
		}
		int mid = (i + j) / 2;
		if (a[mid] < target)i = mid;
		else if (target < a[mid])j = mid;
		else i = j = mid;
	}
	return new int[2]{ i,j };
}

bool find(int** A, int m, int n, int target)
{
	if (m < 1 || n < 1)return false;
	else if (target > A[0][n - 1])
	{
		vector<int>a = vector<int>(m - 1);
		for (int i = 0; i < m - 1; i++)
			a[i] = A[i][n - 1];
		return find(&A[1], m - f(a, target)[1] - 1, n, target);
	}
	else if (target < A[0][n - 1])
	{
		vector<int>a = vector<int>(n - 1);
		for (int i = 0; i < n - 1; i++)
			a[i] = A[0][i];
		return find(A, m, n - f(a, target)[0] - 1, target);
	}
	else return true;
}

bool Process(vector<vector<int>>A, int target)
{
	int m = A.size();
	if (m <= 0)return false;
	int n = A[0].size();
	if (n <= 0)return false;
	int** AA = new int*[m];
	for (int i = 0; i < m; i++)
	{
		n = A[i].size();
		AA[i] = new int[n];
		for (int j = 0; j < n; j++)
			AA[i][j] = A[i][j];
	}
	return find(AA, m, n, target);
}

int main()
{
	int nums;
	cin >> nums;
	while (nums-- > 0)
	{
		int m, n, target;
		cin >> m >> n >> target;
		vector<vector<int>>A = vector<vector<int>>(m);
		for (int i = 0; i < m; i++)
		{
			A[i] = vector<int>(n);
			for (int j = 0; j < n; j++)
				cin >> A[i][j];
		}
		printf("%s\n", Process(A, target) ? "true" : "false");
	}
	system("pause");
	return 0;
}

/*不正确*/