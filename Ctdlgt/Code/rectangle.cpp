#include<bits/stdc++.h>
using namespace std;

class CRectangle
{
    int width, height;
    public: 
    void set_values (int,int);
    int area (){
	    return (width*height);
	}
}; 
void CRectangle::set_values (int a, int b){
    width = a; height = b; 
}
int main () 
{
    CRectangle rect; 
    rect.set_values (3, 4);
    cout << "area: " << rect.area();   
	return 0; 
} 
