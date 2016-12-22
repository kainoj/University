#include "divided_difference.h"



// Prints array in its natural order
void div_diff::nshow() {
		for(int i=0; i<dd.size(); i++) {
			for(int j=0; j<dd[i].size(); j++ ) {
				std::cout << dd[i][j] << "\t| ";
			}
			std::cout << "\n";
		}
		std::cout << "\n########\n";
}




// Prints array in human readable format
void div_diff::show() {
	
	for(int i=0; i<dd[0].size(); i++) {
			for(int j=0; j<i+2; j++ ) {
				std::cout << dd[j][i] << "\t| ";
			}
			std::cout << "\n";
		}
		std::cout << "\n########\n";
}


double div_diff::getValue(int a, int b) {

	return dd[ b-a+1][b ];
}

