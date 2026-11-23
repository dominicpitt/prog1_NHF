#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "debugmalloc.h"
#include <string.h>
typedef struct ADAT
{
      char nev[30];
      char foglalkozas[20];
      char emailcim[20];
      char telefonszam[15];
}ADAT;
void nevkeres(char *keresendo)
{
      ADAT adatok;
      FILE *fp;
      fp=fopen("adatok","rb");
      if(fp==NULL)
      {
            printf("\n Hiba a megnyitasban.");
            exit(1);
      }
      while(fread(&adatok,sizeof(adatok),1,fp)==1)
      {
            if(strcmp(adatok.nev,keresendo)==0)
            {
                  printf("\nNev:%s\nFoglalkozas:%s\nTelefonszam:%s\nEmailcim:%s",adatok.nev,adatok.foglalkozas,adatok.telefonszam,adatok.emailcim);
            }
            else
            {
                  printf("Nincs talalat.");
            }
      }
 fclose(fp);
}
void rekordkilistazas()
{
    ADAT adatok;
    FILE *f;
f=fopen("adatok","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

exit(1);
}
while(fread(&adatok,sizeof(adatok),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nNev:%s\nFoglalkozas:%s\nE-mailcim:%s\nTelefon:%s",adatok.nev,adatok.foglalkozas,adatok.emailcim,adatok.telefonszam);
}
fclose(f);
}
void telefonszamkeres(char *keresendo)
{
      ADAT adatok;
      FILE *fp;
      fp=fopen("adatok","rb");
      if(fp==NULL)
      {
            printf("\n Hiba a megnyitasban.");
            exit(1);
      }
      while(fread(&adatok,sizeof(adatok),1,fp)==1)
      {
            if(strcmp(adatok.telefonszam,keresendo)==0)
            {
                  printf("\nNev:%s\nFoglalkozas:%s\nTelefonszam:%s\nEmailcim:%s",adatok.nev,adatok.foglalkozas,adatok.telefonszam,adatok.emailcim);
            }
        else
            printf("Nincs talalat.");

      }
 fclose(fp);
}
void modosit(char *modositando)
{

}
void letrehoz()
{

      system("cls");
      FILE *fp;
      ADAT adatok;
      fp=fopen("adatok","ab+");
      printf("Kerem adja meg a nevet: ");
      char keresztnev[15];
      char vezeteknev[15];
      scanf(" %s %s", vezeteknev, keresztnev);
      sprintf(adatok.nev, "%s %s", vezeteknev, keresztnev);
      printf("\nKerem adja meg a foglalkozast: ");
      scanf(" %s", adatok.foglalkozas);
      printf("\nKerem adja meg a E-mailcimet: ");
      scanf(" %s", adatok.emailcim);
      printf("\nKerem adja meg a telefonszamot: ");
      scanf(" %s", adatok.telefonszam);
      fwrite(&adatok,sizeof(adatok),1,fp);
fclose(fp);
printf("Sikeres mentes.");
}
void torles()
{

}

int main()
{
      char valasz;
      bool menu=true;
      do
            {
      printf("Kerem valasszon az alabbi menupontokbol:\n");
      printf(" '1': Rekord kereses nev szerint\n");
      printf(" '2': Rekord kereses telefonszam szerint\n");
      printf(" '3': Rekord modositas\n");
      printf(" '4': Rekord torles\n");
      printf(" '5': Rekord letrehozas\n");
      printf(" '6': Rekord kilistazas\n");
      printf(" '9': Kilepes!\n");
      scanf(" %c", &valasz);
      switch(valasz)
      {
            case'1':
                  system("cls");
                  char *nev;
                  char keresztnev[15];
                  char vezeteknev[15];
                  printf("Adja meg a keresett nevet:\n");
                  scanf(" %s %s", vezeteknev, keresztnev);
                  sprintf(nev, "%s %s", vezeteknev, keresztnev);
                  nevkeres(nev);
                  break;
            case'2':
                  system("cls");
                  char *telefonszam;
                  printf("Adja meg a keresett telefonszamot:\n");
                  scanf(" %s", telefonszam);
                  telefonszamkeres(telefonszam);
                  break;
            case'3':
                  system("cls");
                  printf("Adja meg a modositando rekordnak a nevet:\n");
                  char *modositnev;
                  char modositkeresztnev[15];
                  char modositvezeteknev[15];
                  scanf(" %s %s", modositvezeteknev, modositkeresztnev);
                  sprintf(modositnev, "%s %s", modositvezeteknev, modositkeresztnev);
                  modosit(modositnev);
                  break;
            case'4':
                  torles();
                  break;
            case'5':
                  letrehoz();
                  break;
            case'6':
                  rekordkilistazas();
                  break;
            case'9':
                  menu=false;
                  exit(1);
                  break;
            default:
                  printf("Ervenytelen valasz.\n");
                  break;
      }
            }while(menu);

      return 0;
}
