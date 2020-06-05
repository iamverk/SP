#include <iostream>
#include "mlisp.h"

double a = 12;
double b = 14;

double fun (double x);
double golden__section__search (double a, double b);
double golden__start (double a, double b);

double mphi = 0.5 * (12 - sqrt(14));

double __now__try (double a, double b, double xa, double ya, double xb, double yb);
bool close__enough_Q (double x, double y);

double tolerance = 0.00001;
double xmin = 0.;

double fun (double x) {
    x = x - 13/14;
    return x - 2*sin(x)*cos(x)-0.5;
}

double golden__section__search (double a, double b) {
    {
        double
            xmin(a < b ? golden__start(a, b) : golden__start(b, a));
        newline();
        return xmin;
    }
}

double golden__start (double a, double b) {
    {
        double
            xa(a + mphi*(b - a)),
            xb(b - mphi*(b - a));
        return __now__try(a, b, xa, fun(xa), xb, fun(xb));
    }
}

double __now__try (double a, double b, double xa, double ya, double xb, double yb) {
    return (close__enough_Q(a,b) ? ((a + b)*0.5) : (
            {
                (display("+"), ( ya < yb ? (b = xb,
                                          xb = xa,
                                          yb = ya,
                                          xa = a + mphi*(b - a),
                                          __now__try(a, b, xa, fun(xa), xb, yb)) :
                                         (a = xa,
                                          xa = xb,
                                          ya = yb,
                                          xb = b - mphi*(b - a),
                                          __now__try(a, b, xa, ya, xb, fun(xb)))
                                          ));
            }
            ));
}

bool close__enough_Q (double x, double y) {
    return (abs(x - y) < tolerance);
}

int main() {
    xmin = golden__section__search(a, b);
    display("interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]\n");
    display("xmin=\t\t");
    display(xmin);
    display("\n");
    display("f(xmin)=\t");
    display(fun(xmin));
		newline();
    return 0;
}
