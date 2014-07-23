#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct ttree 
{
	int inf;  
    ttree *left; 
    ttree *right; 
} *proot;

 
ttree *add(ttree *proot, int inf)   
{ 
	ttree *nl, *pr, *ps;  
	bool b; 
	nl = new ttree; 
	nl->inf = inf; 
	nl->left  = NULL; 
	nl->right = NULL; 
    if (proot == NULL) return nl; 
    ps = proot; 
    while (ps != NULL) 
	{ 
		pr=ps; 
		b = (inf < ps->inf); 
		if (b) ps = ps->left; 
			else ps = ps->right; 
	} 
	if (b) pr->left = nl; 
		else pr->right = nl; 
	return proot; 
} 

void poisktree(ttree *p,int key, bool &b, int &inf)   
{ 
	if ((p != NULL) && (b != true)) 
	{ 
		if (p->inf !=key) 
		{ 
			poisktree(p->left, key,b,inf); 
			poisktree(p->right,key,b,inf); 
		} 
		else 
		{ 
			b=true; 
			inf=p->inf; 
        } 
	} 
} 

 
ttree *deltree(ttree *p)   
{ 
	if (p==NULL) return NULL; 
	deltree(p->left); 
	deltree(p->right);   
	delete(p);  
	p = NULL; 
	return NULL; 
} 

 
ttree *del(ttree *proot, int inf)   
{ 
	ttree *ps = proot, *pr = proot, *w, *v;
	while ((ps != NULL) && (ps->inf != inf)) 
	{ 
		pr = ps; 
		if (inf < ps->inf) ps = ps->left; 
			else ps = ps->right; 
	} 
  
	if (ps == NULL) return proot; 

	if ((ps->left == NULL) && (ps->right == NULL))  
	{ 
		if (ps == pr)
		{ 
			delete(ps); 
			return NULL; 
		} 
		if (pr->left == ps)	pr->left = NULL; 
			else pr->right = NULL; 
		delete(ps); 
		return proot; 
	} 
  
	if (ps->left == NULL) 
	{ 
		if (ps == pr)
		{ 
			ps = ps->right; 
			delete(pr); 
			return ps; 
		} 
 
		if (pr->left == ps) pr->left = ps->right; 
			else pr->right = ps->right; 
		delete(ps); 
		return proot; 
	} 

	if (ps->right == NULL) 
	{ 
		if (ps == pr)
		{ 
			ps = ps->left; 
			delete(pr); 
			return ps; 
		} 
 
		if (pr->left == ps) pr->left = ps->left; 
			else pr->right = ps->left; 
		delete(ps); 
		return proot; 
	} 
 
 
	w = ps->left; 
	if (w->right == NULL) w->right = ps->right;  
		else    
		{ 
			while (w->right != NULL) 
			{ 
				v = w; 
				w = w->right; 
			} 
			v->right = w->left; 
			w->left = ps->left; 
			w->right = ps->right; 
		} 
 
		if (ps == pr)
		{ 
			delete(ps); 
			return w; 
		} 
 
		if (pr->left == ps) pr->left = w; 
			else pr->right = w; 
		delete(ps); 
		return proot; 
}  

void wrtree_pr(ttree *p)   
{
	if (p==NULL) return; 
	cout << p->inf  << "  ";
	wrtree_pr(p->left); 
	wrtree_pr(p->right);    
} 

void wrtree_obr(ttree *p)   
{
	if (p==NULL) return; 	
	wrtree_obr(p->left); 
	wrtree_obr(p->right);   
	cout << p->inf  << "  "; 
} 

void wrtree_sim(ttree *p)   
{
	if (p==NULL) return; 
	wrtree_sim(p->left); 
	cout << p->inf  << "  "; 
	wrtree_sim(p->right);
} 

void count_uzl(ttree *p,int &k)
{
	if (!p) return;
	k++;
	count_uzl(p->right,k);
	count_uzl(p->left,k);
}

void zadanie()
{
	int k=0;
	count_uzl(proot->left,k);
	cout<<"v levoi vetvi "<<k<<" uzlov"<<endl;
}



int main()
{
	int v,n;
	cout<<"vvedite kolichesvo elementov "; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"element "<<i+1<<" :";
		cin>>v;
		proot=add(proot,v);
	}
	while(true)
	{
		cout<<"1. Dobavit"<<endl;
		cout<<"2. Udalit"<<endl;
		cout<<"3. Poisk"<<endl;
		cout<<"4. Print"<<endl;
		cout<<"5. Zadanie"<<endl;
		cout<<"6. Exit"<<endl;
		int k,x;
		cin>>k;
		switch(k)
		{
		case 1:
			cout<<"vvedi x ";
			cin>>x;
			proot=add(proot,x);
			break;
		case 2:
			cout<<"vvedi x ";
			cin>>x;
			proot=del(proot,x);
			break;
		case 3:
			{
				int inf;
				bool b=false;
				cout<<"vvedi x ";
				cin>>x;
				poisktree(proot,x,b,inf);
				if (b) cout<<"x="<<x<<" naiden"<<endl; 
					else cout<<"x="<<x<<" ne naiden"<<endl; 
			}
			break;
		case 4:
			wrtree_pr(proot);
			cout<<endl;
			wrtree_obr(proot);
			cout<<endl;
			wrtree_sim(proot);
			cout<<endl;
			break;
		case 5:
			zadanie();
			break;
		default:
			proot=deltree(proot);
			return 0;
		}
		getch();
		system("cls");
	}
}
