#include <iostream>
#include <stack>
#include <string>

using namespace std;

//int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	bool possible{ true };
	string answer = "";
	stack<int> S;
	int i{ 0 }, index{ 1 }, num;

	while (i < n)
	{
		cin >> num;
		while (index <= num)
		{
			answer += "+\n";
			S.push(index++);
		}

		if (S.top() == num)
		{
			answer += "-\n";
			S.pop();
			++i;
		}
		else
		{
			possible = false;
			break;
		}
	}

	if (possible)
		cout << answer;
	else
		cout <<  "NO";


	return 0;
}