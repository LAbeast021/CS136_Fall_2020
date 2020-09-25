//LAB 2 HESAMPOUR, KIARASH T TH
#include <iostream>
using namespace std;
double power(double b, int e);
int sumofsquares1(int n1, int n0);
int sumofsquares2(int n2);
int main()
{
double b, pow;
int choose,e,n1,n2;
cout<<"1.To find power\n2.To find sum of squares of numbers i.e.,(1+ 2^2 + 3^3 +....n^n)"<<endl;
cout<<"3.To find sum of squares of numbers i.e.,(n^n + ... 3^3 + 2^2 +1)"<<endl;
cout<<"choose 1 or 2 or 3: ";
cin>>choose;  
do{
if(choose==1)
{
   cout<<"Enter base: ";
   cin>>b;
   cout<<"Enter exponent: ";
   cin>>e;
   pow = power(b, e);
   cout<<b<<"^"<<e<<" = "<<pow<<endl;
   }
   else if(choose==2)
   {
       cout<<"Enter number of terms: ";
       cin>>n1;
       cout<<"sum of squares= "<<sumofsquares1(n1,1)<<endl;
      
   }
   else if(choose==3)
   {
       cout<<"Enter number of terms: ";
       cin>>n2;
       cout<<"sum of squares= "<<sumofsquares2(n2)<<endl;
   }
   cout<<"1.To find power\n2.To find sum of squares of numbers i.e.,(1+ 2^2 + 3^3 +....n^n)"<<endl;
cout<<"3.To find sum of squares of numbers i.e.,(n^n + ... 3^3 + 2^2 +1)"<<endl;
   cout<<"Enter 1 or 2 or 3: ";
   cin>>choose;
   }while(choose==1 || choose==2 || choose==3);
      
}
double power(double b, int e)//finding power for both +ve and -ve numbers
{
if(e==0)
return 1;
else if(e>0)
return b*power(b,e-1);//for +ve exponent
else
return 1/power(b,-e);//for -ve exponent
}
int sumofsquares1(int n1, int n0)//this is for (1+ 2^2 + 3^3 +....n^n)
{
   if(n0<n1)
       return n0*n0+sumofsquares1(n1,n0+1);
   else if(n0==n1)
       return n0*n0;
}
int sumofsquares2(int n2) //this is for (n^n + ... 3^3 + 2^2 +1)
{
   if(n2>1)
       return n2*n2+sumofsquares2(n2-1);
   else if(n2==1)
       return 1;
}