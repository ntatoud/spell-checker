#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "IHM.h"

int main(int argc, char **argv)
{

    if (argc <= 2 || argc > 5)
    {
        if (argc == 2)
            gererCommandeAide(argv[1]);
        else
            gererCommandeAide("");
    }

    else if (argc == 3)
    {
        gererCommandeCorrection(argv[1], argv[2]);
    }

    else if (argc == 5)
    {
        gererCommandeCreerDico(argv[1], argv[2], argv[3], argv[4]);
    }

    return EXIT_SUCCESS;
}