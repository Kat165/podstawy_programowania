#include <stdio.h>
#include <stdlib.h>
struct pierwiastki
{
    int liczba_m;
    float m[2];
}odp;

struct pierwiastki fkwad(int a, int b, int c)
{
    float e= b*b-(4*a*c);
    float d=e;
    float p=sqrt(d);
    if (d==0)
    {
        odp.liczba_m=1;
        odp.m[0]=-b/(2*a);
    };
    if (d>0)
    {
        odp.liczba_m=2;
        odp.m[0]=(-b-p)/2;
        odp.m[1]=(-b+p)/2;
    };
    if (d<0)
        {odp.liczba_m=0;};


    printf("liczba miejsc zerowych: %d\n rozwiazania: %f %f", odp.liczba_m, odp.m[0], odp.m[1]);
    return odp;
}
int main()
{

    int a;
    int b;
    int c;
    printf("Podaj wspolczynnik a: \n");
    scanf("%d",&a);
    printf("Podaj wspolczynnik b: \n");
    scanf("%d",&b);
    printf("Podaj wspolczynnik c: \n");
    scanf("%d",&c);

    fkwad(a,b,c);

    return 0;
}
