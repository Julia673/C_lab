//Метод трапеції


# include <iostream>

#include <cmath>

using namespace std;

const float E = 1.e-3;

//--------- підінтергральна функція 1-го інтеграла — fn1()

float fn1 (float x)

{ return sqrt(1 + log(x));

}

//---------- підінтергральна функція 2-го інтеграла  — fn2()

float fn2 (float x)

{ return log(1 + pow(x,2))/(1 + pow(x,2));}

//----------------------------- функція метода трапецій — ft()

float ft (int n, float a, float b, float fun(float))

{ int i;

float s1, h, s = 0;

do

{

s1 =s;

h = (b - a)/n;

s = (fun(a) + fun(b))/2;

for (i = 1; i <= n-1; i++)

s += fun(a + i*h);

s *= h; n *= 2;

}

while (fabs(s - s1) > E);

return s;

}

//------------------------------------------- основна функція

int main ( )

{ float y;

y = ft(20, 2.2, 3.0, fn1) + ft(20, 0, 1.0, fn2);

cout << "y = " << y << endl;
return 0 ;
}
