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

int find(int* M, int* N, int m, int n, int k)
{
	if (m <= 0)return N[k - 1];
	if (n <= 0)return M[k - 1];
	if (k <= 1)return M[0] < N[0] ? M[0] : N[0];
	int mid = k / 2;
	int loc = mid - 1;
	if (mid >= m)
	{
		if (M[m - 1] <= N[loc])return find(0, N, 0, n, k - m);
		if (M[m - 1] > N[loc])return find(M, &N[mid], m, n - mid, k - mid);
	}
	if (mid >= n)
	{
		if (M[loc] < N[n - 1])return find(&M[mid], N, m - mid, n, k - mid);
		if (M[loc] >= N[n - 1])return find(M, 0, m, 0, k - n);
	}
	if (M[loc] == N[loc])
	{
		if (k % 2 < 1)return M[loc];
		return M[loc + 1] < N[loc + 1] ? M[loc + 1] : N[loc + 1];
	}
	if (M[loc] < N[loc])return find(&M[mid], N, m - mid, n, k - mid);
	if (M[loc] > N[loc])return find(M, &N[mid], m, n - mid, k - mid);
}

double Process(vector<int>& S1, vector<int>& S2)
{
	int N1 = S1.size(), N2 = S2.size();
	int N = N1 + N2;
	if (N % 2 >= 1)
	{
		if (N1 <= 0)return double(S2[N / 2]);
		if (N2 <= 0)return double(S1[N / 2]);
		return double(find(&S1[0], &S2[0], N1, N2, (N + 1) / 2));
	}
	else
	{
		if (N1 <= 0)return double(S2[N / 2] + S2[N / 2 - 1])/2;
		if (N2 <= 0)return double(S1[N / 2] + S1[N / 2 - 1])/2;
		int l = find(&S1[0], &S2[0], N1, N2, N / 2);
		int r = find(&S1[0], &S2[0], N1, N2, N / 2 + 1);
		return double(l + r) / 2;
	}
}

int main()
{
	int M;
	cin >> M;
	vector<int>S[2];
	while (M-- > 0)
	{
		int N[2];
		cin >> N[0]>> N[1];
		for (int j = 0; j < 2; j++)
		{
			S[j] = vector<int>(N[j]);
			for (int i = 0; i < N[j]; i++)
			{
				cin >> S[j][i];
			}
		}
		printf("%.5f\n", Process(S[0], S[1]));
	}
	system("pause");
	return 0;
}

/*正确*/