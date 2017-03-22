#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "constante.h"


void initialiserEntite(Entite etre[],int taille)
{
 int i=0;
     for(i=0;i<taille;i++)
     {
      initialiseEntite(&etre[i]);
     }
}

void initialiseEntite(Entite *etre)
{
 etre->vie=-1;
 etre->jour=-1;
 etre->annee=-1;
 /*etre->age=-1;*/
 etre->donnees.tribu=-1;
 etre->donnees.sexe=-1;
 etre->donnees.age=-1;
 /*
 etre->vivre=-1;*/
 
 etre->gestation=-1;
 etre->grossesse=-1;
 
 etre->direction=-1;
 /*
 etre->genome=NULL;
 etre->mere=NULL;
 etre->pere=NULL;*/
}



void creerEntite(Entite etre[],int taille,int nombreEntite)
{
 int i=0;
 int ok=nombreEntite;
     for(i=0;i<taille;i++)
     {
           if(etre[i].vie<=0&&nombreEntite>0)
           {
            creeEntite(&etre[i]);
            nombreEntite--;/*
            determineTribu(&etre[i]);*/
           }
     }
     if(nombreEntite==ok)
     {
          do
          {
           creeEntite(&etre[taille]);
           taille++;nombreEntite--;
          }while(nombreEntite>0);
     }
}

void creeEntite(Entite *etre)
{
 int MIN=60000;
 int MAX=100000;
 etre->vie=(rand()%(MAX-MIN+1))+MIN;
 etre->jour=0;
 etre->annee=0;
 /*etre->age=0;*/
 
 etre->donnees.age=ENFANT;
 etre->vivre=NEANT;
 etre->mourir=NEANT;
 
 
 etre->gestation=0;
 etre->grossesse=0;
 
 etre->direction=AUCUNE;
 MIN=0;
 MAX=LARGEUR-TAILLE_BLOC;
 etre->pos.x=(rand()%(MAX-MIN+1))+MIN;
 MIN=0;
 MAX=HAUTEUR-TAILLE_BLOC;
 etre->pos.y=(rand()%(MAX-MIN+1))+MIN;
 /*
 etre->genome=NULL;
 etre->mere=NULL;
 etre->pere=NULL;*/
}


void determinerTribu(Entite *etre,int taille)
{
 int i=0;
     for(i=0;i<taille;i++)
     {
      determineTribu(&etre[i]);
     }
}

void determineTribu(Entite *etre)
{
 int MIN=0;
 int MAX=1200;
 int j=(rand()%(MAX-MIN+1))+MIN;
     if(j<400)
     {etre->donnees.tribu=ROUGE;}
     else if(j<800)
     {etre->donnees.tribu=VERT;}
     else
     {etre->donnees.tribu=BLEU;}
 
 MIN=0;
 MAX=200;
 j=(rand()%(MAX-MIN+1))+MIN;
     if(j<100)
     {etre->donnees.sexe=MASCULIN;}
     else
     {etre->donnees.sexe=FEMININ;}
 /*
 MIN=0;
 MAX=LARGEUR;
 etre->pos.x=(rand()%(MAX-MIN+1))+MIN;
 MIN=0;
 MAX=HAUTEUR;
 etre->pos.y=(rand()%(MAX-MIN+1))+MIN;*/
}



void tribuRouge(Entite *etre,Entite *mere)
{
 etre->mere=mere;
 etre->donnees.tribu=ROUGE;
 
 int MIN=MASCULIN;
 int MAX=FEMININ;
 etre->donnees.sexe=(rand()%(MAX-MIN+1))+MIN;

  MIN=etre->mere->pos.x-40;
  MAX=etre->mere->pos.x+40;
  etre->pos.x=(rand()%(MAX-MIN+1))+MIN;
  
  MIN=etre->mere->pos.y-40;
  MAX=etre->mere->pos.y+40;
  etre->pos.y=(rand()%(MAX-MIN+1))+MIN;
}

void tribuVerte(Entite *etre,Entite *mere)
{
 etre->mere=mere;
 etre->donnees.tribu=VERT;
 
 int MIN=MASCULIN;
 int MAX=FEMININ;
 etre->donnees.sexe=(rand()%(MAX-MIN+1))+MIN;
 
  MIN=etre->mere->pos.x-40;
  MAX=etre->mere->pos.x+40;
  etre->pos.x=(rand()%(MAX-MIN+1))+MIN;
  
  MIN=etre->mere->pos.y-40;
  MAX=etre->mere->pos.y+40;
  etre->pos.y=(rand()%(MAX-MIN+1))+MIN;
}

void tribuBleue(Entite *etre,Entite *mere)
{
 etre->mere=mere;
 etre->donnees.tribu=BLEU;
 
 int MIN=MASCULIN;
 int MAX=FEMININ;
 etre->donnees.sexe=(rand()%(MAX-MIN+1))+MIN;
 
  MIN=etre->mere->pos.x-40;
  MAX=etre->mere->pos.x+40;
  etre->pos.x=(rand()%(MAX-MIN+1))+MIN;
  
  MIN=etre->mere->pos.y-40;
  MAX=etre->mere->pos.y+40;
  etre->pos.y=(rand()%(MAX-MIN+1))+MIN;
}














void afficherEntite(SDL_Surface *ecran,Entite etre[],int taille)
{
 int i=0;
 
     for(i=0;i<taille;i++)
     {
      afficheEntite(ecran,&etre[i]);
     }
 
}



void afficheEntite(SDL_Surface *ecran,Entite etre[])
{
 SDL_Surface *bloc;
 bloc=SDL_CreateRGBSurface(SDL_HWSURFACE,TAILLE_BLOC,TAILLE_BLOC,32,0,0,0,0);

	  if(etre->donnees.age==VIEUX)
	  {
	  SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,200,200,200));
	  SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
	  }
	  else
	  {
           switch(etre->donnees.tribu)
           {
            case ROUGE:
                 switch(etre->donnees.sexe)
                 {
                  case MASCULIN:
                       SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,255,0,0));
                       SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                       break;
                  case FEMININ:
                       SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,255,74,88));
                       SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                       break;
                 }
                 if(etre->donnees.age==ENFANT)
                 {
                  SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,255,255,0));
                  SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                 }
                 break;
            case VERT:
                 switch(etre->donnees.sexe)
                 {
                  case MASCULIN:
                       SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,0,153,0));
                       SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                       break;
                  case FEMININ:
                       SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,0,255,0));
                       SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                       break;
                 }
                 if(etre->donnees.age==ENFANT)
                 {
                  SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,255,255,0));
                  SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                 }
                 break;
            case BLEU:
                 switch(etre->donnees.sexe)
                 {
                  case MASCULIN:
                       SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,0,0,255));
                       SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                       break;
                  case FEMININ:
                       SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,0,255,255));
                       SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                       break;
                 }
                 if(etre->donnees.age==ENFANT)
                 {
                  SDL_FillRect(bloc,NULL,SDL_MapRGB(ecran->format,255,255,0));
                  SDL_BlitSurface(bloc,NULL,ecran,&etre->pos);
                 }
                 break;
           }
	  }
 
 SDL_FreeSurface(bloc);
}


void afficheCompteur(SDL_Surface *ecran,Entite etre[],int taille,int *jour)
{
 SDL_Surface *tableau;
 //int i=0;
 //int nombre=0;
 SDL_Rect pos;
 
 tableau=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_CADRE,HAUTEUR,32,0,0,0,0);
 SDL_FillRect(tableau,NULL,SDL_MapRGB(ecran->format,255,255,255));
 
 compteurG(tableau,etre,taille,jour);
 /*compteurRouge(tableau,etre,taille);
 compteurVert(tableau,etre,taille);
 compteurBleu(tableau,etre,taille);*/
 
 pos.x=LARGEUR_ECRAN-tableau->w;
 pos.y=0;
 SDL_BlitSurface(tableau,NULL,ecran,&pos);
 
 SDL_FreeSurface(tableau);
}

void compteurG(SDL_Surface *ecran,Entite etre[],int taille,int *jour)
{
 int i=0;
 static int mois=0;
 static int annees=0;
 //int population=0;
 int vivant=0;
 int enfant=0;
 int adulte=0;
 int male=0;
 int femelle=0;
 int vieux=0;
 int naissance=0;
 int deces=0;
 char donnees[10]={0};
 TTF_Font *police;
 TTF_Font *Titre;
 SDL_Color noir={0,0,0};
 SDL_Color Rouge={255,0,0};
 SDL_Rect pos;
 
 SDL_Surface *texte=NULL;
 SDL_Surface *cadre;
 
 
     for(i=0;i<taille;i++)
     {
      if(etre[i].vie>0){vivant++;}
      if(etre[i].donnees.vivre==NAISSANCE){naissance++;}
      if(etre[i].donnees.mourir==DECES){deces++;}
      if(etre[i].donnees.age==ENFANT){enfant++;}
      else if(etre[i].donnees.age==ADULTE
      &&etre[i].donnees.sexe==MASCULIN){adulte++;male++;}
      else if(etre[i].donnees.age==ADULTE
      &&etre[i].donnees.sexe==FEMININ){adulte++;femelle++;}
      else if(etre[i].donnees.age==VIEUX){vieux++;}
     }
 
 police=TTF_OpenFont("arial.ttf",20);
 Titre=TTF_OpenFont("arial.ttf",30);
 
 cadre=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_CADRE,HAUTEUR/4,32,0,0,0,0);
 SDL_FillRect(cadre,NULL,SDL_MapRGB(ecran->format,255,255,255));
 //SDL_SetColorKey(cadre,SDL_SRCCOLORKEY,SDL_MapRGB(cadre->format,255,255,255));
 
 if(*jour==100){mois++;*jour=0;}
 if(mois==10){annees++;mois=0;}
 
 sprintf(donnees,"DONNEES GENERALES:");
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(Titre,donnees,Rouge);
 pos.x=(cadre->w-texte->w)/2;
 pos.y=0;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Jour: %d",*jour);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=25;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Mois: %d",mois);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=50;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Année: %d",annees);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=75;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Population: %d",vivant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=100;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Enfant(s): %d",enfant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=25;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Adulte(s): %d",adulte);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=50;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vieux: %d",vieux);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=75;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Naissance(s): %d",naissance);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=125;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Décès(s): %d",deces);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=125;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 pos.x=0;
 pos.y=0;
 SDL_BlitSurface(cadre,NULL,ecran,&pos);
 
 TTF_CloseFont(Titre);
 TTF_CloseFont(police);
 SDL_FreeSurface(cadre);
 SDL_FreeSurface(texte);
}

void compteurRouge(SDL_Surface *ecran,Entite etre[],int taille)
{
 int i=0;
 int rouge=0;
 int vivant=0;
 int enfant=0;
 int adulte=0;
 int male=0;
 int femelle=0;
 int vieux=0;
 int naissance=0;
 int deces=0;
 char donnees[10]={0};
 TTF_Font *police;
 TTF_Font *Titre;
 SDL_Color noir={0,0,0};
 SDL_Color Rouge={255,0,0};
 SDL_Rect pos;
 
 SDL_Surface *texte=NULL;
 SDL_Surface *cadre;
 
 police=TTF_OpenFont("arial.ttf",20);
 Titre=TTF_OpenFont("arial.ttf",30);
 
 cadre=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_CADRE,HAUTEUR/4,32,0,0,0,0);
 SDL_FillRect(cadre,NULL,SDL_MapRGB(ecran->format,255,255,255));
 SDL_SetColorKey(cadre,SDL_SRCCOLORKEY,SDL_MapRGB(cadre->format,255,255,255));
 
     for(i=0;i<taille;i++)
     {
            if(etre[i].donnees.tribu==ROUGE)
            {
             rouge++;
                  if(etre[i].vie>0){vivant++;}
                  if(etre[i].donnees.vivre==NAISSANCE){naissance++;}
                  else if(etre[i].donnees.mourir==DECES){deces++;}
                  if(etre[i].donnees.age==ENFANT){enfant++;}
                  else if(etre[i].donnees.age==ADULTE){adulte++;}
                  else if(etre[i].donnees.age==VIEUX){vieux++;}
                  if(etre[i].donnees.age==ADULTE
                  &&etre[i].donnees.sexe==MASCULIN){male++;}
                  else if(etre[i].donnees.age==ADULTE
                  &&etre[i].donnees.sexe==FEMININ){femelle++;}
            }
     }
 sprintf(donnees,"Données Tribu ROUGE: %d",rouge);
 texte=TTF_RenderText_Blended(Titre,donnees,Rouge);
 pos.x=(cadre->w-texte->w)/2;
 pos.y=0;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vivant(s): %d",vivant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=30;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Naissance(s): %d",naissance);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=120;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Mâle(s): %d",male);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=60;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Décès: %d",deces);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;;
 pos.y=120;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Enfant(s): %d",enfant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=30;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Adulte(s): %d",adulte);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=60;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Femelle(s): %d",femelle);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=90;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vieux: %d",vieux);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=90;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 pos.x=0;
 pos.y=cadre->h;
 SDL_BlitSurface(cadre,NULL,ecran,&pos);
 
 TTF_CloseFont(Titre);
 TTF_CloseFont(police);
 SDL_FreeSurface(cadre);
 SDL_FreeSurface(texte);
}

void compteurVert(SDL_Surface *ecran,Entite etre[],int taille)
{
 int i=0;
 int vert=0;
 int vivant=0;
 int enfant=0;
 int adulte=0;
 int male=0;
 int femelle=0;
 int vieux=0;
 int naissance=0;
 int deces=0;
 char donnees[10]={0};
 TTF_Font *police;
 TTF_Font *Titre;
 SDL_Color noir={0,0,0};
 SDL_Color Rouge={255,0,0};
 SDL_Rect pos;
 
 SDL_Surface *texte=NULL;
 SDL_Surface *cadre;
 
 police=TTF_OpenFont("arial.ttf",20);
 Titre=TTF_OpenFont("arial.ttf",30);
 
 cadre=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_CADRE,HAUTEUR/4,32,0,0,0,0);
 SDL_FillRect(cadre,NULL,SDL_MapRGB(ecran->format,255,255,255));
 SDL_SetColorKey(cadre,SDL_SRCCOLORKEY,SDL_MapRGB(cadre->format,255,255,255));
 
     for(i=0;i<taille;i++)
     {
            if(etre[i].donnees.tribu==VERT)
            {
             vert++;
                  if(etre[i].vie>0){vivant++;}
                  if(etre[i].donnees.vivre==NAISSANCE){naissance++;}
                  else if(etre[i].donnees.mourir==DECES){deces++;}
                  if(etre[i].donnees.age==ENFANT){enfant++;}
                  else if(etre[i].donnees.age==ADULTE){adulte++;}
                  else if(etre[i].donnees.age==VIEUX){vieux++;}
                  if(etre[i].donnees.age==ADULTE
                  &&etre[i].donnees.sexe==MASCULIN){male++;}
                  else if(etre[i].donnees.age==ADULTE
                  &&etre[i].donnees.sexe==FEMININ){femelle++;}
            }
     }
 sprintf(donnees,"Données Tribu VERTE: %d",vert);
 texte=TTF_RenderText_Blended(Titre,donnees,Rouge);
 pos.x=(cadre->w-texte->w)/2;
 pos.y=0;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vivant(s): %d",vivant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=30;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Naissance(s): %d",naissance);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=120;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Mâle(s): %d",male);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=60;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Décès: %d",deces);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;;
 pos.y=120;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Enfant(s): %d",enfant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=30;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Adulte(s): %d",adulte);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=60;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Femelle(s): %d",femelle);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=90;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vieux: %d",vieux);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=90;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 pos.x=0;
 pos.y=cadre->h*2;
 SDL_BlitSurface(cadre,NULL,ecran,&pos);
 
 TTF_CloseFont(Titre);
 TTF_CloseFont(police);
 SDL_FreeSurface(cadre);
 SDL_FreeSurface(texte);
}

void compteurBleu(SDL_Surface *ecran,Entite etre[],int taille)
{
 int i=0;
 int bleu=0;
 int vivant=0;
 int enfant=0;
 int adulte=0;
 int male=0;
 int femelle=0;
 int vieux=0;
 int naissance=0;
 int deces=0;
 char donnees[10]={0};
 TTF_Font *police;
 TTF_Font *Titre;
 SDL_Color noir={0,0,0};
 SDL_Color Rouge={255,0,0};
 SDL_Rect pos;
 
 SDL_Surface *texte=NULL;
 SDL_Surface *cadre;
 
 police=TTF_OpenFont("arial.ttf",20);
 Titre=TTF_OpenFont("arial.ttf",30);
 
 cadre=SDL_CreateRGBSurface(SDL_HWSURFACE,LARGEUR_CADRE,HAUTEUR/4,32,0,0,0,0);
 SDL_FillRect(cadre,NULL,SDL_MapRGB(ecran->format,255,255,255));
 SDL_SetColorKey(cadre,SDL_SRCCOLORKEY,SDL_MapRGB(cadre->format,255,255,255));
 
     for(i=0;i<taille;i++)
     {
            if(etre[i].donnees.tribu==BLEU)
            {
             bleu++;
                  if(etre[i].vie>0){vivant++;}
                  if(etre[i].donnees.vivre==NAISSANCE){naissance++;}
                  else if(etre[i].donnees.mourir==DECES){deces++;}
                  if(etre[i].donnees.age==ENFANT){enfant++;}
                  else if(etre[i].donnees.age==ADULTE){adulte++;}
                  else if(etre[i].donnees.age==VIEUX){vieux++;}
                  if(etre[i].donnees.age==ADULTE
                  &&etre[i].donnees.sexe==MASCULIN){male++;}
                  else if(etre[i].donnees.age==ADULTE
                  &&etre[i].donnees.sexe==FEMININ){femelle++;}
            }
     }
 sprintf(donnees,"Données Tribu BLEUE: %d",bleu);
 texte=TTF_RenderText_Blended(Titre,donnees,Rouge);
 pos.x=(cadre->w-texte->w)/2;
 pos.y=0;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vivant(s): %d",vivant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=30;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Naissance(s): %d",naissance);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=120;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Mâle(s): %d",male);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=60;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Décès: %d",deces);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;;
 pos.y=120;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Enfant(s): %d",enfant);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=30;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Adulte(s): %d",adulte);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=60;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Femelle(s): %d",femelle);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=0;
 pos.y=90;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 sprintf(donnees,"Vieux: %d",vieux);
 SDL_FreeSurface(texte);
 texte=TTF_RenderText_Blended(police,donnees,noir);
 pos.x=cadre->w-texte->w;
 pos.y=90;
 SDL_BlitSurface(texte,NULL,cadre,&pos);
 
 pos.x=0;
 pos.y=cadre->h*3;
 SDL_BlitSurface(cadre,NULL,ecran,&pos);
 
 TTF_CloseFont(Titre);
 TTF_CloseFont(police);
 SDL_FreeSurface(cadre);
 SDL_FreeSurface(texte);
}



void miseAJour(Entite etre[],int taille)
{
 int i=0;
 
     for(i=0;i<taille;i++)
     {
      metAJour(&etre[i]);
     }
}
void metAJour(Entite *etre)
{
 etre->jour++;
 if(etre->jour==1000){etre->annee++;etre->jour=0;}
 if(etre->annee>5&&etre->gestation!=ENCEINTE&&etre->annee<80){etre->donnees.age=ADULTE;etre->gestation=APTE;}
 else if(etre->annee>80){etre->donnees.age=VIEUX;}
 /*
 int vivre;
 int mourir;*/
 
 if(etre->gestation==ENCEINTE)
 {etre->grossesse--;
 if(etre->grossesse==0)
 {etre->gestation=APTE;}}
 /*
 etre->direction;
 etre->pos;
 
 etre->donnees;
 etre->mere;*/
 etre->vie--;
 if(etre->vie==0)
 {
  initialiseEntite(etre);
  etre->donnees.mourir=DECES;
 }
}




void degrade(SDL_Surface *ecran)
{
 //int i,j,l=0;
 //int k=255;
 SDL_Surface *pix;
 //SDL_Rect pos;
 
 /*pos.x=0;
 pos.y=0;*/
 
 pix=SDL_CreateRGBSurface(SDL_HWSURFACE,(ecran->w)+1,(ecran->h)+1,32,0,0,0,0);
 SDL_FillRect(pix,NULL,SDL_MapRGB(ecran->format,0,0,0));
 /*
 for(i=0;i<255;i++)
 {
  pos.x=0;
  k=255;
  l=0;
        for(j=0;j<255;j++)
        {l=k;
             if((i+j)<=255)
             {
              SDL_FillRect(pix,NULL,SDL_MapRGB(ecran->format,k,k,k));
              k--;
             }
             else
             {
              SDL_FillRect(pix,NULL,SDL_MapRGB(ecran->format,l,l,l));
              l++;
             }
             SDL_BlitSurface(pix,NULL,ecran,&pos);
             pos.x+=pix->w;
        }
  pos.y+=pix->h;
 }
 */
 
 SDL_FreeSurface(pix);
}

