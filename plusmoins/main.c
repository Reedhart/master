#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int recommencer;
    do
    {
        printf("le but de ce jeu est de trouver un nombre mytere en un minimum de coups\n\n");
        unsigned int nombremystere,MAX,MIN=1,nombredecoups=0, nombre, difficulte, nombredejoueurs;
        // choix du nombre de joueur
        printf("Mode 1 ou 2 joueurs?\n");
        scanf("%d", &nombredejoueurs);
        //on ounaide les petits malins
        if(nombredejoueurs!=1 && nombredejoueurs!=2)
        {
            printf("mauvais numero\n");
            return 0;
        }                   //mode 2 joueurs
        else if(nombredejoueurs==2)
        {
            printf("joueur 1 choisis le nombre mystere\n");
            scanf("%d", &nombremystere);
            do
            {
                printf("joueur 2 choisis un nombre\n");
                scanf("%d", &nombre);
                nombredecoups++;
                if(nombre<nombremystere)
                    printf("c+  ");
                else if(nombre>nombremystere)
                    printf("c-  ");
                else
                    printf("GG mon bro\n");
            }
            while(nombre!=nombremystere);
            printf("victoire en %d coups", nombredecoups);
            return 0;
        }                   ///mode 1 joueur
        //choix de la difficulté
        printf("===difficulte===\n");
        printf("1.facile (entre 1 et 100)\n");
        printf("2.moyen (entre 1 et 1000)\n");
        printf("3.difficile (entre 1 et 10000)\n");
        scanf("%d",&difficulte);
        switch(difficulte)
        {
        case 1:
            MAX=100;
            break;
        case 2:
            MAX=1000;
            break;
        case 3:
            MAX=10000;
            break;
        default:
            printf("tu te crois drole?");
            return 0;
            break;
        }
        //génération du nombre mystère.
        srand(time(NULL));
        nombremystere=(rand()%(MAX-MIN+1))+MIN;
        //la boucle du programme.
        do
        {
            printf("choissez un nombre\n");
            scanf("%d", &nombre);
            nombredecoups++;
            if(nombre<nombremystere)
                printf("c+   ");
            else if(nombre>nombremystere)
                printf("c-   ");
            else
                printf("GG mon bro\n");

        }
        while(nombre!=nombremystere);
        printf("victoire en %d coups\n\n\n\n", nombredecoups);
        printf("voulez-vous recommencer?\n");
        printf("1.OUI\n2.NON\n");
        scanf("%d", &recommencer);
    if (recommencer==1){system("cls");}
    }
    while(recommencer == 1);
    return 0;
}
