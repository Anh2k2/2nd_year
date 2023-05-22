/*
Viet ham de quy tim kiem 1 chu cai 
nao do co trong 1 xau ki tu hay ko 
*/
#include<bits/stdc++.h>
using namespace std;
char check(char chuoi[],char n){
	int dem=0;
	for(int i=0;i<strlen(chuoi);i++){
		if(chuoi[i]==n) dem++;
	}
	if(dem>0) cout<<"\nKi tu "<< n <<" co trong chuoi "<< dem <<" lan.";
	if(dem==0) return 1;
} 
int main()
{
	char chuoi[100],n;
	int dem =0;
	cout<<"Nhap xau ki tu: ";
	cin>>chuoi;
	cout<<"Nhap ki tu can kiem tra: ";
	cin>>n;
	if(check(chuoi,n)==1) cout<<"Ki tu "<< n <<" khong co trong chuoi.";
}

