//Roman Kozar - Laboratory 8
#include <iostream.h> 
#include <math.h> 
#include <iomanip.h> 

     typedef double ( *uf )( double, double, int & );  

		void tabl( double, double, double, double, uf ); 
			double y( double, double, int & ); 
			double s( double, double, int & );  

				int main() { 
					cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl; 
					tabl( -0.8, 0.9, -0.8, 0.0001, y );
					
					cout << endl;
					
						cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl ; 
						tabl( -0.8, 0.9, -0.8, 0.0001, s ); 
					return 0; 
				}  

			void tabl( double a, double b, double h, double eps, uf fun ) {  
				int k = 0;  
				double sum; 
					for( double x = a; x < b + h / 2; x += h ) {
						sum = fun( x, eps, k );        
						cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;   
					} 
			}  

			double y( double x, double eps, int &k ) { 
				return pow( x + 1, 1 / 4. ) - ( ( 4 - x ) / 4 ); 
			}
			
			double s( double x, double eps, int &k ) {  
				double a, c, sum;  
				sum = a = c = x;     
					k = 1; 
						while ( fabs( c ) > eps ) {  
							c = x / (4*k-3)*(4*k-1);  
							a *= -c;  
							sum += a; 
						k++;  
						} 
				return sum;
			 } 
