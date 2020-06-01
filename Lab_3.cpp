#include <iostream>
#include <math.h>
using namespace std;
// Метод Крамера 
const int N = 4;
const int a0[N][N] = {
                    {1,0,1,2},
                    {1,0,1,2},
                    {1,0,1,2},
                    {1,0,1,2}
                    };
int a[N][N];
int b[N],x[N];
const int b0[N]={12, 30, 14, 3};
void mas(){
    int l,k;
    for(l=0; l<N; l++)
    {
        b[l] = b0[l];
        for(k=0; k< N; k++)
            a[l][k] = a0[l][k];
    }
}
int kramer(){
    float q;
    int f;
    int i,j;
    printf("Метод Крамера \n");
    mas();
    q = vizn(a);
    for(i=0;i<N;i++)
    {
    
      for(j=0;j<N;j++)
         a[j][i] = b0[j];
         x[i] = vizn(a);
         mas();
    }
    f = 0;
    if( float(q) < 0.01f)
      return 0;
    else
    {
        for(i=0; i<N; i++)
            x[i] = x[i]/q;
        return 1;
    }
}
void main()
{
    if(kramer())
    {
      printf("'->pозв'язок системи:\n");
      for(int i=0;i<N;i++)
        printf("x[%d]=%6.3f\n", i,x[i]);
    } else
       printf("Багато або немає розв'язків\n");

       //Метод Гаусса-Жордана
int g_jor()
{
    int k,i,j;
    float m;
    printf("Метод Гаусса-Жордана \n");
    mas();
    for(k=0;k<N;k++)
        for(i=0;i<N;i++)
            if(i != k)
            {
            m = a[i][k]/a[k][k];
            a[i][k] = 0;
            for(j=k; j<N;j++)
                a[i][j] = a[i][j] - m*a[k][j];
                b[i] = b[i] - m*b[k];
            }
        for(i=0; i<N;i++)
        {
             b[i] = b[i]/a[i][i];
             a[i][i] = 1;
             x[i] = b[i];
    }
}