#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;

bool in(vector<string>& v, string str)
{
	int count = v.size();

	cout << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
		if (str.compare(v[i]) != 0)
			count--;
	}

	if (count == 0)
		return false;
	else
		return true;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		v.push_back(str);
	}

	cout << in(v, "no");
}