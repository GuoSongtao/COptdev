// umfpack test

#include <stdio.h>
#include "umfpack.h"

int n = 5;
int Ap[]={0,2,5,9,10,12};
int Ai[]={0,1,0,2,4,1,2,3,4,2,1,4};
double Ax[]={2.,3.,3.,-1.,4.,4.,-3.,1.,2.,2.,6.,1.};
double b[]={8.,45.,-3.,3.,19.};
double x[5];
double Info[UMFPACK_INFO],Control[UMFPACK_CONTROL];

int main(int argc,char*argv[])
{
	double *null = (double*)NULL;
	int i;
	void *Symbolic,*Numeric;
	(void) umfpack_di_symbolic(n,n,Ap,Ai,Ax,&Symbolic,Control,Info);
	(void) umfpack_di_numeric(Ap,Ai,Ax,Symbolic,&Numeric,Control,Info);
	umfpack_di_free_symbolic(&Symbolic);
	(void) umfpack_di_solve(UMFPACK_A,Ap,Ai,Ax,x,b,Numeric,Control,Info);
	umfpack_di_free_numeric(&Numeric);
	for(i =0 ; i < n ; ++ i ) printf("x[%d] = %g\n",i,x[i]);
	umfpack_di_report_info(Control,Info);
	return 0;
}