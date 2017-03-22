#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "constante.h"
#include "vie.h"




void seDeplacer(Entite etre[],int taille)
{
 int i=0;
 int MIN=DROITE;
 int MAX=HAUT;
 
     for(i=0;i<taille;i++)
     {
      etre[i].direction=(rand()%(MAX-MIN+1))+MIN;
      seDeplace(&etre[i]);
     }
}
void seDeplace(Entite *etre)
{
     switch(etre->direction)
     {
      case DROITE:
           if(etre->donnees.age==ENFANT
           &&etre->mere!=NULL&&etre->mere->vie>0)
           {
                   if(etre->pos.x<etre->mere->pos.x+4*TAILLE_BLOC
                   &&etre->pos.x<LARGEUR-TAILLE_BLOC)
                   {
                    etre->pos.x++;
                   }
           }
           else if(etre->pos.x<LARGEUR-TAILLE_BLOC)
           {
            etre->pos.x++;
           }
           break;
      case BAS:
           if(etre->donnees.age==ENFANT
           &&etre->mere!=NULL&&etre->mere->vie>0)
           {
                   if(etre->pos.y<etre->mere->pos.y+4*TAILLE_BLOC
                   &&etre->pos.y<HAUTEUR-TAILLE_BLOC)
                   {
                    etre->pos.y++;
                   }
           }
           else if(etre->pos.y<HAUTEUR-TAILLE_BLOC)
           {
            etre->pos.y++;
           }
           break;
      case GAUCHE:
           if(etre->donnees.age==ENFANT
           &&etre->mere!=NULL&&etre->mere->vie>0)
           {
                   if(etre->pos.x>etre->mere->pos.x-4*TAILLE_BLOC
                   &&etre->pos.x>0)
                   {
                    etre->pos.x--;
                   }
           }
           else if(etre->pos.x>0)
           {
            etre->pos.x--;
           }
           break;
      case HAUT:
           if(etre->donnees.age==ENFANT
           &&etre->mere!=NULL&&etre->mere->vie>0)
           {
                   if(etre->pos.y>etre->mere->pos.y-4*TAILLE_BLOC
                   &&etre->pos.y>0)
                   {
                    etre->pos.y--;
                   }
           }
           else if(etre->pos.y>0)
           {
            etre->pos.y--;
           }
           break;
     }
}



int seReproduire(Entite etre[],int taille)
{
 int i=0;
 int j=0;
 //int variable;
     for(i=0;i<taille;i++)
     {
           for(j=0;j<taille;j++)
           {
                if(etre[i].pos.x==etre[j].pos.x
                &&etre[i].pos.y==etre[j].pos.y
                &&etre[i].donnees.age==ADULTE
                &&etre[j].donnees.age==ADULTE
                &&etre[i].donnees.sexe==MASCULIN
                &&etre[j].donnees.sexe==FEMININ)
                {
                             if(etre[j].gestation==APTE)
                             {
                              seReproduit(&etre[taille],&etre[i],&etre[j],taille);
                             }
                       taille++;
                }
           }
     }
 return taille;
}

void seReproduit(Entite *etre,Entite *pere,Entite *mere,int taille)
{
     switch(pere->donnees.tribu)
     {
      case ROUGE:
           creerEntite(etre,taille,1);
           tribuRouge(etre,mere);
           mere->gestation=ENCEINTE;
           mere->grossesse=1000;
           etre->donnees.vivre=NAISSANCE;
           break;
      case VERT:
           creerEntite(etre,taille,1);
           tribuVerte(etre,mere);
           mere->gestation=ENCEINTE;
           mere->grossesse=1000;
           etre->donnees.vivre=NAISSANCE;
           break;
      case BLEU:
           creerEntite(etre,taille,1);
           tribuBleue(etre,mere);
           mere->gestation=ENCEINTE;
           mere->grossesse=1000;
           etre->donnees.vivre=NAISSANCE;
           break;
    }
}


