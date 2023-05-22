#include<bits/stdc++.h>

using namespace std;


class sinhvien{
	// thuoc tinh
	// private: chi dung ben trong class. duoc bao ve. ko bieu hien ra ben ngoai.
	private:
		string sbd;
	 	string hoten;
	 	int namsinh;
		string gioitinh;
	 	float diemtoan;
	 	float diemly;
	 	float diemhoa;
	//phuong thuc . public: ca trong va ngoai class
	public:
		//ham tao và ham huy
		 sinhvien();
		~sinhvien();
		void nhap();
		void xuat();
		void tongdiem();
		void laydiem();
};

sinhvien::sinhvien()
{
	sbd = '\0';
	hoten = '\0';
	namsinh = 0;
	gioitinh = '\0';
	diemtoan = 0;
	diemly = 0;
	diemhoa=0;	
}

sinhvien::~sinhvien()
{
	this->sbd = '\0';
	this->hoten = '\0';
	this->namsinh = 0;
	this->gioitinh = '\0';
	this->diemtoan = 0;
	this->diemly = 0;
	this->diemhoa =0 ;
}

void sinhvien::nhap(){// dau cham de hien thi nhap la con cua class
	cout<<"nhap so bao danh cua sinh vien la: ";
	cin.ignore();
	getline(cin,sbd);
	cout<<"nhap ho ten cua sinh vien la: ";
	getline(cin,hoten);
	cout<<"nhap nam sinh cua sinh vien la: ";
	cin>>namsinh;
	cout<<"nhap gioi tinh cua sinh vien la: ";
	cin.ignore();
	getline(cin,gioitinh);
	cout<<"nhap diem toan cua sinh vien la: ";
	cin>>diemtoan;
	cout<<"nhap diem ly cua sinh vien la: ";
	cin>>diemly;
	cout<<"nhap diem hoa cua sinh vien la: ";
	cin>>diemhoa;
}

void sinhvien::xuat(){
	cout<<setw(10)<<sbd<<setw(20)<<hoten<<setw(20)<<namsinh<<setw(20)<<gioitinh<<setw(20)<<diemtoan<<setw(20)<<diemly<<setw(20)<<diemhoa<<endl;
}

void sinhvien::tongdiem(){
	float tong =0;
	tong = diemtoan + diemly + diemhoa;
	cout<<tong;
}

void sinhvien::laydiem(){
	cout<<setw(20)<<"diem toan"<<setw(20)<<"diem ly"<<setw(20)<<"diem hoa"<<endl;
	cout<<setw(20)<<diemtoan<<setw(20)<<diemly<<setw(20)<<diemhoa<<endl;
}

int main(){
	int n;
	cout<<"nhap so sinh vien:";
	cin>>n;
	sinhvien *t = new sinhvien[n];
	for (int i=0;i<n;i++){
		cout<<"Thong tin sinh vien thu "<<i+1<<" la: "<<endl;
		t[i].nhap();
	}
	cout<<endl<<setw(50)<<"------------Danh sach sinh vien------------"<<endl;
	cout<<setw(10)<<"So bao danh:"<<setw(20)<<"Ho Ten"<<setw(20)<<"nam sinh"<<setw(20)<<"gioi tinh"<<setw(20)<<"diem toan"<<setw(20)<<"diem ly"<<setw(20)<<"diem hoa"<<endl;
	for (int i=0;i<n;i++){
		t[i].xuat();
	}
	for (int i=0;i<n;i++){
		cout<<"Tong diem cua cac sinh vien thu "<<i+1<<" la: ";
		t[i].tongdiem();
		cout<<endl;
	}
	for (int i=0;i<n;i++){
		cout<<"Diem cua cac sinh vien thu "<<i+1<<" la: "<<endl;
		t[i].laydiem();
	}
}


