#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void setfichier();
void choisirmot(char mot[100]);

int main()
{
    int nbjoueur=0;
    char mot[100]=" ";
    do
    {
        printf("voulez vous jouer a 1 ou a 2 ?");
        scanf("%d", &nbjoueur);
    }while(nbjoueur!=1 && nbjoueur!=2);
    if(nbjoueur==1)
    {
       setfichier();
       choisirmot(mot);
       getchar();
    }
    else
    {
        printf("l'un des joueurs entre un mot en majuscule : ");
        scanf("%s", mot);
        getchar();
        system("cls");
    }
    char lettre;
    int taille=0, i, vie=10, nullos=0, victoire, gagne=1, perdu=1;
    taille=strlen(mot);
    char *essai=NULL;
    essai=malloc(taille*sizeof(char));

    for(i=0; i<taille; i++)
    {
        essai[i]='*';
    }
    essai[taille]='\0';
    do
    {
        nullos=0;
        victoire=0;
        printf("il vous reste %d vies", vie);
        printf("\nmot=%s", essai);
        printf("\nnouvelle lettre (en majuscule stp ) : ");
        scanf("%c", &lettre);
        getchar();
        for(i=0; i<taille; i++)
        {
            if(mot[i]==lettre){essai[i]=lettre;}
            else {nullos++;}
        }
        if (nullos==i){vie--;}
        if(vie==0){perdu=0;}
        for(i=0; i<taille; i++){if(essai[i]==mot[i]){victoire++;}}//if(!strcmp(essai,mot)){gagne=0;}
        if(victoire==i){gagne=0;}
    }while(gagne!=0 && perdu!=0);
    if(gagne==0)
    {
        system("cls");
        printf("\t\tVOUS AVEZ GAGNE");
        printf("\nVOUS AVEZ TROUVE LE MOT <<%s>>", mot);
        printf("\nC'EST PAS TOUT LE MONDE QUI Y ARRIVE");
        return 0;
    }
    if(perdu==0)
    {
        system("cls");
        printf("\t\t\tVOUS AVEZ PERDU");
        printf("\n\t\t A UN JEU POUR ENFANT DE 8 ANS");
        printf("\n\t\t\tGROS NULLOS");
        printf("\nLe mot etait %s", mot);
    }
    free(essai);
    return 0;
}

void setfichier()
{
    FILE *f=NULL;
    f=fopen("mot.txt" , "w");
    if(f==NULL)
    {
        printf("oupsi");
        exit(0);
    }
    fprintf(f,"INTERRUPTEUR\nASTRONAUTE\nDENSE\nGLACIAL\nINSTALLER\nCHAMPION\nCOMBUSTIBLE\nPOUET\nPRIMITIF\nLOTERIE\nCROUSTILLANT\nDEVORER\nPOTENTIEL\nPARASITE\nDEVASTATION\nRUBIS\nLIQUIDE\nCHEVAL");
    fclose(f);
}

void choisirmot(char mot [100])
{
    int aleatoire=0, nbmot=1, i=0, j=0;
    char lettre=0;
    char azertyuiop[100]=" ";
    FILE *fichier=NULL;
    fichier=fopen("mot.txt", "r");
    if(fichier==NULL)
    {
        printf("zut");
        exit(0);
    }
    for(i=0; i<182; i++)
    {
        lettre=fgetc(fichier);
        if(lettre=='\n'){nbmot++;}
    }
    srand(time(NULL));
    aleatoire=rand()%nbmot;
    rewind(fichier);
    for(i=0; i<aleatoire; i++)
    {
        fgets(azertyuiop, 50, fichier);
    }
    fgets(mot, 50, fichier);
    j=strlen(mot);
    for(i=0; i<j; i++)
    {
        if(mot[i]=='\n'){mot[i]='\0';}
    }
    fclose(fichier);
}

