#include <iostream.h>
struct tochd  
{
	int inf;  
	tochd *left; 
	tochd *rigth; 
}; 

void newochd(tochd **sl, tochd **sr)  
{
	*sl=new tochd; 
	*sr=new tochd; 
	(*sl)->left = NULL; 
	(*sl)->rigth = *sr; 
	(*sr)->left = *sl; 
	(*sr)->rigth = NULL; 	
} 

void delochd(tochd **sl, tochd **sr)  
{
	tochd *t;
	while( (*sl)->rigth != (*sr) )
	{
		t=(*sl)->rigth->rigth;
		delete (*sl)->rigth;
		(*sl)->rigth=t;
	}
	delete *sl;  *sl = NULL;  
	delete *sr;  *sr = NULL; 
}

void add_l(tochd *sp, int inf)  
{
	tochd *spt=new tochd; 
	spt->inf = inf; 
    spt->left = sp->left; 
	spt->rigth = sp; 
	spt->left->rigth = spt; 
	sp->left = spt;   
} 

void add_r(tochd *sp, int inf)   
{
	tochd *spt=new tochd; 
	spt->inf = inf; 
    spt->left = sp; 
	spt->rigth = sp->rigth; 
	sp->rigth = spt; 
	spt->rigth->left = spt;   
} 

void showochd(tochd *sl,tochd *sr)
{
	tochd *p=sl;
	while( (p=p->rigth) != sr)
	{
		cout<<p->inf<<" ";
	}
	cout<<endl;
}

int read_del(tochd *sp)  
{
	int inf= sp->inf; 
	sp->left->rigth = sp->rigth;        
	sp->rigth->left = sp->left; 
	delete sp;  
	return inf; 
} 
void div2Ochd(tochd *sl, tochd *sr,tochd **slL, tochd **srL,tochd **slR, tochd **srR) 
{ 
	newochd(slL,srL); 
	newochd(slR,srR); 
    tochd *spt = sl->rigth; 
	while(spt != sr)  
	{
		add_l(*srL, read_del(spt)); 
		spt = sl->rigth; 
		if (spt != sr)  
		{ 
			add_l(*srR, read_del(spt)); 
			spt = sl->rigth; 
		} 
	} 
	delete sl;  
	delete sr; 
} 

void slip(tochd **sl, tochd **sr,tochd *slL, tochd *srL,tochd *slR, tochd *srR) 
{ 
	newochd(sl,sr); 
	tochd *sptL = slL->rigth; 
	tochd *sptR = slR->rigth; 
	while ((sptL != srL) && (sptR != srR))  
	{ 
	    if (sptL->inf < sptR->inf)  
		{ 
			add_l(*sr, read_del(sptL)); 
			sptL = slL->rigth; 
		} 
		else 
		{ 
			add_l(*sr, read_del(sptR)); 
			sptR = slR->rigth; 
		} 
	}
	while (sptL != srL) 
	{ 
		add_l(*sr, read_del(sptL)); 
		sptL = slL->rigth; 
	} 
    delete slL; delete srL; 
 
	while (sptR != srR) 
	{ 
		add_l(*sr, read_del(sptR)); 
		sptR = slR->rigth; 
	} 
    delete slR; delete srR; 
} 

void sort(tochd **sl, tochd **sr) 
{
	tochd *slL, *srL,*slR, *srR; 
    if ((*sl)->rigth->rigth == *sr) return;  
	div2Ochd(*sl,*sr,&slL,&srL,&slR,&srR); 
	sort(&slL,&srL); 
	sort(&slR,&srR);       
    slip(sl,sr,slL,srL,slR,srR); 
} 

void poisk(tochd *sl,tochd *sr,int x)
{
	tochd *p=sl;
	int n=0;
	while( (p=p->rigth) != sr )
	{
		n++;
		if (p->inf == x) break;
	}
	if (p->inf == x) cout<<"element naiden: "<<n<<endl;
		else cout<<"takogo elementa net"<<endl;
	
}


int main()
{
	int n,k,nvar=14;

	cout<<"vvedi n: ";
	cin>>n;

	tochd *sl,*sr;
	newochd(&sl,&sr);

	for(int i=0;i<n;i++)
	{
		cin>>k;
		add_r(sl,k);
	}
	cout<<"ochered:"<<endl;
	showochd(sl,sr);
	
	cout<<"poisk "<<nvar<<endl;
	poisk(sl,sr,12);

	cout<<"obmen pervii i max"<<endl;
	tochd *max,*p,*f;
	p=max=sl->rigth;
	f=sl->rigth;
	while( (p=p->rigth) != sr )
	{
		if (p->inf > max->inf) max=p;
	}
	cout<<"max="<<max->inf<<endl;
	if (max !=f )
	{	
		if (f->rigth == max)
		{
			tochd *l,*r;
			l=f->left;
			r=max->rigth;

			l->rigth=max;
			r->left=f;

			max->left=l;
			max->rigth=f;

			f->rigth=r;
			f->left=max;
			
		}
		else
		{
			tochd *fl,*fr,*maxl,*maxr;
			fl=f->left;
			fr=f->rigth;
			maxl=max->left;
			maxr=max->rigth;

			f->left=maxl;
			f->rigth=maxr;

			max->left=fl;
			max->rigth=fr;

			fl->rigth=max;
			fr->left=max;

			maxl->rigth=f;
			maxr->left=f;
		}
	}

	showochd(sl,sr);

	cout<<"posle sortirovki:"<<endl;
	sort(&sl,&sr);
	showochd(sl,sr);

	delochd(&sl,&sr);
	return 0;
} 
