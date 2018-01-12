#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str, st;
	cin >> st;
	int num = 0;
	bool flag = false;
	for (int j = 0; j < st.length(); j++){
		num = ((num % 2) * 10) + (st[j] - '0');
		if (num / 2 == 0 && flag)str += (num / 2) + '0';
		if (num / 2)str += (num / 2) + '0', flag = true;
	}
	cout << str << endl;
	return 0;
}
