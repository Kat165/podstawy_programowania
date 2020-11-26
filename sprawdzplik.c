#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *plik;
    if ((plik=fopen("zadanie.txt", "r"))==NULL)
    {
        perror("nie udalo sie otworzyc pliku");
        exit (1);
    }
    char tekst[200];
    fscanf(plik,"%s",tekst);
    printf("%s", tekst);

    fclose (plik);
    return 0;
}
