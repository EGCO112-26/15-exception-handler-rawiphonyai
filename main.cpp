#include<iostream>
using namespace std;

void check0(int);

int main(){
	int x,y,a;
	double d;
do{
	a=1;
	try{
		int i;	
		double * myarray;
		for( i=0;i<100000;i++){
			cout<<"Allocating my array number "<<i<<endl;
			myarray = new double[500000000];
		}
		cout<<"Enter 2 numbers : ";
		cin>>x>>y;
		/*corated Exception Handling*/
		if(cin.fail()) throw 101;
		if(abs(x)>1000 ||abs(y)>1000) throw("Value out of range");
		check0(y);
		//if (y==0) throw "Error divide by zero";
		a=0;
		/* Normal Code */
		d=(double) x/y;
		cout<<"the result is "<<d<<endl;

	}

	catch(const char* error){
		cerr<<error<<endl;
	}
	catch(int e){
		switch(e){
			case 0 : cerr<<"Error divide by zero"<<endl; break;
			case 101 : cerr<<"Incorrect Numbers"<<endl; break; 
		}
		cin.clear();  //only first
		cin.ignore(50,'\n'); //clear all
	}
	catch(...){
		cerr<<"Memory Leak!!!";
		a=1;
	}

}while(a);
	
	return 0;
}


void check0(int x){
	if(x==0) throw(x);

}
