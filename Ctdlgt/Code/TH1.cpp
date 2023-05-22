#include <bits/stdc++.h>
#include <vector>
using namespace std;
class SV {
private:	
	string masv;
    string hoten; 
	int ngay; 
	int thang;
	int namsinh; 
	string gioi;
	string que; 
	float dtb; 
public: 
	float getdiem(){return dtb;}
	friend istream & operator >> (istream &is,SV &s){
	cout<<"Nhap ma sinh vien: ";
	is>>s.masv;
	cout<<"Nhap ho va ten: ";
	is.ignore(); 
	getline(is, s.hoten);
	cout<<"Nhap ngay, thang, nam sinh cua sinh vien:";
	do{
		is>>s.ngay>>s.thang>>s.namsinh;
		if (31<s.ngay<0 || 12<s.thang<0 || 2021<s.namsinh<0){
			cout<<"\nKhong hop le !!! Xin vui long nhap lai !!! \n";
			is>>s.ngay>>s.thang>>s.namsinh;
		}
	}while(31<s.ngay<0 || 12<s.thang<0 || 2021<s.namsinh<0);
	cout<<"Nhap gioi tinh: ";
	is.ignore();
	getline(is, s.gioi);
	cout<<"Nhap que quan: ";
	is.ignore(); 
	getline(is, s.que);
	cout<<"Nhap diem trung binh tich luy: ";
	is>>s.dtb; 
	return is; 	 
    }
	friend ostream &operator<<(ostream &os,SV s){
		os<<setw(5)<<s.masv<<setw(15)<<s.hoten<<setw(15)<<s.ngay<<setw(15)<<s.thang<<setw(15)<<s.namsinh<<setw(15)<<s.gioi<<setw(15)<<s.que<<setw(15)<<s.dtb<<endl; 	
	    return os;
	}
};
class Lop{
	vector<SV> C;	
	public: 
		friend istream &operator>>(istream &is, Lop &s){
			cout<<"Nhap so luong sinh vien: ";
			int n;
			is>>n;
			s.C.resize(n);
			for(auto &c:s.C) is>>c;
			return is;
		}
		friend ostream &operator<<(ostream &os, Lop s){
			for(auto c:s.C) os<<c<<"\n";
			return os;
		}	
		void ThemCuoi(){
			SV t;
			cout<<"\nNhap thong tin sinh vien them vao vi tri cuoi:\n";
			cin>>t;
			C.push_back(t);
		}
		void ThemVaoViTri(){
			int vitri;
			cout<<"Nhap vi tri them sinh vien: ";
			cin>>vitri;
			int dem=0;
			vector<SV>::iterator it;
			for(it=C.begin();it!=C.end();it++){
				dem++;
				if(dem==vitri){
					SV t;
					cout<<"\nNhap thong tin sinh vien them:\n";
					cin>>t;
					C.insert(it,t);
					break;
				}
			}
		}
		void XoaViTri(){	
			int vitri;
			cout<<"Nhap vi tri xoa bo sinh vien: ";
			cin>>vitri;
			int dem=0;
			vector<SV>::iterator it;
			for(it=C.begin();it!=C.end();it++){
				dem++;
				if(dem==vitri){
					C.erase(it);
					break;
				}
			}	
			
		}
		void ThayThe(){
			int vitri;
			cout<<"Nhap vi tri thay the sinh vien: ";
			cin>>vitri;
			int dem=0;
			vector<SV>::iterator it;
			for(it=C.begin();it!=C.end();it++){
				dem++;
				if(dem==vitri){
					SV t;
					cout<<"\nNhap thong tin sinh vien:\n";
					cin>>t;
					C.erase(it);
					C.insert(it,t);
					break;
				}
			}
		}
		void MaxSV(){
			for(int i=0;i<C.size();i++){
				for(int j=i+1;j<C.size();j++){
					if(	C[i].getdiem()<C[j].getdiem()){
						swap(C[i],C[j]);
					}
				}						
			}
			int n;
			cout<<"Nhap n: "; cin>>n;
			int t=(n<C.size()?n:C.size());
			for(int i=0;i<=t;i++){
				cout<<C[i]<<endl;
			}
		}
};

int main(){
	Lop L;
	do {
		int chon;
		cout<<"1. Nhap so luong sinh vien. \n";
		cout<<"2. Them 1 sinh vien vao vi tri cuoi.\n";
		cout<<"3. Them 1 sinh vien vao vi tri i.\n";
		cout<<"4. Xoa bo sinh vien thu i.\n";
		cout<<"5.Thay the sinh vien thu i bang 1 sinh vien moi.\n";
		cout<<"6. In ra n sinh vien co diem cao nhat.\n";
		cout<<"7. In ra danh sach hien tai.\n";
		cout<<"8. Thoat.\n";
		cout<<"Nhap lua chon: ";
		cin>>chon;
		if(chon==1){cin>>L;}
		else if(chon==2){L.ThemCuoi();}
		else if(chon==3){L.ThemVaoViTri();}
		else if(chon==4){L.XoaViTri();}
		else if(chon==5){L.ThayThe();}
		else if(chon==6){L.MaxSV();}
		else if(chon==7){
		cout<<setw(5)<<"MSV"<<setw(15)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(15)<<"Thang sinh"<<setw(15)<<"Nam sinh"<<setw(15)<<"Gioi tinh"<<setw(15)<<"Que quan"<<setw(15)<<"Diem GPA"<<endl<<L;
        }
		else {exit(0);}
	}while(true);

}
