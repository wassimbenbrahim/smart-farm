#include <gtk/gtk.h>
typedef struct equipement{
char type[30];
char marque[20];
char id[30];
char prix[30];
}equipement;
void supprimerr(char id[]);
void ajouter(equipement E);
void modifierr(equipement E, char id[]);
void afficher(GtkWidget *liste);
int rechercher(char id[]);
void afficherrr(GtkWidget *liste);
