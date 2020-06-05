/*  MVM2020   */
#include "mlisp.h"
double even__bits(double n);
double odd__bits(double n);
double bit__count(double n);
double report__results(double n);
double dd   = 30.;
double mm   = 9.;
double yyyy   = 2020.;
//________________ 
double even__bits(double n){
return ((n == 0. ? 1. : (true ? ((remainder(n, 2.) == 0. ? even__bits(quotient(n, 2.)) : (true ? odd__bits(quotient(n, 2.)): _infinity))): _infinity)));
}
double odd__bits(double n){
return ((n == 0. ? 0. : (true ? ((remainder(n, 2.) == 0. ? odd__bits(quotient(n, 2.)) : (true ? even__bits(quotient(n, 2.)): _infinity))): _infinity)));
}
double bit__count(double n){
return ((n == 0. ? 0. : (true ? (remainder(n, 2.) + bit__count(quotient(n, 2.))): _infinity)));
}
double report__results(double n){
display("Happy birthday to you_E\n\t");
display(n);
newline();
display("\teven_Q\t");
display(even__bits(n) == 1. ? "yes" : "no");
newline();
display("\todd_Q\t");
display(odd__bits(n) == 1. ? "yes" : "no");
newline();
display("bit__count = ");
return bit__count(n);
}
int main(){
display(report__results(((dd * 1000000.) + (mm * 10000.) + yyyy))); newline();
	 std::cin.get();
 return 0;
}

