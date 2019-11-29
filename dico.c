#ifndef DICO
#define DICO


#include "dico.h"


void trouverMot(char *mot){
    FILE *dico;
    dico = fopen("dico.txt","r");

    if(dico!=NULL){
            int nombreMot = 0;
            while(fgets(mot,15,dico)!=NULL)nombreMot++;
            rewind(dico);
            int motChoisi = nombreAleatoire(nombreMot);
            for(int i =0; i<motChoisi; i++){
                fgets(mot,15,dico);

            }
            mot[strlen(mot)-1] = '\0';

    fclose(dico);
    }
    else{
        mot = "MARRON";
    }


}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}
#endif
