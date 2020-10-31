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

int Process(string S[2])
{
	int n[2] = { (int)S[0].size(),(int)S[1].size() };
	vector<vector<int>>M(n[0]);
	for (int i = 0; i < n[0]; i++)
		M[i] = vector<int>(n[1]);
	M[0][0] = S[0][0] == S[1][0] ? 1 : 0;
	for (int i = 1; i < n[0]; i++)
		if (S[0][i] == S[1][0] || M[i - 1][0] > 0)
			M[i][0] = 1;
	for (int j = 1; j < n[1]; j++)
		if (S[1][j] == S[0][0] || M[0][j - 1] > 0)
			M[0][j] = 1;
	for (int i = 1; i < n[0]; i++)
	{
		for (int j = 1; j < n[1]; j++)
			if (S[0][i] == S[1][j])
				M[i][j] = 1 + M[i - 1][j - 1];
			else M[i][j] = max(M[i - 1][j], M[i][j - 1]);
	}
	return M[n[0] - 1][n[1] - 1];
}

int main()
{
	int m;
	cin >> m;
	while (m-- > 0)
	{
		string S[2];
		cin >> S[0] >> S[1];
		printf("%d\n", Process(S));
	}
	system("pause");
	return 0;
}

/*正确*/