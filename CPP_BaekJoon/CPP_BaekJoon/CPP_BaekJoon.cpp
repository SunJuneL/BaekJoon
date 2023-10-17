#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

enum Range
{
	MAX = 1000000,
};

set<int> s;
int arr[MAX];
int ans[MAX];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		s.insert(num);
	}

	int index = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		arr[index] = *iter;
		index++;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		
		if (arr[lower_bound(arr, arr + N, num) - arr] == num)
			cout << "1 ";
		else
			cout << "0 ";
	}
}