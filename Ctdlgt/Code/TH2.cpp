#include<bits/stdc++.h>
using namespace std;
class STACK{
	int n;
	list<int> elem;
	public:
		STACK() {n=0;}
		STACK(int m) {n=m;}
		~STACK() {n=0;}
		void Push(int p);
		int Top();
		bool IsEmpty() {return n==0;}
		int Size() {return n;}
		void HauTo();
		void Menu();
}; 

void STACK::Push(int p){
	n++;
	elem.push_back(p);
}

int STACK::Top(){
	auto j = elem.begin();
	for(int i=0;i<(n-1);i++){
		j++;
	}
	int t=*j;
	elem.erase(j);
	n--;
	return t;
}

float f(int u, int v, char c){
	if(c=='+') return (u+v);
	if(c=='-') return (u-v);
	if(c=='*') return (u*v);
	return u/v;
}

void STACK::HauTo(){
	float GT;
	string x;
	STACK S;
	cout<<"Nhap bieu thuc: ";
	cin>>x;
	for(auto c:x){
		if(c>='0' && c<='9') S.Push(c-'0');
		else{
			int v = S.Top();
			GT = f(S.Top(), v, c);
		}
	}
	cout<<"\tGia tri hau to la: "<<GT;
}

void STACK::Menu(){
	cout<<" ========== Menu ========== \n";
	int chon;
	do{
		STACK t;
		cout<<"1.Them 1 phan tu vao stack.\n";
		cout<<"2.Lay ra 1 phan tu cua stack.\n";
		cout<<"3.Stack rong hay khong.\n";
		cout<<"4.Stack co bao nhieu phan tu.\n";
		cout<<"5.Gia tri cua 1 bieu thuc hau to.\n";
		cout<<"6.Ket thuc.\n";
		cout<<"\nLua chon cua ban: ";cin>>chon;
		if(chon==1){
			int t;
			cout<<"\nNhap phan tu: ";
			cin>>t;
			Push(t);
			cout<<endl;
		}
		else if(chon==2){
			cout<<"\tPhan tu lay ra: ";
			cout<<Top();
			cout<<endl;
		}
		else if(chon==3){
			if(IsEmpty()==true) cout<<"\tStack rong.\n";
			else cout<<"\tStack co phan tu.\n";
		}
		else if(chon==4) cout<<"\tSo phan tu cua stack: "<<Size()<<endl;
		else if(chon==5){
			HauTo();
			cout<<endl;
		}
		else if(chon==6) break;
	}while(1);
}

int main(){
	STACK t;
	t.Menu();
	return 0;
}











