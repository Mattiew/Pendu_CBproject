#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "dico.h"

char lire_caractere();
int trouverCar(char car, char * motCache, char * motCacheEtoile);
void creerEtoile(char * motcache, char *motCacheEtoile);

/*

tant que le joueur ne gagne pas ou a encore de la vie:
    On lit le caractere
    On regarde si il est dans le mot:
        si non on enleve une vie, à la deniere vie on arrete

        si oui on affiche les lettres trouvées, si le mot est complet on arrete



*/

int main()
{

    int rejouer = 1;
    printf("Jeu du pendu!\n");
    do{
        //On entre dans la boucle du jeu



        //Initialisation du mot et de la vie
        int vie = 8;
        int gagne = 0;

        char motCache[20] = {0}; //Contiendra le mot caché ex: MARRON
        char motCacheEtoile[20] = {0}; //Contiendra la chaine affichée au joueur ex: ***** ou *A**** ou *A**ON

        trouverMot(motCache);
        creerEtoile(motCache, motCacheEtoile);


        //
        do{
                //On entre dans la boucle de la partie

                printf("Il te reste %d vie(s)\nQuel lettre propose tu? %s\n",vie,motCacheEtoile);
                char entre = lire_caractere();

                vie -= trouverCar(entre, motCache, motCacheEtoile); //on enleve une vie si on ne trouve pas la lettre



                if(strchr(motCacheEtoile,'*')==NULL){ //Lorsqu'il n'y a plus * dans le mot a reveler on a gagné
                        gagne = 1;
                }



        }while(vie != 0 && gagne != 1);

        if (vie==0){
            printf("Desole tu as perdu! Le mot etait %s\n retente ta chance !\n1.Oui\t2.Non",motCache);

        }
        else{
            printf("Bravo tu as gagne !\veux tu rejouer\n1.Oui\t2.Non");

        }
        scanf("\n%d",&rejouer);
        printf("\n\n");
    }while( rejouer == 1);
    return 0;
}

char lire_caractere(){
    char myChar;
    myChar = getchar(); //on lit le premier caractere
    while(getchar() != '\n'); //on vide le buffer
    return myChar;
}

int trouverCar(char car, char *motCache, char *motCacheEtoile){

    car = toupper(car);
    int erreur = 1;

    for(int i = 0; i<strlen(motCache); i++){
        if(motCache[i] == car){
            motCacheEtoile[i] = car; //Si la lettre est la meme on remplace le caractere dans la chaine en etoile. et on dit que erreur vaut 0, on enleve 0 vie
            erreur = 0;
        }

    }

    return erreur; //retourne 1 si la lettre n'est pas presente.


}

void creerEtoile(char * motCache, char *motCacheEtoile){
    int i = 0;
    while(motCache[i] != '\0'){
            motCacheEtoile[i] = '*';
            i++;

    }

    motCacheEtoile[i]='\0';
}

