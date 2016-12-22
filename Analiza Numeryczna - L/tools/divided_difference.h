#ifndef DD_INCLUDED
#define DD_INCLUDED 1

#include <iostream>
#include <vector>


class div_diff {
	std::vector<double> xs;
	std::vector<double> ys;

	std::vector< std::vector<double> > dd;


  public:
  	
	div_diff(std::vector<double> x, std::vector<double> y) 
		: xs{x},
		  ys{y}
	{
		dd.resize(x.size()+1);
		for(int i=0; i<dd.size(); i++) 
			dd[i].resize(x.size());
		
		for(int i=0; i<x.size(); i++) {
			dd[0][i] = x[i];
			dd[1][i] = y[i];
		}

		// calculate dd


		for( int i=2; i< x.size()+1; i++ ){
			for( int j=i-1; j< x.size(); j++) {
				dd[i][j] = (dd[i-1][j] - dd[i-1][j-1]) /( dd[0][j] - dd[0][j-i+1] );
			}
		}
	}

	void show();
  	void nshow();

  	double getValue(int a, int b);
};






#endif

/*
	0		1		 2			 4
0	x0		x1		 x2			 x3
1	f[x0]   f[x1]	 f[x2]		 f[x3]
2			f[x0,x1] f[x1,x2]    f[x2,x3]
3					 f[x0,x1,x2] f[x1,x2,x3]
4								 f[x0,x1,x2,x3]
*/





/*
	0  1
0	x0 f[x0]
1	x1 f[x1] f[x0, x1]
2	x2 f[x2] f[x1, x2] f[x0, x1, x2]


]
3	x3 f[x3] f[x2, x3] f[x1, x2, x3]
4	x4


*/