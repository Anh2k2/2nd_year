/*
Lap ham de quy tim gia tri min cua 1 day n so thuc 
*/
#include<bits/stdc++.h>
using namespace std;
int min(float a[], int n){
	if(n==1) return a[0];
	if(a[n-1]<min(a,n-1)) return a[n-1];
	return min(a,n-1); 
} 
int main()
{
	float a[100],n;
	cout<<"n = ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i]; 
	} 
	cout<<"Min = "<<min(a,n); 
}

