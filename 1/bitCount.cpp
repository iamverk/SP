/*#include "mlisp.h"

double odd__bits(double n);
double even__bits(double n);


double even__bits(double n) {
	return (( n == 0.) ? 1. :
	       ((remainder(n, 2.) == 0.) ?
	       	even__bits (quotient(n, 2.)) :
       	       (true ? odd__bits(quotient(n, 2.)) :
		_infinity)));
}
double odd__bits(double n) {
	return (( n == 0.) ? 0. :
		((remainder(n, 2.) == 0.) ? 
		 odd__bits(quotient(n, 2.)) :
			 even__bits(quotient(n, 2.))));
	}

double bit__count(double n) {
	return (( n == 0.) ? 0 : 
		( remainder(n, 2.) + bit__count(quotient(n, 2.))));
}	

int trash(int x) {
    return x > 10 ? display(x), x : 0;
}

double report__results(double n) {
	display("Happy birthday to you!\n\t");
	display(n); newline();
	display( "\teven?\t"); display ( (even__bits(n) == 1) ? "yes" : "no");
	newline();
	display( "\todd?\t"); display ( (odd__bits(n) == 1) ? "yes" : "no");
	newline();
	display("bit-count = ");
	return bit__count(n);
}

int main() {
double dd = 30.,mm = 9., yyyy = 2000.;
       
display(report__results (dd*1000000+
                         mm*10000+
                         yyyy));
 newline();

 std::cin.get();
 return 0;
}
*/

#include "mlisp.h"

double even__bits(double n);
double odd__bits(double n);


double odd__bits(double n) {
  return (n == 0 ? 0
       : remainder(n,2) == 0 ?
                odd__bits (quotient(n,2))
       : true ? even__bits(quotient(n,2))
       : _infinity);
 }
 
 double even__bits(double n) {
  return (n == 0 ? 1
       : remainder(n,2) == 0 ?
                even__bits (quotient(n,2))
       : (odd__bits(quotient(n,2))));         
 }
 
 double bit__count(double n) {
	return (( n == 0.) ? 0 : 
		( remainder(n, 2.) + bit__count(quotient(n, 2.))));
}	

int trash(int x) {
    return x > 10 ? display(x), x : 0;
}
	
 
 double report__results(double n) {
 	display("Happy birthday to you!\n\t");
 	display(n);
 	newline();
 	display("\teven?\t");
 	display((even__bits(n) == 1 ? "yes" : "no"));
 	newline();
 	display("\todd?\t");
 	display((odd__bits(n) == 1 ? "yes" : "no"));
 	newline();
 	display("bit-count = ");
	return bit__count(n);

 }

int main(){
	double dd = 30;
	double mm = 9;
	double yyyy = 2000;
	display(report__results (dd*1000000+
                         mm*10000+
                         yyyy));
 	newline();
 	std::cin.get();
 	return 0;	
} 

