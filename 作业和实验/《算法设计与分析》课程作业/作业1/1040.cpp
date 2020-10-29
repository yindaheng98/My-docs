#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::vector;

bool find(int** A, int m, int n, int target)
{
	if (m < 1 || n < 1)return false;
	else if (target > A[0][n - 1])return find(&A[1], m - 1, n, target);
	else if (target < A[0][n - 1])return find(A, m, n - 1, target);
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
	return 0;
}

/*正确*/