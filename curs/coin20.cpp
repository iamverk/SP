/*  MVM2020   */
#include "mlisp.h"
double variant   = 13.;
double last__digit__of__group__number   = 6.;
double kinds__of__coins   = 6.;
bool NOT_Q(bool x_Q);
bool implication_Q(bool x_Q, bool y_Q);
double cc(double amount, double kinds__of__coins);
double count__change(double amount, double kinds__of__coins);
double first__denomination(double kinds__of__coins);
double gr__amount();
//________________ 
bool NOT_Q(bool x_Q){
return 0. == ((x_Q ? 1. : (true ? 0.: _infinity)));
}
bool implication_Q(bool x_Q, bool y_Q){
return (NOT_Q(x_Q) || y_Q);
}
double cc(double amount, double kinds__of__coins){
return ((amount == 0. ? 1. : (true ? ((implication_Q(0. < amount, kinds__of__coins == 0.) ? 0. : (true ? (cc(amount, (kinds__of__coins + -1.)) + cc((amount + ( -first__denomination(kinds__of__coins) )), kinds__of__coins)): _infinity))): _infinity)));
}
double count__change(double amount, double kinds__of__coins){
display("count__change for ");
display(amount);
display(" ");
display(kinds__of__coins);
display(" \t= ");
return ((0. < amount ? ((0. < kinds__of__coins ? ((0. < first__denomination(kinds__of__coins) ? cc(amount, kinds__of__coins) : (true ? display("(improper parameter value) "), 0.: _infinity))) : (true ? display("(improper parameter value) "), 0.: _infinity))) : (true ? display("(improper parameter value) "), 0.: _infinity)));
}
double first__denomination(double kinds__of__coins){
return ((kinds__of__coins == 1. ? 1. : (true ? ((kinds__of__coins == 2. ? 2. : (true ? ((kinds__of__coins == 3. ? 3. : (true ? ((kinds__of__coins == 4. ? 5. : (true ? ((kinds__of__coins == 5. ? 10. : (true ? ((kinds__of__coins == 6. ? 20. : (true ? 0.: _infinity))): _infinity))): _infinity))): _infinity))): _infinity))): _infinity)));
}
double gr__amount(){

return remainder(((100. * last__digit__of__group__number) + variant), 137.);
}
int main(){
display("MVM variant ");
	display(variant); newline();
	newline();
	display("1__2__3__5__10__20");
	newline();
	display(count__change(100., kinds__of__coins)); newline();
	newline();
	display(count__change(gr__amount(), kinds__of__coins)); newline();
	newline();
	display(count__change(100., 100.)); newline();
	newline();
	 std::cin.get();
 return 0;
}

