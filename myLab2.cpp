//Roman Kozar - Laboratory-2

//standart libs
#include <iostream.h>

//math-lib
#include <math.h>

using namespace std;
	
	//main
	int main() {

		//main variables
		double variableX, variableY, varFunction, function, finalResult;
		int varSwitch;

		cout << "Input variableX: ";
			cin >> variableX;

		cout << "Input variableY";
			cin >> variableY;

		cout << "Change the function (1) - sh(x); (2) - x*x; (3) - exp(x)";
			cin >> varFunction;

				//begin switch 
				switch( varFunction ) {
					case 1 : function = sinh( x );
						break;
					case 2 : function = pow( x, 2 );
						break;
					case 3 : function = exp( x );
						break;
					
						default : cout << "Unchange function! Error!";
							return 1;
				}

				//begin to compile operator "if" and final operation to output response with "finalResult"
				if ( pow( variableX, 3 ) > 0 );
					finalResult = ( log( pow( function, 3 ) );

						if ( pow( variableX, 3 ) < 0 );
							finalResult = ( tan( pow( variableX, 3 ) ) + function );
							
								if ( pow( variableX, 3 ) = 0 );
									finalResult = pow( fabs( pow( variableY, 3 ) - pow( variableX, 2 ) ), 1 / 3. );
		return 0;
	}
