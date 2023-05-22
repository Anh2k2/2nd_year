#include<iostream>

//#include<stack>
//#include "sllStack.cpp"
#include "arrayStack.cpp"

#ifndef __KyPhapBaLan__cpp
#define __KyPhapBaLan__cpp

using namespace std;

class KyPhapBaLan{
	private:
		// khai bao 2 bien ky tu. Bien "in" de lay du lieu dau vao, bien "out" de luu du lieu dau ra
		string in, out;
		
	public:
		
		KyPhapBaLan(string x) // phuong thuc khoi tao KyPhapBaLan de gan du lieu cho bien "in"
		{
			this->in = x; 				//1
			//T(n) = 1 => O(1)
		}
		
		int UuTien(char x) // ham UuTien de xet do uu tien cua cac phep toan
		{
			if(x == '^'){ 				//1
				return 4; 				//1
			}
			if(x == '*' || x == '/'){ 	//3
				return 3; 				//1
			}
			if(x == '+' || x == '-'){ 	//3
				return 2;				//1
			}
			if(x == '(' || x == ')'){ 	//3
				return 1;				//1
			}
			// 2 <= T(n) <= 11 => O(1)
		}
				
		void HauTo() // phuong thuc HauTo de chuyen cac bieu thuc tu trung to sang hau to
		{
			Stack<char> s; 									//1
			for(auto i:in){ 								//n
				if((i < '0' || i > '9') && i != '+' && i != '-' && i != '*' && i != '/' 
					&& i != '(' && i != ')' && i != '^'){ 	//17n
					cout << "Error."; 						//1
					exit(0);								//1
					// 15 + 1 + 1  <= T(n) <= 17n
				}
				if('0' <= i && i <= '9'){ 					//3n
					out.push_back(i);						//n
				//T(n) = 4n
				} else {
					out.push_back(' ');						//n
					if(i == '('){ 							//n
						s.push(i); 							//n
					} else {
						if(i == ')'){ 						//n
							while(s.top() != '('){ 			//n*(n+2)
								out.push_back(s.top());		//2*n*n
								s.pop();					//n*n
							}
							s.pop();						//n
						//T(n) = 4*n*n + 4n
						} else {
							while(!s.empty() && UuTien(i) <= UuTien(s.top())){  //n*(n+7)
								out.push_back(s.top());							//2*n*n
								s.pop();										//n*n
								out.push_back(' ');								//n*n
							}
							s.push(i);											//n
						//T(n) = 5*n*n + 8n
						}
					}
				}
			}
			//T(n) = 5*n*n + 8n + n + n + n + 3n + 17n + n + 1
			//	   = 5*n*n+26n+1
			out.push_back(' ');			//1
			while(!s.empty()){			//n+2
				out.push_back(s.top()); //2n
				out.push_back(' ');		//n
				s.pop();				//n
			//T(n) = 5n + 3
			}
		//=> 17 <= T(n) <= 5*n*n+31n+4 => O(n^2)
		}
		string getOut() // phuong thuc getOut dung de lay ra bieu thuc hau to
		{
			return out;//1
			//T(n) = 1 => O(1)
		}
};
#endif
