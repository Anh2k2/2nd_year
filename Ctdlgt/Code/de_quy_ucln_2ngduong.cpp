/*
Lap ham de quy tim uoc so chung cua 2 so nguyen duong 
*/
#include<bits/stdc++.h>
using namespace std;
int UCLN(int a, int b){
	if(a*b==0) return a+b;
	if(a>b) return UCLN(a-b,b);
	else return UCLN(a,b-a); 
} 
int main()
{
	int a,b; 
	cout<<"a = ";
	cin>>a;
	cout<<"b = ";
	cin>>b; 
	cout<<"Uoc so chung cua 2 so nguyen a va b la "<<UCLN(a,b); 
}

