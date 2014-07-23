#include <iostream.h>  
#include <stdio.h>  
#include <conio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <iomanip.h> 
FILE *fl; 
typedef struct  
{ 
	int nomer; 
    int time; 
	int tarif;
} razgovor; 
 
razgovor ATC[30]; 
char name[20];      
int n=0;     
int menu();       
void nnf();       
void newf();  
void spisok();
void opf();   
void resc();  
void resf();
void s_qs();
void s_vs();
void show();
void p_lin();
void p_int();
int main()  
{  
	while (true)  
	{ 
		switch (menu()) 
		{ 
			case 1: nnf();    break; 
			case 2: newf();   break; 
			case 3: spisok(); break; 
			case 4: opf();    break; 
			case 5: resc();   break; 
			case 6: resf();   break; 
			case 7: s_qs();   break;
			case 8: s_vs();   break;
			case 9: show();   break;
			case 10: p_lin();   break; 
			case 11: p_int();   break; 
			case 12: return 0;  
			default: "Viberite pravilno!"; 
		} 
		puts("Press any key to continue");  
		getch();      system("cls");  
	}  
}  
 
int menu() 
{ 
	cout << "VIBERITE:" << endl; 
	cout << "1. Vvod file name" << endl; 
	cout << "2. New file" << endl; 
	cout << "3. Vvesti spisok" << endl; 
	cout << "4. Open file" << endl; 
	cout << "5. Vivesti result" << endl; 
	cout << "6. Vivesti v fail" << endl; 
	cout << "7. QuickSort" << endl; 
	cout << "8. Vstavkoi" << endl; 
	cout << "9. Show" << endl; 
	cout << "10. Poisk lin" << endl;
	cout << "11. Poisk interp." << endl;
	cout << "12. Exit" << endl;  
	int i; 
	cin >> i; 
	return i; 
} 

void s_vs() 
{
	int i,j; 
	razgovor t;
	for(i=1; i<n; i++) 
	{
		t=ATC[i]; 
		for(j=i-1; j>=0 && t.nomer<ATC[j].nomer; j--) ATC[j+1]=ATC[j];  
        ATC[j+1] = t; 
	} 	 
} 

void s_qs() 
{
	struct  
	{
		int l;  
		int r;  
	} stack[20]; 
  
	int i,j, left, right, s=0; 
	razgovor t;
	double x;
	stack[s].l=0; stack[s].r=n-1; 
	while (s != -1) 
	{ 
		left=stack[s].l; right=stack[s].r;  
		s--; 
		while (left < right) 
		{ 
			i=left; 
			j=right; 
			x=ATC[(left+right)/2].nomer; 
			while (i <= j) 
			{ 
				while (ATC[i].nomer < x) i++; 
				while (ATC[j].nomer > x) j--; 
				if (i<=j) 
				{ 
					t=ATC[i];  
					ATC[i]=ATC[j];  
					ATC[j]=t; 
					i++;  j--; 
				} 
			} 
			if ((j-left)<(right-i))  
			{ 
				if (i<right) 
				{
					s++;  
					stack[s].l=i;  
					stack[s].r=right; 
				} 
				right=j; 
			} 
			else 
			{ 
				if (left<j) 
				{
					s++;  
					stack[s].l=left;  
					stack[s].r=j; 
				} 
				left=i; 
			} 
		} 
	} 
} 

void show()
{
	cout<<setw(10)<<"nomer"<<setw(7)<<"vremya"<<setw(7)<<"tarif"<<endl;
	for(int i=0;i<n;i++)
		cout <<setw(10)<< ATC[i].nomer << setw(7)<< ATC[i].time<<setw(7)<<ATC[i].tarif<<endl;

}  
void nnf() 
{ 
	cout << "Vvedite file name" << endl; 
	cin >> name; 
} 
 
void newf()
{ 
	if ((fl = fopen(name,"wb"))==NULL) 
	{ 
		cout << "Oshibka pri sozdanii"<<endl; 
		exit(1); 
	} 
	cout << "OK" << endl; 
	fclose(fl); 
} 
 
void spisok()
{ 
	if ((fl = fopen(name,"rb+"))==NULL) 
	{ 
		cout << "Oshibka pri sozdanii"<<endl; 
		exit(1); 
	} 
 
	cout << "Vvedite kolichestvo razgovorov " << endl; 
	cin >> n; 
 
	for (int i=0; i<n; i++) 
	{ 
		cout << "Vvedite nomer telefona: "; 
		cin >> ATC[i].nomer; 
		cout << "Vvedite vremya razgovora: "; 
		cin >> ATC[i].time; 
		cout << "Vvedite tarif: "; 
		cin >> ATC[i].tarif;
		fwrite( &ATC[i], sizeof(razgovor), 1, fl ); 
	} 
	fclose(fl); 
} 
 
void opf()
{ 
	if ((fl = fopen(name,"rb"))==NULL) 
	{
		cout << "Oshibka pri otkritii"<<endl; 
		exit(1); 
	} 
 
	n=0; razgovor t; 
	cout<<setw(10)<<"nomer"<<setw(7)<<"vremya"<<setw(7)<<"tarif"<<endl;
	while(true) 
	{ 
		int  nwrt = fread( &t, sizeof(razgovor), 1, fl ); 
		if (nwrt!=1) break; 
		ATC[n]=t; 
		cout <<setw(10)<< ATC[n].nomer << setw(7)<< ATC[n].time<<setw(7)<<ATC[n].tarif<<endl;
		n++; 
	} 
	fclose(fl); 
} 
 
void resc()
{ 
	cout<<"vvedi nomer abonenta"<<endl;
	int nom;
	cin>>nom;
	for (int i=0; i<n; i++) 
	if (ATC[i].nomer==nom)
	{		
		cout<<"nado oplatit: "<<ATC[i].tarif*ATC[i].time<<endl;

	}
} 
 
void resf()
{ 
	char namet[30]; 
	FILE *ft; 
	cout << "Vvedite imya faila" << endl; 
	cin >> namet; 
	if ((ft = fopen(namet,"w"))==NULL) 
	{ 
		cout << "Oshibka pri sozdanii "<<endl; 
		exit(1); 
	} 
	char s[80],c[30]; 
	
	cout<<"vvedi nomer abonenta"<<endl;
	int nom;
	cin>>nom;
	for (int i=0; i<n; i++) 
	if (ATC[i].nomer==nom)
	{
		strcpy(s, "nado oplatit \n");
		itoa(ATC[i].tarif*ATC[i].time,c,10);
		strcat(s, " ");
		strcat(s, c);
		strcat(s, "\n");
		fputs(s, ft); 
    } 
	fclose(ft); 
} 

void p_lin() 
{ 
	int k=-1;
	double x=21603;
	for(int i=0; i < n; i++)  
        if (ATC[i].nomer==x) 
		{
			k=i;
			break;
		} 
	if (k==-1)
	{
		cout<<"abonent ne naiden"<<endl;
	}
	else
	{		
		cout<<setw(10)<<"nomer"<<setw(7)<<"vremya"<<setw(7)<<"tarif"<<endl;	
		cout <<setw(10)<< ATC[k].nomer << setw(7)<< ATC[k].time<<setw(7)<<ATC[k].tarif<<endl;
	}
} 

void p_int()
{
	int i=0, j=n-1, m,k=-1;
	double x=21603;
	while(i<j) 
	{ 
		if (ATC[i].nomer==ATC[j].nomer)
		if (ATC[i].nomer==x) 
		{
			k=i;
			break;
		} 
		m=i+(j-i)*(x-ATC[i].nomer)/(ATC[j].nomer-ATC[i].nomer); 
 
		if (ATC[m].nomer==x) 
		{
			k=m;
			break;
		}
		else  
		if (x > ATC[m].nomer) i=m+1; else j=m-1; 
	} 
	if (k==-1)
	{
		cout<<"abonent ne naiden"<<endl;
	}
	else
	{
		cout<<setw(10)<<"nomer"<<setw(7)<<"vremya"<<setw(7)<<"tarif"<<endl;	
		cout <<setw(10)<< ATC[k].nomer << setw(7)<< ATC[k].time<<setw(7)<<ATC[k].tarif<<endl;
	}
	
} 
