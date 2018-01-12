#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	while(cin>>n)
	{
		cout<<"Factor: "<<n<<" = ";
		for(int i=2;i*i<=n;i++)
		{
			while(n%i==0)
			{
				n=n/i;
				cout<<i<<" ";
			}
		}
		if(n>1)cout<<n<<endl;
	}
	return 0;
}
