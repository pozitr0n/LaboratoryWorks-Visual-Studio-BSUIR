#include <iostream.h>
struct toch
{
	int inf;
	toch *a;
};

void add(toch **sp,toch **spk, int inf)   
{
	toch *spt=new toch; 
	spt->inf = inf; 
	spt->a = NULL; 
	if (*spk == NULL) 
		*sp=*spk=spt; 
    else
	{
		(*spk)->a = spt;
		*spk = spt;   
	} 	
} 


void deloch(toch **sp, toch **spk)  
{
	toch *spt; 
	while(*sp != NULL) 
	{ 
		spt = *sp; 
		*sp = (*sp)->a; 
		delete spt;
	} 
	*spk=NULL; 
} 

void showoch(toch *sp,toch *spk)
{
	while(sp)
	{
		cout<<sp->inf<<" ";
		sp=sp->a;
	}
	cout<<endl;
}


int main()
{
	toch *sp,*spk;
	sp=spk=NULL;
	int n,k; 
	cout<<"vvedi n: ";
	cin>>n;	
	if (n<1) return 0;
	double sredn=0;
	for( int i=0;i<n;i++)
	{
		cin>>k;	
		add(&sp,&spk,k);
		sredn+=k;
	}
	sredn/=n;
	showoch(sp,spk);
	cout<<"srednee = "<<sredn<<endl;
	toch *p,*t;

	if (sp==spk) 
	{
		cout<<"vvedi bolshe chisel"<<endl;
		return 0;
	}
	
	p=sp;
	while(p)
	{
		if (p->inf < sredn)
		{
			if (p==sp)
			{
				sp=sp->a;
				delete p;
				p=sp;
			}
			else
			{
				t->a=p->a;
				delete p;
				p=t->a;
			}
		}
		else 
		{
			t=p;
			p=p->a;
		}
	}
	

	showoch(sp,spk);
	deloch(&sp,&spk);
	return 0;
}
