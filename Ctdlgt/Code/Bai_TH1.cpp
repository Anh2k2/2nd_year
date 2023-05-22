#include<bits/stdc++.h>
using namespace std;
class SV{
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
    friend istream & operator >> (istream &is,SV &d);	
    friend ostream & operator << (ostream &os,SV d);	
    SV& operator=(SV s){
    	masv = s.masv;
		hoten = s.hoten;
		ngay = s.ngay;
		thang = s.thang;
		namsinh = s.namsinh;
		gioi = s.gioi;
		que = s.que;
		dtb = s.dtb; 
	}	
}; 
istream & operator >> (istream &is,SV &d){
	cout<<"Nhap ma sinh vien: ";
	is>>d.masv;
	cout<<"Nhap ho va ten: ";
	is.ignore(); 
	getline(is, d.hoten);
	cout<<"Nhap ngay, thang, nam sinh cua sinh vien:";
	do{
		is>>d.ngay>>d.thang>>d.namsinh;
		if (31<d.ngay<0 || 12<d.thang<0 || 2021<d.namsinh<0){
			cout<<"\nKhong hop le !!! Xin vui long nhap lai !!! \n";
			is>>d.ngay>>d.thang>>d.namsinh;
		}
	}while(31<d.ngay<0 || 12<d.thang<0 || 2021<d.namsinh<0);
	cout<<"Nhap gioi tinh: ";
	is.ignore();
	getline(is, d.gioi);
	cout<<"Nhap que: ";
	is.ignore(); 
	getline(is, d.que);
	cout<<"Nhap diem trung binh tich luy: ";
	is>>d.dtb; 
	return is; 	 
}
ostream & operator << (ostream &os,SV d){
	os<<setw(10)<<d.masv<<setw(15)<<d.hoten<<setw(15)<<d.ngay<<setw(15)<<d.thang<<setw(15)<<d.namsinh<<setw(15)<<d.gioi<<setw(15)<<d.que<<setw(10)<<d.dtb<<endl; 	
	return os; 
}

template<class SV>
class Vector{
private:
    int N;   //so chieu toi da cua vector 
    SV *V;   //luu tru du lieu 
	int n;   //so phan tu co trong vector 
public:
    Vector(); 
    ~Vector(); 
    int getAtRank(int r, SV &o); 
    int replaceAtRank(int r, SV o); 
    int insertAtRank(int r, SV o); 
    int removeAtRank(int r, SV &o); 
    int size(); 
    int isEmpty(); 			
};
template<class SV>
Vector<SV>::Vector(){
	V = new SV[1];
	N = 1;
	n = 0; 
} 
template<class SV>
Vector<SV>::~Vector(){
	delete V; 
} 
//ham insertAtRank 
template<class SV>
int Vector<SV>::insertAtRank(int r, SV o){
	if(r<0 || r>n) return 0;
	if(n==N){
		SV *A;
		N = 2*N;
		A = new SV[N];
		for(int i=0;i<n;i++)
			A[i]= V[i]; 
		delete V;
		V = A; 
		int k = n-1;
		while(k>=r){
			V[k+1] = V[k];
			k--; 
		} 
	} 
	V[r] = o;
	n++;
	return 1; 
} 
//ham lay ra 1 phan tu
template<class SV>
int Vector<SV>::getAtRank(int r, SV &o){
	if(r<0 || r>(n-1)) return 0;
	o = V[r];
	return 1; 
} 
//ham thay the 1 phan tu
template<class SV>
int Vector<SV>::replaceAtRank(int r, SV o){
	if(r<0 || r>(n-1)) return 0;
	V[r] = o ;
	return 1; 
} 
template<class SV>
int Vector<SV>::removeAtRank(int r, SV &o){
	if(r<0 || r>(n-1)) return 0;
	o = V[r];
	int k = r;
	while(k < (n-1)){
		V[k] = V[k+1];
		k++; 
	} 
	n--; 
	return 1; 
} 
template<class SV>
int Vector<SV>::size(){
	return n; 
} 
template<class SV>
int Vector<SV>::isEmpty(){
	return n==0; 
} 

template <class SVT> 
class VectorItr{ 
private : 
    Vector<SV>* theVector; 
    int cur_Index; 
public: 
    VectorItr(Vector<SV>*V1){
    	theVector = V1; 
        cur_Index = 0; 
    } 
    int hasNext(){ 
        if (cur_Index<theVector->size()) return 1; 
        else return 0; 
    } 
    SV next(){ 
        SV o; 
        theVector->getAtRank(cur_Index, o); 
        cur_Index++; 
        return o; 
    } 
};

class VectorApp {//Lop ung dung lop vector va lop VectorItr  
private: 
    Vector<SV> v; 
public: 
    void InsertElement(); 
    void RemoveElement(); 
    void ReplaceElement(); 
    void ListElement();
	int menu();
	void run(); 
    
}; 
 
void VectorApp::InsertElement(){
	SV x; 
    int r; 
    cout<<"Nhap thong tin cua sinh vien:"; 
    cin>>x; 
    cout<<"Vi tri chen:"; 
    cin>>r; 
    if(v.insertAtRank(r,x)==1) 
        cout<<"Chen phan tu thanh cong!"; 
    else 
        cout<<"Chen phan tu khong thanh cong. Loi do vi tri chen"; 
} 
void VectorApp::RemoveElement(){
    SV x; 
    int r;  
    cout<<"Nhap vi tri cua sinh vien can xoa bo:"; 
    cin>>r; 
    if(v.removeAtRank(r,x)==1) 
        cout<<"Phan tu bi xoa di :"<<x; 
    else 
        cout<<"Xoa phan tu khong thanh cong. Loi do vi tri xoa";  
} 
void VectorApp::ReplaceElement(){ 
    SV x; 
    int r; 
    cout<<"Nhap thong tin sinh vien:"; 
    cin>>x; 
    cout<<"Nhap vi tri can thay the:"; 
    cin>>r; 
    if(v.replaceAtRank(r,x)==1) 
        cout<<"Thay the phan tu thanh cong"; 
    else 
        cout<<"Thay the phan tu khong thanh cong. Loi do vi tri thay  the";  
} 
void VectorApp::ListElement() 
{ 
    VectorItr<SV> Itr(&v); 
    cout<<"Danh sach cac sinh vien:\n"; 
    while(Itr.hasNext()) 
        cout<<Itr.next()<<"\n"; 
} 

int VectorApp::menu() 
{ 
    cout<<"1.Them mot sinh vien moi"; 
    cout<<"\n2.Xoa mot sinh vien"; 
    cout<<"\n3.Thay the mot sinh vien";  
    cout<<"\n4.In danh sach sinh vien"; 
    cout<<"\n5.Ket thuc chuong trinh"; 
    cout<<"\nChon chuc nang tu 1..5:"; 
    int n; 
    cin>>n; 
    return n; 
}

void VectorApp::run() 
{ 
    int ch; 
    do{ 
        system("cls"); 
        ch = menu(); 
        system("cls"); 
        switch(ch) 
    { 
    case 1: 
        InsertElement(); 
        break; 
    case 2: 
        RemoveElement(); 
        break; 
    case 3: 
        ReplaceElement(); 
        break; 
    case 4: 
        ListElement(); 
        break; 
    }  
    } while(ch!=5); 
} 

int main() 
{ 
	int n;
	cout<<"Nhap so sinh vien: ";
	cin>>n;
	SV *a = new SV[n+10];
	
	VectorApp d; 
    d.run(); 
    return 0; 
} 


/*
int main(){
	int n;
	cout<<"Nhap so sinh vien: ";
	cin>>n;
	SV *a = new SV[n+10];
	
	VectorApp d;
	d.InsertElement();
	a[1].operator=(d.showFirst());
	for (int i=2;i<=n;i++){
		d.
		a[i].operator=(d.showLast());
	}
	cout<<"\n---------------------DANH SACH SINH VIEN LA---------------------\n";
	d.ListElement(); 
	 
	
} 
*/ 












