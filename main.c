#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "constante.h"
#include "vie.h"/*
#include "affichageCompteur.h"*/


int main(int argc, char *argv[])
{
    SDL_Surface *ecran;
    SDL_Event event;
    int continuer=1;
    int ok=1;
    //int i=0;
    int tpsA=0;
    int tpsB=0;
    int delai=100;
    int jours=0;
    //int annees=0;
    int nombreDepart=50;
    srand(time(NULL));
    
    Entite etre[1000];
    int taille=0;
    
    TTF_Init();
    
    SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(LARGEUR_ECRAN,HAUTEUR,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("K.I.D!!!",NULL);
    
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
        
 
 initialiserEntite(etre,taille);
 taille=1;
 creerEntite(etre,taille,taille);
 determinerTribu(etre,taille);
    
    do
    {
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
        degrade(ecran);
        SDL_PollEvent(&event);
            switch(event.type)
            {
             case SDL_QUIT:
                  continuer=0;
                  break;
         case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
               case SDLK_ESCAPE:
                    if(ok){continuer=0;ok=0;}
                    break;
               case SDLK_KP0:
                    if(ok){delai=1000;ok=0;}
                    break;
               case SDLK_KP1:
                    if(ok){delai=500;ok=0;}
                    break;
               case SDLK_KP2:
                    if(ok){delai=200;ok=0;}
                    break;
               case SDLK_KP3:
                    if(ok){delai=100;ok=0;}
                    break;
               case SDLK_KP4:
                    if(ok){delai=50;ok=0;}
                    break;
               case SDLK_KP5:
                    if(ok){delai=20;ok=0;}
                    break;
               case SDLK_KP6:
                    if(ok){delai=10;ok=0;}
                    break;
               case SDLK_KP7:
                    if(ok){delai=5;ok=0;}
                    break;
               case SDLK_KP8:
                    if(ok){delai=2;ok=0;}
                    break;
               case SDLK_KP9:
                    if(ok){delai=1;ok=0;}
                    break;
              }
              break;
         case SDL_KEYUP:
              switch(event.key.keysym.sym)
              {
               case SDLK_ESCAPE:
                    if(ok==0){continuer=1;ok=1;}
                    break;
               case SDLK_KP0:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP1:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP2:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP3:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP4:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP5:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP6:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP7:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP8:
                    if(ok==0){ok=1;}
                    break;
               case SDLK_KP9:
                    if(ok==0){ok=1;}
                    break;
              }
              break;
            }
            
  tpsA=SDL_GetTicks();
       if(tpsA-tpsB>=delai)
       {
            if(taille<nombreDepart)
            {
             creerEntite(etre,taille,1);
             determineTribu(&etre[taille]);
             taille++;
            }
        seDeplacer(etre,taille);
        taille=seReproduire(etre,taille);
        jours++;
        miseAJour(etre,taille);
        tpsB=tpsA;
       }
            
  afficherEntite(ecran,etre,taille);
  afficheCompteur(ecran,etre,taille,&jours);
        SDL_Flip(ecran);
    }while(continuer);
    
    
    
    
    TTF_Quit();
    
    SDL_Quit();
    return 0;
}
