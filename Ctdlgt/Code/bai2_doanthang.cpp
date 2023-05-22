#include<bits/stdc++.h>

using namespace std;

class doanthang{
	private:
		float xA, yA , xB , yB;
	public:
		doanthang(){
		}
		doanthang(float,float,float,float);
		~doanthang(){
			
		}
		void nhap();
		void in();
		float dodai(float,float,float,float){
			return sqrt (pow (xB-xA,2) + pow (yB-yA,2));
		}
};

void doanthang::nhap(){
	cout<<"Nhap toa diem thu nhat: ";
	cin>>xA>>yA;
	cout<<"Nhap toa diem thu hai: ";
	cin>>xB>>yB;
}

doanthang::doanthang(float a , float b , float c , float d){
	xA=a;
	yA=b;
	xB=c;
	yB=d;
}

void doanthang::in(){
	cout<<"Toa do diem la:";
	cout<<"("<<xA<<" , "<<yA<<") , ("<<xB<<" , "<<yB<<")";
}

int main(){
	float xA,yA,xB,yB;
	cout<<"----------Cau tu khong doi:----------"<<endl;
	doanthang t;
	t.nhap();
	cout<<setprecision(1)<<fixed;
	t.in();
	cout<<endl<<"Do dai cuadoan thang la: "<<t.dodai(xA,yA,xB,yB);
	
	
	doanthang s(5.7,7.9,9,8);
	cout<<endl<<"----------Cau tu co doi:----------"<<endl;
	cout<<setprecision(1)<<fixed;
	s.in();
	cout<<endl<<"Do dai cuadoan thang la: "<<s.dodai(xA,yA,xB,yB);
}

