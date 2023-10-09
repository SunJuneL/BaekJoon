#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

class Couple
{
public:
	int _age = 0;
	string _name = "";

	Couple() {};
	Couple(int age, string name)
	{
		_age = age;
		_name = name;
	}

	bool operator<= (const Couple &other)
	{
		if ((_age) <= other._age)
			return true;
		else
			return false;
	}

	Couple& operator= (const Couple& other)
	{
		_age = other._age;
		_name = other._name;
		return *this;
	}
};

Couple Arr[MAX];
Couple Temp[MAX];
int N;

void Swap(Couple* c, int i, int j)
{
	Couple temp = c[i];
	c[i] = c[j];
	c[j] = temp;
}

void Print()
{
	for (int i = 0; i < N; i++)
	{
        cout << Arr[i]._age << " " << Arr[i]._name << "\n";
	}
}

void Merge(int left, int mid, int right)
{
    int l = left, r = mid;

    int i = 0;

    while (l < mid && r < right)
    {
        if (Arr[l] <= Arr[r])
        {
            Temp[i] = Arr[l];
            l++;
        }
        else
        {
            Temp[i] = Arr[r];
            r++;
        }
        i++;
    }

    while (l < mid)
    {
        Temp[i] = Arr[l];
        l++;
        i++;
    }

    while (r < right)
    {
        Temp[i] = Arr[r];
        r++;
        i++;
    }

    for (int j = 0; j < i; j++)
        Arr[left + j] = Temp[j];
}

void MergeSort(int left, int right)
{
    if (left + 1 >= right)
        return;

    int mid = (right + left) / 2;
    MergeSort(left, mid);
    MergeSort(mid, right);
    Merge(left, mid, right);
}

int main()
{
    // cout << "N 입력 : ";
    cin >> N;

    // cout << "\n-------------------------- 배열 입력 --------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i]._age >> Arr[i]._name;
    }

    MergeSort(0, N);

    // cout << "\n--------------------------------결과------------------------------" << endl;

    Print();
}