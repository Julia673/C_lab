// Метод простої ітерації
#include <iostream>
#include <math.h>
using namespace std;

const float x0 = -2.0f;
const float eps = 0.001f;
float fun(float x)
{
return sinf(x) - 5.0f;
}
float iter(float &xi)
{
float xm;
xm = xi;
do
{
xi = xm;
xm = fun(xi);
} while( fabs(xi-xm) < eps);
return xm;
}
void main()
{
float x1,x;
x1 = x0;
 x = iter(x1);
printf("iter - Корінь рiвняння : %8.6f\n",x);
printf("'Похибка :%8.6f\n", fabs( fun(x) -x ));
}
ЗАВДАННЯ ДЛЯ 