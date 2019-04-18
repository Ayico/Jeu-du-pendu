#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "selectMot.h"

int selectMot(char *motPioche)
{
    FILE *dico = fopen("dico.txt", "r"); //Ouverture et lecture du fichier dico.txt
    int nbMots = 0;
    int caractereLu = 0;
    int numChoisi = 0;

    if(dico == NULL)
        exit(1);

    do  //Recherche le nombre de mots dans le fichier dico.txt
    {
        caractereLu = fgetc(dico); //fgetc parcours les caractères du doc
        if(caractereLu == '\n')
            nbMots++;
    } while (caractereLu != EOF); //Tant que l'on atteind pas la fin du fichier (EOF) la boucle continue

    numChoisi = nbAlea(nbMots);

    rewind(dico); //Lecture du document dico.txt depuis le début

    while (numChoisi > 0) //Boucle qui atteind la ligne en fonction du numéro demandé
    {
        caractereLu = fgetc(dico);
        if(caractereLu == '\n')
            numChoisi--;
    }

    fgets(motPioche, 100, dico); //fgets parcours la ligne

    motPioche[strlen(motPioche) - 1] = '\0'; //Remplace le dernier caractère de la ligne (\n) par la fin de la chaine = \0

    fclose(dico);

    return 1;
}

int nbAlea(int nbMax)
{
    srand(time(NULL));
    return (rand() % nbMax);
}