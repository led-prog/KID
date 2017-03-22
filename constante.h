#ifndef CONSTANTE
#define CONSTANTE

#define LARGEUR 600
#define LARGEUR_CADRE 150
#define LARGEUR_ECRAN LARGEUR+LARGEUR_CADRE
#define HAUTEUR 600
#define TAILLE_BLOC 5
#define MAXIMUM 32000

typedef struct Liste Liste;
struct Liste
{
 int tribu;
 int sexe;
 int age;
 int vivre;
 int mourir;
};
typedef struct Genome Genome;
struct Genome
{
 int chromosome[3];
};

typedef struct Entite Entite;
struct Entite
{
 int vie;
 int jour;
 int annee;
 /*int age;*/
 
 int vivre;
 int mourir;
 
 int gestation;
 int grossesse;
 
 int direction;
 SDL_Rect pos;
 
 Liste donnees;
 Entite *mere;/*
 Genome *genome;
 Entite *mere;
 Entite *pere;*/
 /*
 Entite *cible;
 int cibleAcquise;
 Entite *meVise;
 int partenaireX;
 int partenaireY;*/
 /*Entite *enfants[15];*/
};

enum {ANDROGYNE,MASCULIN,FEMININ};
enum {AUCUN,ENFANT,ADULTE,VIEUX};
enum {NUL,APTE,ENCEINTE};
enum {AUCUNE,DROITE,BAS,GAUCHE,HAUT};
enum {NOIR,ROUGE,VERT,BLEU};
enum {NEANT,NAISSANCE,DECES};

#endif

void initialiserEntite(Entite etre[],int taille);
void initialiseEntite(Entite *etre);
void creerEntite(Entite etre[],int taille,int nombreEntite);
void creeEntite(Entite *etre);
void determinerTribu(Entite *etre,int taille);
void determineTribu(Entite *etre);
void tribuRouge(Entite *etre,Entite *mere);
void tribuVerte(Entite *etre,Entite *mere);
void tribuBleue(Entite *etre,Entite *mere);/*
void determineTribu(Entite *etre,Entite *mere,Entite *pere,int *liste);*/
void afficherEntite(SDL_Surface *ecran,Entite etre[],int taille);
void afficheEntite(SDL_Surface *ecran,Entite etre[]);
void afficheCompteur(SDL_Surface *ecran,Entite etre[],int taille,int *jour);
void compteurG(SDL_Surface *ecran,Entite etre[],int taille,int *jour);
void compteurRouge(SDL_Surface *ecran,Entite etre[],int taille);
void compteurVert(SDL_Surface *ecran,Entite etre[],int taille);
void compteurBleu(SDL_Surface *ecran,Entite etre[],int taille);
void compteurDonnees(Entite *etre,int taille);
void miseAJour(Entite etre[],int taille);
void metAJour(Entite *etre);
void degrade(SDL_Surface *ecran);

