//Roman Kozar - Laboratornaya 7
#include <iostream.h>
#include <string.h>

int main() {
	struct strc{
		char fio[ 40 ];
		int otc[ 4 ];
		double sb;
	} mstud[ 100 ];

	int nst, i, j;
	double sbp = 0;
		cout << "Input the number of students: ";
			cin >> nst;
			for ( i = 0; i < nst; i++ ){
				cout << "Input FIO" << endl;
					cin >> mstud[ i ].fio;
				cout << "Input 4 marks: " << endl;
					mstud[ i ].sb = 0;

						for ( j = 0; j < 4; j++ ) {
							cin >> mstud[ i ].otc[ j ];
							mstud[ i ].sb += mstud[ i ].otc[ j ] / 4.;
						}
						cout << endl;
					}
				cout << "New list of students:" << endl;

				for( i = 0; i < nst; i++ )
					if ( mstud[ i ].sb == 10 ) 
						cout << mstud[ i ].fio << endl;

			for( i = 0; i < nst; i++ )
				if ( mstud[ i ].sb > sbp && mstud[ i ].sb != 10 ) 
					cout << mstud[ i ].fio << endl;
	return 0;
}
