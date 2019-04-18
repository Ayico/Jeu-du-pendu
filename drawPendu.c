#include <stdio.h>
#include "drawPendu.h"

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