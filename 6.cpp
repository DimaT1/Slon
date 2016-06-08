#include <iostream>
#include <math.h>
#define precision 0.000001


using namespace std;

void psqrt4(int a, int b, int c, int d, int e);
void psqrt2(int a, int b, int c);

int main(void)
{
    int a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    if(a) {
        psqrt4(a, b, c, d, e);
    }
    else if((!a) && (!b) && (c)) {
        psqrt2(c, d, e);
    }
    else
        cout << "нет корня" << endl;

    return 0;
}

void psqrt4(int a, int b, int c, int d, int e) {
    if((a < 0) || (e < 0)) { // квадрат отрицательный
        cout << "нет корня" << endl;
    }
    else {
        float a1 = sqrt(a);
        float c1 = sqrt(e);
        float b1 = b/2.0/a1;

        if(b < 0) {
            if(d < 0)
                b1 *= 1;
            else
                a1 *= -1;
        }
        else if(d < 0)
            c1 *= -1;

        if((c1 < 0) && (d < 0) && (b1 < 0))
            b1*= -1;

        if((a1 < 0) && (b < 0) && (b1 < 0))
            b1*= -1;

        if((c < 0) && (abs(b) < precision))
            a1*= -1;

    if(((2 * a1 * c1 + b1 * b1 - c) < precision) && ((2 * a1 * c1 + b1 * b1 - c) > -precision))
        cout << "(" << a1 << ")x^2 + (" << b1 << ")x + (" << c1 << ")" << endl;
    else
        cout << "нецелые коэффициенты, наибольшая степень икса 2"  << endl;
    }
}

void psqrt2(int a, int b, int c) {

    if((a < 0) || (c < 0)) { // квадрат отрицательный
        cout << "нет корня" << endl;
    }
    else {

        bool flag = (b > 0);
        b = abs(b);

        if((((sqrt(a) * sqrt(c) * 2) - b) < precision) && ((sqrt(a) * sqrt(c) * 2) - b) > -precision)
            if(flag)
                cout << sqrt(a) << "x + " << sqrt(c) << endl;
            else
                cout << sqrt(a) << "x - " << sqrt(c) << endl;
        else
            cout << "нецелые коэффициенты, наибольшая степень икса 1"  << endl;
    }
}
