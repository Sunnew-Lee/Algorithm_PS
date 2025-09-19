#include <iostream>
#include <vector>

using namespace std;

int N;

//2. start func -> print '(' + recur if need divide + print ')' if returned
//	2.1. for 0~3, check if need to divide
//	2.2. if no need to div, print 0 or 1
void func(int div_count, int section, pair<int,int>&& start, vector<vector<char>>& v)
{
	int len = N >> div_count;
	if (len == '1')
	{
		//print this num
		cout << v[start.first][start.second];
		return;
	}

	//len>>1; + section => start point
	// if section
	//	0-> 0,0	x,y
	//	1-> len>>1 , 0
	//	2-> 0, len>>1
	//	3-> len>>1,len>>1

	int next_len = len >> 1;
	pair<int, int> new_start = start;	//y,x
	switch (section)
	{
	case 0: break;
	case 1: new_start.second += len; break;
	case 2: new_start.first += len;  break;
	case 3: new_start.first += len; new_start.second += len; break;
	default:
		cout << "wrong section"; break;
	}

	const char value = v[new_start.first][new_start.second];
	bool need_div{ false };

	//check if need to divide
	for (int i{ new_start.first }; i < new_start.first+len; ++i)
	{
		for (int j{ new_start.second }; j < new_start.second+len; ++j)
		{
			if (v[i][j] != value)
			{
				need_div = true;
				break;
			}
		}

		if (need_div)
			break;
	}

	if (need_div)
	{
		cout << '(';
		func(div_count + 1, 0, move(new_start), v);
		func(div_count + 1, 1, move(new_start), v);
		func(div_count + 1, 2, move(new_start), v);
		func(div_count + 1, 3, move(new_start), v);
		cout << ')';
	}

	else
		cout << value;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> N;

	// N-> powered 2, 2^0~2^6
	//1. cin setup
	vector<vector<char>> arr(N, vector<char>(N, 0));
	for (int i{ 0 }; i < N; ++i)
	{
		for (int j{ 0 }; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	//2. start func -> print '(' + recur if need divide + print ')' if returned
	func(0, 0, { 0,0 }, arr);
	//	2.1. for 0~3, check if need to divide
	//	2.2. if no need to div, print 0 or 1
	


	//func(cur power means of div numbers, section?)

	return 0;
}