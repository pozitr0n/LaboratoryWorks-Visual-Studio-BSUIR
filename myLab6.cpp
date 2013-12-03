//Roman Kozar - Laboratory 6

//librarys
#include <iostream.h>
#include <string.h>
#include <stdio.h>

	int main() {
		char arrayString[ 50 ];

		cout << "Input the string: " << endl;
			gets( arrayString );
			strcat( arrayString,  " " );

			int length = strlen( arrayString );
			int i, max = 0, k = 0, n = 0, wp;

			for(i = 0; i < length; i++ ){
				if( arrayString[ i ] != ' ' ) 
					k++; else {
					if( k > max ){ 
						max = k; wp = i - k; 
						k = 0; n++;
					}
				}
			}

			//output data
			cout << "Maximum Word: " << n << ", " << "Position: " << wp << ' ' << endl;
	return 0;
}
