//giai thua demo dlist code by tichpx@utc.edu.vn 7/2020
#include<bits/stdc++.h>
#include"dlist.cpp"
using namespace std;
int main()
{
	int n,d=0;  //d dung dem so so 0 tan cung cua n!
	dlist<int> L(1,1);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		long long nho=0;
		for(auto z=L.rbegin();z!=L.rend();z++)
		{
			nho+=*z*i;
			*z=nho%10;
			nho/=10;
		}
		while(nho) {L.push_front(nho%10); nho/=10;}
		while(L.back()==0) {d++; L.pop_back();}
	}
	for(auto z:L) cout<<z;
	//for(dlist<int>::iterator it=L.begin();it!=L.end();it++) cout<<*it;
	cout<<string(d,'0');
}
 
