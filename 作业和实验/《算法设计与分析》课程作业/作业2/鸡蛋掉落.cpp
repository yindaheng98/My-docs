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

//在remainTestCount个测试机会（扔鸡蛋的机会 或者移动的次数），eggsCount个鸡蛋可以确定的楼层数量
int getConfirmFloors(int remainTestCount, int eggsCount) {
	if (remainTestCount == 1 || eggsCount == 1) {
		//如果remainTestCount == 1你只能移动一次，则你只能确定第一楼是否，也就是说鸡蛋只能放在第一楼，如果碎了，则F == 0，如果鸡蛋没碎，则F == 1
		//如果eggsCount == 1鸡蛋数为1，它碎了你就没有鸡蛋了，为了保险，你只能从第一楼开始逐渐往上测试，如果第一楼碎了（同上），第一楼没碎继续测第i楼，蛋式你不可能无限制的测试，因为你只能测试remainTestCount次
		return remainTestCount;
	}
	return getConfirmFloors(remainTestCount - 1, eggsCount - 1) + 1 + getConfirmFloors(remainTestCount - 1, eggsCount);
}
int superEggDrop(int K, int N) {
	int remainTestCount = 1;//穷举移动次数（测试的次数）
	while (getConfirmFloors(remainTestCount, K) < N) {
		++remainTestCount;
	}
	return remainTestCount;
}

int main()
{
	int m;
	cin >> m;
	while (m-- > 0)
	{
		int K, N;
		cin >> K >> N;
		printf("%d\n", superEggDrop(K, N));
	}
	system("pause");
	return 0;
}

/*正确*/