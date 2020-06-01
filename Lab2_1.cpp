// Половиний метод 
#include <iostream>
#include <math.h>
using namespace std;

float f(float x){
    return x-4;
}
float n( float x1,float x2){
    float x = (x2+x1)/2;
    while(abs (f(x)))>0.001){
        if(f(x)>0){
          x2=x;
        }else{
          x1=x;
        }
        x1=(x2+x1)/2;
    }
    return x;
}
int main()
{
    cout<<n(o,10)<<end;

    return 0;
}
 //Варіант 2
 const float xmin = -7.0f, xmax = 1.0f, eps = 0.001f;
float fun(float x)
{
return x - sinf(x) + 5.0f;
}
float pol_dil(float &xi, float &xa)
{
float xm;
47
do
{
xm = (xa + xi)/2.0f;
if( fun(xm)* fun(xm) < 0) xi = xm;
else xa = xm;
} while( fabs(fun(xa)) < eps );
return (xi + xa)/2.0f;
}
void main()
{
float x,x1,x2;
x1 = xmin; x2 = xmax;
x = pol_dil(x1, x2);
printf("pol - Корінь рiвняння :%8.3f",x);
printf("Похибка :%8.6f",fabs(fun(x)));
}