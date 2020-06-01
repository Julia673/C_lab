// Функція методу прямокутників
float integral_pram(float a, float b, int n)
{   float h, S, x;
    int i;
    h = (b – a) / n;
    S=0;
    for (i = 0; i<= n –1; i++){
        x = a + i * h;
        S = S + f (x);
    }
    S = h* S;
    return S;
}
// Функція методу Сімпсона
float integral_simps (float a, float b, int n)
{ 
    float h, S, S1, S2, x;
    int i;
    h = (b – a) / n;
    S = 0;
    S1 = 0;
    S2 = 0;
    for (i = 1; i<= n –1; i+ +) {
        x = a + i * h;
        if (i % 2 == 0) S2 = S2 + f(x);
        else S1 = S1 + f(x);
    }
    S = h/3* (f(a) + f(b) + 4*S1+2*S2);
    return S;
}