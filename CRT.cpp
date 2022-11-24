#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int gcd( int a, int b) {
  	int c = 0;
  	while ( b != 0)
	{ 
		c = a % b;
    	a = b;
    	b = c;
    }
  	return a;
}

int inverse( int a, int b) {
   int pa[100],q[100],x[100];
   int n,i,j;
   
   pa[0]=b; 
   pa[1]=a; 
   
   i=0;
   
   while(pa[i]%pa[i+1]!=0)   //compute the pa and the q column
     {
       pa[i+2]=pa[i]%pa[i+1];
       q[i+1]=pa[i]/pa[i+1];
       i++;
     }
   
   
   n=i+1; 
   x[n]=0; 
   x[n-1]=1;
   for(j=n-2;j>=0;j--)  
	   x[j]=x[j+1]*q[j+1] + x[j+2];//compute x column
    
   
   if((x[1]*pa[0])>(x[0]*pa[1])) 	
	{
		x[0]=b-x[0];
	}

   return x[0];

}

int main() {
	int k=3;
	int *a=new int[k];
	int *mi=new int[k];
	int *Mi=new int[k];
	int M;
	int *yi=new int[k];

	for (int i=0; i<k; i++) {
	cout<<"value of a"<<i+1<<":";
	cin>>a[i];
	cout<<"value of m"<<i+1<<":";
	cin>>mi[i];
	}

//  check for relatively prime
	for(int i=0; i<k; i++) {
		for(int j=i+1; j<k; j++)
			if (1 != gcd( mi[i], mi[j]))
				cout<<"moduli are not relatively prime";
}
   
//  equations
	M=1;
	for(int i=0; i<k; i++) {
		M = M*mi[i];     //7*3*5=105
	}

	for(int i=0; i<k; i++) {
		Mi[i] = M / mi[i]; //Mi[0]=15, Mi[1]=35, Mi[2]=21
	}

	for(int i=0; i<k; i++) {
		yi[i] = inverse(Mi[i],mi[i]); //yi[0]=1, yi[1]=2, yi[2]=1 
	}

	int x=0;
	for(int i=0; i<k; i++) {
	 	x = x + ( a[i]*Mi[i]*yi[i]); //=2*15*1 + 2*35*2 + 3*21*1
	}

	int res = x % M; //233%105=23
	//  print result

	printf("\n\nx = %d = %d (mod %d)\n", x, res, M);
	//  ---------------------------------------------------------
}