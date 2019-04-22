#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jeu.h"

void jeu(signed char *mSecret, signed char *mCacher, int *nbL)
{
    signed char lettreJoueur = 0;
    int nbCoups = 10;

    *nbL = strlen(mSecret); //Compte le nombre de caractères du mot
    for(int f=0; f<*nbL; f++)
    {
        mCacher[f] = '*';
    }

    while (strchr(mCacher, '*') != NULL && nbCoups != 0)
    {
        printf("\n");
        drawPendu(nbCoups); //Figure du pendu qui se dessine
        printf("Mot cacher : %s\n", mCacher);

        printf("Il vous reste %d coup !\n", nbCoups);

        printf("Taper une lettre : ");
        while(getchar() != '\n'); //Liberer le Buffer (Charactère gardé en mémoire)
        scanf("%c", &lettreJoueur);
        convertMajLettre(&lettreJoueur);
        printf("lettre : %c\n", lettreJoueur);

        if((strchr(mSecret, lettreJoueur)) == NULL)
        {
            nbCoups--;
        }
        else
        {
            for(int i=0; mSecret[i] != '\0'; i++) //Remplacement des * par les lettres trouvé
            {
                if(mSecret[i] == lettreJoueur)
                {
                    mCacher[i] = lettreJoueur;
                }
            }
        }
    }

    if(nbCoups != 0)
    {
        printf("Bravo vous avez gagnez le mot cacher etais : %s\n\n", mSecret);
    }
    else
    {
        drawPendu(nbCoups);
        printf("Vous avez perdu !\n");
        printf("Le mot etait : %s\n\n", mSecret);
    }
}

int drawPendu(int coups)
{
    switch (coups)
    {
    case 9:
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|__\n\n");
        
        break;
    
    case 8:
        printf("|/\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|__\n\n");

        break;

    case 7:
        printf("_________\n");
        printf("|/\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|__\n\n");

        break;
    
    case 6:
        printf("_________\n");
        printf("|/      |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|__\n\n");

        break;
    
    case 5:
        printf("_________\n");
        printf("|/      |\n");
        printf("|       O\n");
        printf("|\n");
        printf("|\n");
        printf("|__\n\n");

        break;

    case 4:
        printf("_________\n");
        printf("|/      |\n");
        printf("|       O\n");
        printf("|       |\n");
        printf("|\n");
        printf("|__\n\n");

        break;
    
    case 3:
        printf("_________\n");
        printf("|/      |\n");
        printf("|       O\n");
        printf("|      /|\n");
        printf("|\n");
        printf("|__\n\n");

        break;
    
    case 2:
        printf("_________\n");
        printf("|/      |\n");
        printf("|       O\n");
        printf("|      /|\\\n");
        printf("|\n");
        printf("|__\n\n");

        break;
    
    case 1:
        printf("_________\n");
        printf("|/      |\n");
        printf("|       O\n");
        printf("|      /|\\\n");
        printf("|      / \n");
        printf("|__\n\n");

        break;

    case 0:
        printf("_________\n");
        printf("|/      |\n");
        printf("|       O\n");
        printf("|      /|\\\n");
        printf("|      / \\\n");
        printf("|__\n\n");

        break;
    
    default:
        printf("___\n\n");
        break;
    }
}

void convertMajLettre(char *lettreMin)
{
    *lettreMin = toupper(*lettreMin);
}