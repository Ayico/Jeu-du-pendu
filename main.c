#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selectMot.h"
#include "jeu.h"
#include <ctype.h>

//Ajouter mode 2 joueurs

int menu();
void convetMajMot(signed char *motMin);

int main(void)
{
    signed char motSecret[100] = {0};
    signed char motCacher[100] = {0};
    int nbLettre = 0;
    int sortir = 0;
    char sortirJeu = 'N';

    while(sortir != 1)
    {
        switch (menu())
        {
            case 1: { //Mode 1 joueur
                if(sortirJeu == 'N')
                    sortirJeu = 'M';

                while (sortirJeu != 'N')
                {
                    nbLettre = 0;
                    memset(motCacher, 0, sizeof(motCacher));

                    selectMot(motSecret);
                    jeu(motSecret, motCacher, &nbLettre);

                    printf("Voulez-vous rejouer ? (O/N) ");
                    while(getchar() != '\n'); //Liberer le Buffer (Charactère gardé en mémoire)
                    scanf("%c", &sortirJeu);
                    convertMajLettre(&sortirJeu);
                    printf("\n\n");
                }
                
                break;
            }

            case 2: { //Mode 2 joueurs
                if(sortirJeu == 'N')
                    sortirJeu = 'M';
                
                while (sortirJeu != 'N')
                {
                    nbLettre = 0;
                    memset(motCacher, 0, sizeof(motCacher));

                    printf("Joueur 1 taper le mot secret : ");
                    scanf("%s", motSecret);
                    convetMajMot(motSecret);
                    
                    for(int e = 0; e < 1000; e++)
                        printf("\n"); //Cacher la saisie du joueur 1

                    jeu(motSecret, motCacher, &nbLettre);

                    printf("Voulez-vous rejouer ? (O/N) ");
                    while(getchar() != '\n'); //Liberer le Buffer (Charactère gardé en mémoire)
                    scanf("%c", &sortirJeu);
                    convertMajLettre(&sortirJeu);
                    printf("\n\n");
                }
                break;
            }
            
            case 3: { //Mode Ajout de mots
                if(sortirJeu == 'N')
                    sortirJeu = 'M';

                while (sortirJeu != 'N')
                {
                    FILE *dico = fopen("dico.txt", "r+"); //Mode d'ouverture du fichier "a" est pour ajouter des éléments à le fin du fichier
                    signed char newMot[26];
                    signed char ligneLu[100] = "";
                    int motIdentique = 0;
                    int motValide = 0;
                    
                    while (motValide == 0)
                    { 
                        printf("Ajoute un mot dans le dictionnaire du jeu a faire deviner : ");
                        scanf("%s", newMot);
                        convetMajMot(newMot);

                        rewind(dico);

                        while (fgets(ligneLu, 1000, dico) != NULL) //Verification si le mot existe déjà
                        {
                            if(strstr(ligneLu, newMot) != NULL) {
                                motIdentique++;
                            }
                        }

                        if(motIdentique == 0)
                        {
                            fputs(newMot, dico);
                            fseek(dico, 0, SEEK_END); //Place le curseur à la fin du fichier
                            fputs("\n", dico); //Ajout d'un saut de ligne après l'ajout du nouveau mot
                            motValide++;
                        }
                        else
                        {
                            printf("Ce mot existe deja !\n");
                            motIdentique = 0;
                        }             
                    }

                    motValide = 0;
                    fclose(dico);

                    printf("Voulez-vous ajouter un autre mot ? (O/N) ");
                    while(getchar() != '\n'); //Liberer le Buffer (Charactère gardé en mémoire)
                    scanf("%c", &sortirJeu);
                    convertMajLettre(&sortirJeu);
                    printf("\n\n");
                }
                break;
            }

            case 4: { //Quitter le programme
                sortir++;
                break;
            }
        
            default:
                printf("Erreur veuillez redemarrer le programme...");
                break;
        }
    }
    return 0;
}

int menu()
{
    int choix;

    while(choix < 1 || choix > 4) {
        printf("Menu :\n\n");
        printf("1: Jouer au pendu.\n");
        printf("2: Mode 2 joueurs.\n");
        printf("3: Ajouter des mots.\n");
        printf("4: Quitter.\n");
        printf("Select > ");
        scanf("%d", &choix);
        printf("\n\n");
    }

    return choix;
}

void convetMajMot(signed char *motMin)
{
    for (int i = 0; motMin[i] != '\0'; i++)
    {
        motMin[i] = toupper(motMin[i]);
    }
}