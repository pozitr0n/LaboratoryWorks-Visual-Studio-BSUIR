//Roman Kozar - Laboratory 3

//connect all core libraries
#include <iomanip.h>
#include <iostream.h>

//mathematic-library
#include <math.h> 

	int main() { 
		
		//Initialization of global variables
		double initialStep, finalStep, increment, abscissa, function, amount, partRecurrent, partUnrecurrent; 
		int number, count;

			//Stream I / O data
			cout << "Input initialStep: ";
				cin >> initialStep;

			cout << "Vvedite finalStep: ";
				cin >> finalStep;
				
			cout <<"Vvedite number: ";
				cin >> number;

			//specify the amount equal b-a/10
			increment = ( finalStep - initialStep ) / 10;

			//the first term is equal to the initial value
			abscissa = initialStep;

				do {

					//sum is equal to zero
					amount = 0;
					partRecurrent = partUnrecurrent = 1;
					
						for ( count = 1; count <= number; count++ ) {
							
							//introduce variables for the separation of recurrent and recurrent parts
							partUnrecurrent = pow( count, 2 );
							partRecurrent *= abscissa / ( 2 * count * ( 2 * count + 1 ) );

							//then multiply the two parts
							amount += partRecurrent * partUnrecurrent; 
						} 
					
					//enter the series of expansions
					function = 1 / 4. * ( ( abscissa + 1 ) / sqrt( abscissa ) * sinh( sqrt( abscissa ) ) - cosh( sqrt( abscissa ) ) );
					
					//display a table with an interval of 15 pixels between columns
					cout << setw(15) << abscissa << setw(15) << function << setw(15) << amount << endl; 
					
					abscissa += increment; 
				} 

			while ( abscissa <= finalStep + increment / 2 ); 
			cout << endl; 
			
		return 0; 
	}
