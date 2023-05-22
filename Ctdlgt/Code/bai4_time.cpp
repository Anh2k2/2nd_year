#include<bits/stdc++.h>

// bien co su lieu
// doi tuong nhu bien nhung con co ham.

using namespace std;

class Time{
	private:
		int gio, phut, giay;
	public:
		// ham tao khong co doi
		Time(){gio = phut = giay = 0;}
		Time(int,int,int);
		~Time(){}
		void nhap();
		void in();
		// lay gia tri gio ra de doi.
		int laygio(){
		return gio;
		}
		// dat gia tri cho gio, phai truyen tham so.
		// phai dat g ko bi trung voi gio
		void datgio( int g);
		void datphut(int p);
		void datgiay(int second);
};

void Time::nhap(){
	do{
	cout<<"Gio: ";
	cin>>gio;
	}while(gio>=24||gio<0);
	
	do{
	cout<<"Phut: ";
	cin>>phut;
	}while(phut>60||phut<0);
	
	do{
	cout<<"Giay: ";
	cin>>giay;
	}while(giay>60||giay<0);
}

Time::Time(int a , int b , int c){
	gio = (a<24&&a>=0)?a:0;
	phut = (b<61&&b>=0)?b:0;
	giay = (c<61&&c>=0)?c:0;
}

void Time::in(){
	// setfill; in ra so 0 dung dau
		cout<<setfill('0')<<setw(2)<<gio<<":";
		cout<<setfill('0')<<setw(2)<<phut<<":";
		cout<<setfill('0')<<setw(2)<<giay;
}

void Time::datgio(int g){
	gio = g;
}

void Time::datphut(int p){
	phut =p;
}

void Time::datgiay(int second){
	giay = second;
}

int main(){
	int g,p,second;
	cout<<"----------Cau tu khong doi:----------"<<endl;
	Time t;
	t.nhap();
	cout<<"Gio cua nhap la: ";
	t.in();
	cout<<endl;
	do{
		cout<<"Nhap gio thay doi: ";
		cin>>g;
	}while(g>=24||g<0);
	t.datgio(g);
	do{
		cout<<"Nhap phut thay doi: ";
		cin>>p;
	}while(p>61||p<0);
	t.datphut(p);
	do{
		cout<<"Nhap giay thay doi: ";
		cin>>second;
	}while(second>61||second<0);
	t.datgiay(second);
	t.in();
	
	cout<<endl<<"----------Cau tu co doi:----------"<<endl;
	Time s(12,05,26);
	s.in();
	cout<<endl;
	do{
		cout<<"Nhap gio thay doi: ";
		cin>>g;
	}while(g>=24||g<0);
	s.datgio(g);
	do{
		cout<<"Nhap phut thay doi: ";
		cin>>p;
	}while(p>61||p<0);
	s.datphut(p);
	do{
		cout<<"Nhap giay thay doi: ";
		cin>>second;
	}while(second>61||second<0);
	s.datgiay(second);
	s.in();
}

