#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double y(int n, double x) {

	double result = 0;
	double a, b; 
	if ( 0 == n ) {
		result = sin(x)/x;
	} else if ( 1 == n ) {
		result = sin(x)/x/x - cos(x)/x;
	} else {
		a=y(n-1,x);
		b=y(n-2,x);
		result= (2*(n-1)+1)*a/x-b;    
	}
	return result;
}

int main (int argc, char **argv) {
	int n;
	double x;
	if ( 3 != argc ) 
	{
		puts("Usage: upbessel n x ");
		return 1;
	}
	n = atoi(argv[1]);
	x = atof(argv[2]);
	printf("y(%d,%f) = %f\n",n,x,y(n,x));

	return 0;

}
