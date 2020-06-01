// P9_9.CPP — вычисление интеграла методом трапеции

//          использование функции как параметра значения

# include <iostream.h>

#include <math.h>

#include <conio.h>

const float E = 1.e-3;

//--------- подынтегральная функция 1-го интеграла — fn1()

float fn1 (float x)

{ return sqrt(l + log(x));

}

//---------- подынтегральная функция 2-го интеграла — fn2()

float fn2 (float x)

{ return log(1 + pow(x,2))/(1 + pow(x,2));}

//----------------------------- функция метода трапеций — ft()

float ft (int n, float a, float b, float fun(float))

{ int i;

float s1, h, s = 0;

do

{

s1 =s;

h = (b - a)/n;

s = (fun(a) + fun(b))/2;

for (i = 1; і <= n-1; i++)

s += fun(a + i*h);

s *= h; n *= 2;

}

while (fabs(s - s1) > E);

return s;

}

//------------------------------------------- главная функция

void main ( )

{ float y;

у = ft(20, 2.2, 3.0, fn1) + ft(20, 0, 1.0, fn2);

cout << "y = " << у << endl;

getch();