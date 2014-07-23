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
			case 7: return 0; 
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
	cout << "7. Exit" << endl; 
	int i; 
	cin >> i; 
	return i; 
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
		cout <<setw(10)<< ATC[n].nomer << setw(7)<< ATC[n].time<<setw(7)<<ATC[n].tarif<<endl;;
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
