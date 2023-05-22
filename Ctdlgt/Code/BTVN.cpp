#include<bits/stdc++.h>
using namespace std;
int m; 
class SV{
private:
    string masv;
    string hoten; 
	int ngay; 
	int thang;
	int namsinh; 
	string gioi;
	string que; 
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
	return is; 	 
}
ostream & operator << (ostream &os,SV d){
	os<<setw(10)<<d.masv<<setw(15)<<d.hoten<<setw(15)<<d.ngay<<setw(15)<<d.thang<<setw(15)<<d.namsinh<<setw(15)<<d.gioi<<setw(15)<<d.que<<endl; 	
	return os; 
}
template <class SV>
class Node{
private:
    SV elem;
	Node *next;
public:
    Node(){
    	
	}
    Node(SV x){
    	elem = x;
		next = NULL; 
	} 
	Node *getNext();                //ham tra ve node ma next tro den 
	void setNext(Node<SV>*);        //dat node ma next tro vao la doi cua phuong thuc 
	SV &getElem();	                //ham tra ve phan tu luu trong node 
	void setElem(SV x);	            //thay the phan tu luu trong node = phan tu moi 
}; 
template <class SV>
Node<SV> *Node<SV>::getNext(){
	return next; 
} 
template <class SV>
void Node<SV>::setNext(Node<SV> *p){
	next = p; 
} 
template <class SV>
SV& Node<SV>::getElem(){
	return elem; 
} 
template <class SV>
void Node<SV>::setElem(SV x){
	elem = x; 
} 

template <class SV>
class SingleList{
private:
    Node<SV> *header;       //con tro vao dau danh sach 
    Node<SV> *trailer;      //con tro vao phan tu cuoi cua danh sach  
    long n;                 //so phan tu cua danh sach 
public:
	SingleList();
	SingleList(int m);
	long size();
	bool isEmpty();
	Node<SV>* first();                       //tra lai dia chi do con tro header tro den 
	Node<SV>* last();                        //tra lai dia chi do con tro trailer tro den 
	void replace(Node<SV> *p,SV e);          //thay the phan tu luu trong p = phan tu e va tra lai dia chi p 
	Node<SV>* insertFirst(SV e);             //chen them 1 node vao dau danh sach 
	Node<SV>* insertLast(SV e);              //chen them 1 node vao cuoi danh sach 
	void remove(Node<SV> *p);                //loai bo node do con tro p tro toi 
	Node<SV>* getNode(int ); 		
}; 
template <class SV>
SingleList<SV>::SingleList(int m){
    header = NULL; 
    trailer = NULL; 
    n = m; 
} 
template <class SV>
long SingleList<SV>::size(){
	return n; 
} 
template <class SV>
bool SingleList<SV>::isEmpty(){
	return n==0; 
} 
template <class SV>
Node<SV>* SingleList<SV>::first(){
	return header; 
} 
template <class SV>
Node<SV>* SingleList<SV>::last(){
	return trailer; 
} 
template <class SV>
void SingleList<SV>::replace(Node<SV>* p,SV e){
	p -> setElem(e); 
} 
template <class SV>
Node<SV>* SingleList<SV>::insertFirst(SV e){
	Node<SV>* q;
	q = new Node<SV>;
	q -> setElem(e);
	
	if(isEmpty()){
		header = q;
		trailer = q;
	}
	else{
		q -> setNext(header);
		header = q;
	}
	n++;
	return q;
}
template <class SV>
Node<SV>* SingleList<SV>::insertLast(SV e){
	Node<SV>* q;
	q = new Node<SV>;
	q -> setElem(e);
	
	if(isEmpty()){
		header = q;
		trailer = q;
	}
	else{
		trailer -> setNext(q);
		trailer = q;
	}
	n++;
	return q;
}
template <class SV>
void SingleList<SV>::remove(Node<SV>* p){
	Node<SV> *q;
	if(p==header){
		if(size()==1){
			header = NULL;
			trailer =NULL;
		}
		else
			header = header -> getNext();
	}
	else{
		q = header;
		
		while(q -> getNext() != p)           //vong lap tim vi tri node truoc node p 
		    q = q -> getNext();
		if(q!=NULL){                         //tim node can xoa 
			if(p!=trailer)
				q -> setNext(p -> getNext());
			else
			    trailer = q; 
		}    
	}
	n--;
}
template <class SV>
Node<SV>* SingleList<SV>::getNode(int i){
	if(i < 0 || isEmpty())
	    return NULL;
	Node<SV> *p;
	int dem=0;
	p = header;
	while(dem < i && p != NULL){
		dem++;
		p = p -> getNext();
	}   
	return p;
}
template <class SV>
class DisplayList{
private:
    SingleList<SV>* show;
	Node<SV> *poiter;
public:
    DisplayList(SingleList<SV>* list){
    	show = list;
    	poiter = show -> first();
	}		
	void reset(){
		poiter = show -> first();
	}
	Node<SV> *getNodeFirst(){           //ham lay node dau tien 
		poiter = show -> first();  
		return poiter; 
	} 
	Node<SV> *getNodeLast(){           //ham lay node cuoi 
		poiter = show -> last();  
		return poiter; 
	}
	
	bool getNext(){             
		return poiter!= NULL;         //tro den cuoi danh sach 
	}
	
	SV Next(){
		SV s;
		s = poiter -> getElem();
		poiter = poiter -> getNext();
		return s;
	}
};

 

class MoveSingleList{
private:
    SingleList<SV> *list;
public:
    MoveSingleList();		
	void insertFirst();		
	void insertLast();
	void remove(){
		Node<SV> *p; 
			cout<<"Xoa sinh vien o vi tri thu may:"; 
			cin>>m; 
			p = list->getNode(m-1);// ham lay node thu m-1
			list->remove(p); 
	}				
	void replace(){
		DisplayList<SV> q(list); 
			SV x; 
			Node<SV> *p; 
			cout<<"Nhap thong tin sinh vien can thay\n"; 
			cin>>x; 
			cout<<"Thay the sinh vien thu may\n";
			cin>>m; 
			p = list->getNode(m-1); 
			list->replace(p,x); 
	}
	
	void showDS(){
		cout<<setw(10)<<"MSV"<<setw(15)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(15)<<"Thang sinh"<<setw(15)<<"Nam sinh"<<setw(15)<<"Gioi tinh"<<setw(15)<<"Que quan"<<endl; 	
		DisplayList<SV> p(list); 
			while(p.getNext()) {// tro den NULL thi dung
				m++;
				cout<<p.Next(); // lay het cac node hay la cac sinh vien da them vao
			}
	}
	SV showFirst(){
		DisplayList<SV> p(list); 
		cout<<"Danh sach sinh vien sau khi them vao dau la: \n"; 
		while(p.getNodeFirst()) // hien thi node dau la sinh vien thu nhat
		return p.Next();
	}
	SV showLast(){
		DisplayList<SV> p(list); 
		cout<<"Danh sach sinh vien sau khi them vao cuoi la: \n"; 
		while(p.getNodeLast()) // hien thi node cuoi la sinh vien thu nhat
		return p.Next(); 
	}
}; 
MoveSingleList::MoveSingleList(){
	list = new SingleList<SV> (m); 
}		
void MoveSingleList::insertFirst(){
	SV x;
	cout<<"Nhap thong tin sinh vien: \n";
	cin>>x;
	list->insertFirst(x);
}		
void MoveSingleList::insertLast(){
	SV x;
	cout<<"Nhap thong tin sinh vien: \n";
	cin>>x;
	list->insertLast(x);
}	

int main()
{
	int n;
	cout<<"Nhap so sinh vien:";
	cin>>n;
	SV *a = new SV[n+10];

	MoveSingleList d;
	
	d.insertFirst();
	a[1].operator=(d.showFirst());
	for (int i=2;i<=n;i++){
		d.insertLast();
		a[i].operator=(d.showLast());
	}
	cout<<"\n---------------------DANH SACH SINH VIEN LA---------------------\n";
	d.showDS();
	
//	ham them sinh vien vao cuoi
	d.insertLast();
	++n;
	a[n].operator=(d.showLast());
	cout<<"\n---------------------DANH SACH SINH VIEN SAU KHI THEM VAO CUOI LA---------------------\n";
	d.showDS();
	
// ham them sinh vien vao cuoi
	d.insertFirst();
	a[0].operator=(d.showFirst());
	cout<<"\n---------------------DANH SACH SINH VIEN SAU KHI THEM VAO DAU LA---------------------\n";
	d.showDS();

// ham xoa sinh vien
	d.remove();
	cout<<"\n---------------------DANH SACH SINH VIEN SAU KHI XOA LA---------------------\n";
	d.showDS();
	
// ham thay the sinh vien 
	d.replace();
	cout<<"\n---------------------DANH SACH SINH VIEN SAU KHI THAY THE---------------------\n";
	d.showDS(); 
}

