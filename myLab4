//Roman Kozar - Laboratory 4

//adding main labrary 
#include <iostream.h>

    int main() {

        //input the elements
        cout << "Input the elements: ";

        //main variables 
        int count, indicator, number;

            cin >> number;

				//the allocation of the memory size of number units of this type 
                int * arr = new int[ number ];

                //fill the array
                for ( count = 0; count < number; count++ ) {

                    cout << "Number " << count + 1 << " = ";
                    cin >> arr[ count ];

                }

                //the counter is reset
                int numberCount = 0;
                int indifferentCount = 0;

                    for ( count = 0; count < number; count++ ) {

                        numberCount = 0;

                            //start branching algorithm
                            for ( indicator = 0; indicator < number; indicator++) {

                                //start branching algorithm
                                if ( arr[ count ] == arr[ indicator ] )
                                    numberCount++;
                            }

                        if ( 1 < numberCount )
                            indifferentCount++;
                    }

                 if ( indifferentCount < 1 )
                    cout << "All elemnts in array is different: " << endl;
                else 
                    cout << "Number of the same elements: " << indifferentCount << endl;
        return 0;
    }
