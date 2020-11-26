#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    FILE *plik;
    if ((plik=fopen("liczby.bin", "wb"))==NULL)
    {
        printf("nie udalo sie otworzyc pliku");
        exit (1);
    }
    int tab[]={1,2,4,INT_MAX,256,0,-1,INT_MIN};


    fwrite (tab , sizeof(tab),  1, plik);


    fclose(plik);
    return 0;
}
