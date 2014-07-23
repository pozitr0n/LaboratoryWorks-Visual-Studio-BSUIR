#include <cstdlib> 
#include <iostream> 
 
using namespace std; 
 
struct tstk  
{
        int inf;  
        tstk *a;
} ;  
        
        tstk *DelStackAll(tstk *sp)  
        { tstk *spt; int inf;  
        while(sp != NULL) {  
                spt = sp;  
                inf= sp->inf;  
                cout << inf << endl;  
                sp = sp->a;  
                delete spt; }  
        return NULL; }  
        
        tstk *AddStack(tstk *sp, int inf)  
        { tstk *spt=new tstk;  
        spt->inf = inf;  
        spt->a = sp;  
        return spt; }  
        
        tstk *ReadStackD(tstk *sp, int &inf)  
        { 
                if (sp == NULL) return NULL;  
                tstk *spt = sp;  
                inf= sp->inf;  
                sp = sp->a;  
                delete spt;  
                return sp; }  
        int main() 
        { 
                tstk*sp=NULL; 
                int i; 
                for(i=-50;i<=50;i++)
                {sp=AddStack(sp, ( i % 3 == 0 ) );
                cout<<i<<endl;
                }
                tstk*sp2=NULL;
                while ( sp )
                {
                    int inf;
                    sp = ReadStackD( sp, inf );
                    if ( inf > 0 ) sp2 = AddStack( sp2, inf );
                }
                sp2 = DelStackAll( sp2 );
  
                system("PAUSE"); 
                return EXIT_SUCCESS; 
} 
