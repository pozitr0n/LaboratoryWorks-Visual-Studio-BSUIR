#include <iostream.h>

double s(int k)
{
	double a,r;
	r=a=1;
	for(int i=2;i<=k;i++)
	{
		a/=i;
		r+=a;
	}
	return r;
	
}


double s_rec(int k,int z,double f)
{
	if (k==z) return 1;
	z+=1;
	f/=z;
	return f+s_rec(k,z,f);
}


int main()
{
	int k;
	cout<<"vvedite k"<<endl;
	cin>>k;

	cout<<"ne rekursivno "<<s(k)<<endl;
	cout<<"rekursivno "<<s_rec(k,1,1)<<endl;
	return 0;
}
