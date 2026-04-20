#include<iostream>
using namespace std;

void check0(int);

class div0:public exception{ // class จัดการตัวฐานเป็น 0
	public:
	virtual const char* what() const throw() {
            return "Divide by zero";
	}
};

class fail:public exception{
	public:
	virtual const char* what() const throw() {
		cin.clear();  
		cin.ignore(50,'\n');
		return "Accepting numbers only";
	}
}f; 

class range:public exception{
	public:
	virtual const char* what() const throw() {
		return "Value out of range";
	}
}r;

int main(){
	int x,y;
	double d;
	int a=1;
do{
	try{
		cout<<"Enter 2 numbers : ";
		cin>>x>>y;
		/*corated Exception Handling*/
		if(cin.fail()) throw f;
		if(abs(x)>1000 ||abs(y)>1000) throw r;
		check0(y);
		
		/* Normal Code */
		d=(double) x/y;
		cout<<"the result is "<<d<<endl;
		a=0;

		int i;	
		double * myarray;
		for( i=0;i<100000;i++){
			cout<<"Allocating memory... "<<i<<endl;
			myarray = new double[5000000000];
		}
	}

	/*catch(const char* error){
		cerr<<error<<endl;
	}
	catch(int e){
		switch(e){
			case 0   : cerr<<"Error divide by zero"<<endl; break;
			case 101 : cerr<<"Incorrect Numbers"<<endl; break; 
		}
		cin.clear();  //only first
		cin.ignore(50,'\n'); //clear all
	}*/

	catch(exception &e){
		cerr<<e.what()<<endl;
	}

}while(a);
	
	return 0;
}


void check0(int x){
	div0 e;
	if(x==0) throw(e);
}

