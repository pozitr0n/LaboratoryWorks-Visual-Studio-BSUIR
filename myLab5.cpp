//Roman Kozar - Laboratornaya 5

//add main modules 
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>


//add mathematics module
#include <math.h>

	//apply pointer void, because the object type is not defined in advance
	int main( void ) {

		//global variables
		int counter, indicator, line, column;
		int minElement, maxElement, changeVariable=0; 

		char **mainArray;

			//procedure of filling the array
			cout << "Enter the number of lines - ";
				cin >> line;

			cout << "Enter the number of columns - ";


				cin >> column;

				mainArray = new char * [ line ];
					for ( counter = 0; counter < line; counter++ )

						mainArray[ counter ] = new char[ column ];
							for ( counter = 0; counter < line; counter++ ) {

								for ( indicator = 0; indicator < column; indicator++ ) {
									cout << "Input Array[" << counter << "][" << indicator << "] = ";
										cin >> mainArray[ counter ][ indicator ];
								}
							}

				for ( counter = 0; counter < line; counter++ ) {
					for ( indicator = 0; indicator < column; indicator++ )
						cout << setw (3) << mainArray[ counter ][ indicator ] << " ";

					cout << endl;
				}

			//add pause beside two matrix
			system("PAUSE");

				maxElement = minElement = mainArray[0][0];
				int minString=0, maxString=0;

					//find min and max element in double array
					for ( indicator = 0; indicator < column; indicator++ ) {
						for ( counter = 0; counter < line; counter++ ) {

							if ( maxElement < mainArray[ counter ][ indicator ] ) {
								maxElement = mainArray[ counter ][ indicator ]; 
								maxString = counter;

							} if ( minElement > mainArray[ counter ][ indicator ] ) {
								minElement = mainArray[ counter ][ indicator ];
								minString = counter ;
							}
						}
                    
					}
					
					cout<<endl;

					cout<<minString<<" "<<maxString<<endl;

					for ( indicator = 0; indicator < column; indicator++) {
							changeVariable = mainArray[ maxString ][ indicator ]; 
							mainArray[ maxString ][ indicator] = mainArray[ minString ][ indicator ];
							mainArray[ minString ][ indicator ] = changeVariable;
					}

						for ( counter = 0; counter < line; counter++ ) {
							for ( indicator = 0; indicator < column; indicator++ )
								cout << setw (3) << mainArray[ counter ][ indicator ] << " ";

				cout << endl;      
				}
			for ( counter = 0; counter < line; counter++ ) {
				delete []mainArray[ counter ];
				delete []mainArray;
			}

	//finish the program
	return 0;
}
