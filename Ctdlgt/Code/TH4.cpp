#include<bits/stdc++.h>
using namespace std;
void Nhap(int *&a, int n){
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
void XuatT(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
void XuatG(int *a,int n){
	for(int i=n-1;i>=0;i--){
		cout<<a[i]<<"\t";
	}
}
void QuickSort(int *&a,int left, int right){
	if(left>=right) return;
	int chot = a[(left+right)/2];
	int i = left, j = right;
	do{
		while(a[i]<chot) i++; 
		while(a[j]>chot) j--; 
		if(i<=j){
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}	
	}while(i<j);
	QuickSort(a,left,j);
	QuickSort(a,i,right);
}
void Merge(int *&a,int left,int mid, int right){

	int nt = right - left +1;
	int t[nt];
	int pos = 0;
	int i = left;
	int j = mid + 1;
	while(!(i>mid && j>right)){
		if((i<=mid && j<=right && a[i]<a[j])||j>right){
			t[pos++] = a[i++];
		}else {
			t[pos++] = a[j++];
		}
	}
	for(i=0;i<nt;i++){
		a[left+i] = t[i];
	}
}
void MergeSort(int *&a, int left, int right){
	if(left>=right) return ;
	int mid = (left + right)/2;
	MergeSort(a,left,mid);
	MergeSort(a,mid+1,right);
	Merge(a,left,mid,right); // tron trai-> giua -> phai
}

void Heapy(int *&a, int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && a[l] > a[largest]) 
        largest = l; 
    if (r < n && a[r] > a[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
        Heapy(a, n, largest); 
    } 
} 
void HeapSort(int *&a, int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        Heapy(a, n, i); 
    for (int i=n-1; i>0; i--) 
    { 
        swap(a[0], a[i]); 
        Heapy(a, i, 0); 
    } 
} 
int main(){
	int n;
	
	int *a = new int [n+1];
	cout<<"Nhap n: ";cin>>n;
	Nhap(a,n); 
	do{
		int luachon;
		cout<<"\n1. QuickSort Tang";
		cout<<"\n2. QuickSort Giam";
		cout<<"\n3. MergeSort Tang";
		cout<<"\n4. MergeSort Giam";
		cout<<"\n5. HeapSort Tang";
		cout<<"\n6. HeapSort Giam";
		cout<<"\n7. Exit";
		cout<<"\nLua chon: ";
		cin>>luachon;
		if(luachon == 1){
			QuickSort(a,0,n-1);
			XuatT(a,n);
		}else if(luachon == 2){
			QuickSort(a,0,n-1);
			XuatG(a,n);
		}else if(luachon == 3){
			MergeSort(a,0,n-1);
			XuatT(a,n);
		}else if(luachon == 4){
			MergeSort(a,0,n-1);
			XuatG(a,n);
		}else if(luachon == 5){
			HeapSort(a,n);
			XuatT(a,n);
		}else if(luachon == 6){
			HeapSort(a,n);
			XuatG(a,n);
		}else {
			exit(0);
		}
	}while(true);
}
