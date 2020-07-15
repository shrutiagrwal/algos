#include<bits/stdc++.h>
using namespace std;
int karatsurba(int x,int y,int n)
{
	if(n==1)
	{
	  return x*y;	
	}
	else
	{
		int a,b,c,d,z=pow(10,n/2);
		 a=x/z;
	     b=x%z;
	     c=y/z;
	     d=y%z;
	     
		pow(10,n)*karatsurba(a,c,n/2)*(1-pow(10,.5))+karatsurba(b,d,n/2)*(1-pow(10,n/2))+karatsurba(a+b,c+d,n/2)*pow(10,n/2);
	}
}
int main()
{
	int x=1234,y=5678,n=4;
	cout<<karatsurba(x,y,n);
	
}
