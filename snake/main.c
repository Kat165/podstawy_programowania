#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#define K 40
#define W 60


int i,j,x,y,n,a,b,r;
int Head, Tail,kulki,kier;    //glowa i ogon weza i jedzenie
int poleGry[K][W];
int gra,punkty=0,rekord;

FILE *plik;

void narodzinyWeza()
{

    plik=fopen("Rekord.txt","r");
    if (plik==NULL)
    {
        printf("wystapil blad");
        exit(2);
    }
    fscanf(plik,"%d",&rekord);
    fclose(plik);

    for(i=0;i<K;i++)
    {
        for(j=0;j<W;++j)
        {
            poleGry[i][j]=0;
        }
    }
    x=K/2;
    y=W/2;
    Head=5;
    Tail=1;
    n=y;
    gra=1;  //dla 0 koniec gry;
    kulki=0;
    kier='d';

    for(i=0;i<Head;++i)
    {
        n++;
        poleGry[x][n-Head]=i+1;
    }
}

int klawiatura()
{
    if(kbhit())
        return getch();
    else return -1;
}


void koniecGry()
{
    printf("\a");
    Sleep(1000);
    system("Cls");

    if(punkty>rekord)
    {
        printf("        Nowy rekord!!   ");
        plik=fopen("Rekord.txt","w");
        fprintf(plik,"%d",punkty);
        fclose(plik);
    }


    printf("\n\n        KONIEC GRY");
    printf("\n\n    zdobyte punkty: %d",punkty);

    while(1)
    {
        r=klawiatura();
        if(r==27)
        {
            gra=0;
            break;
        }
        else if(r==13)
        {
            gra=1;
            narodzinyWeza();
            break;
        }
    }
    system("Cls");

}

void wypiszPoleGry()
{
    for(i=0;i<=W+1;i++)
    {        //górna ramka
        if(i==0)
        {
            printf("%c",201);
        }
        else if(i==W+1)
        {
            printf("%c",187);
        }
        else
        {
            printf("%c",205);
        }
    }
    printf("Punkty: %d      Rekord: %d",punkty,rekord);
    printf("\n");

     for(i=0;i<K;i++){              //boczne ramki
        printf("%c",186);

        for(j=0;j<W;j++){
            if(poleGry[i][j]==0)
                {
                    printf(" ");
                }
            if(poleGry[i][j]>0 && poleGry[i][j]!=Head)      //print ogona
                {
                    printf("%c",176);
                }
            if(poleGry[i][j]==Head)                 //print glowy
                {
                    printf("%c",178);
                }
            if(poleGry[i][j]==-1)                   //print kulek
                {
                    printf("%c",35);
                }
            if(j==W-1)
                {
                    printf("%c\n",186);
                }
        }
    }

    for(i=0;i<=W+1;i++){        //dolna ramka
        if(i==0){
            printf("%c",200);
        }else if(i==W+1){
            printf("%c",188);
        }else{
            printf("%c",205);
        }
    }
}



void zebyNieWygladaloDziwnie()
{
    COORD pozycja;              //przymocowanie do rogu
    pozycja.X=0;
    pozycja.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pozycja);
}
void spawnkulek()
{
    srand(time(0));
    a=1+rand()%(K-2);                //nie przewidzisz gdzie sa kulki
    b=1+rand()%(W-2);
    if(kulki==0 && poleGry[a][b]==0)
    {
        poleGry[a][b]=-1;
        kulki=1;
    }

}


void ruch()
{
    r=klawiatura();
    r=tolower(r);

    if(((r=='w'||r=='s')||(r=='a'||r=='d')) &&(abs(kier-r)>5))
    {
        kier=r;
    }

    if(kier=='w')      //ruch w gore
    {
        --x;
        if(poleGry[x][y]!=0 &&poleGry[x][y]!=-1)        //waz sie nie zjada
        {
            koniecGry();
        }
        if(x==-1)
        {
            x=K-1;
        }
        if(poleGry[x][y]==-1)
        {
            kulki=0;
            Tail-=5;
            punkty+=2;
        }
        ++Head;
        poleGry[x][y]=Head;
    }
    if(kier=='a')      //ruch w dol
    {
        --y;
        if(poleGry[x][y]!=0 &&poleGry[x][y]!=-1)
        {
            koniecGry();
        }
        if(y==0)
        {
            y=W-1;
        }
        if(poleGry[x][y]==-1)
        {
            kulki=0;
            Tail-=5;
            punkty+=2;
        }
        ++Head;
        poleGry[x][y]=Head;
    }
    if(kier=='s')      //ruch w lewo
    {
        ++x;
        if(poleGry[x][y]!=0 &&poleGry[x][y]!=-1)
        {
            koniecGry();
        }
        if(x==K-1)
        {
            x=-1;
        }
        if(poleGry[x][y]==-1)
        {
            kulki=0;
            Tail-=5;
            punkty+=2;
        }
        ++Head;
        poleGry[x][y]=Head;
    }
    if(kier=='d')      //ruch w prawo
    {
        ++y;
        if(poleGry[x][y]!=0 &&poleGry[x][y]!=-1)
        {
            koniecGry();
        }
        if(y==W-1)
        {
            y=0;
        }
        if(poleGry[x][y]==-1)
        {
            kulki=0;
            Tail-=5;
            punkty+=2;
        }
        ++Head;
        poleGry[x][y]=Head;
    }
}

void ogon()
{
    for(i=0;i<K;i++)
    {
        for(j=0;j<W;j++)
        {
            if(poleGry[i][j]==Tail)
            {
                poleGry[i][j]=0;
            }
        }
    }
    ++Tail;
}

void schowajkursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO inf;
   inf.dwSize = 100;
   inf.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &inf);
}

void main()
{
    Sleep(2000);
    narodzinyWeza();

    while(gra==1)       //petla programu
    {
        schowajkursor();
        wypiszPoleGry();
        zebyNieWygladaloDziwnie();
        spawnkulek();
        ruch();
        ogon();
        Sleep(50);
    }
}


