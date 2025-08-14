#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string str;
	cin >> str;

	stack<char> S;
	int answer{ 0 };
	bool did_delete{ false };

	for(char& c: str)
	{
		if (c == ')')
		{
			if (did_delete == false) //meet laser
			{
				did_delete = true;
				S.pop();
				answer += S.size();
			}
			else
			{
				S.pop();
				++answer;
			}
			continue;
		}

		did_delete = false;
		S.push(c);
	}

	cout << answer;

	return 0;
}