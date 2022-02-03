#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "verification.h"
#include "equipement.h"
#include "support.h"


void
on_retour_mod_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*modifier;

modifier=lookup_widget(button,"modifier");

gtk_widget_destroy(modifier);
Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_button3_mod_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *aa,*bb,*cc,*vv,*in,*window3;
equipement E;
char id[30];
cc=lookup_widget(button,"combobox2");
vv=lookup_widget(button,"combobox3");
aa=lookup_widget(button,"entry12_id");
bb=lookup_widget(button,"entry13_prix");
in = lookup_widget(button,"input");
strcpy(E.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cc)));
strcpy(E.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(vv)));
strcpy(E.id,gtk_entry_get_text(GTK_ENTRY(aa)));
strcpy(E.prix,gtk_entry_get_text(GTK_ENTRY(bb)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(in)));
modifierr(E,id);
 window3 = create_window3 ();
  gtk_widget_show (window3);
}


void
on_button4_recherche_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input1, *output; 
char id[30];

 int x; 
equipement E;
 input1=lookup_widget(button,"entry12_id"); 
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
 output=lookup_widget(button,"label13");
 x= rechercher(id);
 if(x==1)
 { gtk_label_set_text(GTK_LABEL(output),"equipement existe"); 
}
 else
 { 
gtk_label_set_text(GTK_LABEL(output),"equipement inexistant"); 
}
}


void
on_afficherM_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *Maintenance;
GtkWidget *treeview1;

modifier=lookup_widget(button,"modifier");

gtk_widget_destroy(modifier);
Maintenance=lookup_widget(button,"Maintenance ");
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);

treeview1=lookup_widget(Maintenance,"treeview1");


afficher(treeview1);
}


void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *Maintenance;



Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
ajouter=lookup_widget(button,"ajouter");
  ajouter = create_ajouter ();
  gtk_widget_show (ajouter);




ajouter=lookup_widget(Maintenance,"ajouter");
}



void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *Maintenance;



Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
modifier=lookup_widget(button,"modifier");
  modifier = create_modifier ();
  gtk_widget_show (modifier);




modifier=lookup_widget(Maintenance,"modifier");

}


void
on_button4_eliminer_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *Maintenance;



Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
supprimer=lookup_widget(button,"supprimer");
  supprimer = create_supprimer ();
  gtk_widget_show (supprimer);




supprimer=lookup_widget(Maintenance,"supprimer");
}


void
on_affichercapteur_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
int  jr,mo,an, nb1=0,nb2=0,nb3=0,nb4=0,nb5=0,nb6=0,nb7=0,nb8=0,nb9=0,id ;
float Te;
char nb[10];
char n1[10],n2[10],n3[10],n4[10],n5[10],n6[10],n7[10],n8[10],n9[10];
GtkWidget *treeview2;
GtkWidget *tnb1;
GtkWidget *Maintenance;
GtkWidget *windowcapteur;
FILE *T,*FL ;
T = fopen ("temperature.txt", "r");
FL= fopen ("temp.txt", "a+");
if((FL!=NULL)&&(T!=NULL))
{
while (fscanf(T,"%d %d %d %d %f \n",&id,&jr,&mo,&an,&Te)!=EOF )
{
if (15<Te && Te<40)
{


if (id==1)
 nb1++ ;
if (id==2)
nb2++ ;
if (id==3)
nb3++ ;
if (id==4)
nb4++ ;
if (id==5)
nb5++ ;
if (id==6)
nb6++ ;
if (id==7)
nb7++ ;
if (id==8)
nb8++ ;
if (id==9)
nb9++;
}}
fprintf(FL,"%d %d %d %d %d %d %d %d %d \n",nb1,nb2,nb3,nb4,nb5,nb6,nb7,nb8,nb9);
//while(fscanf(FL,"%s %s %s %s %s %s %s %s %s\n",n1,n2,n3,n4,n5,n6,n7,n8,n9)!=EOF)
//{


  
  fclose(T);

fclose(FL);
}
Maintenance=lookup_widget(button,"Maintenance");

gtk_widget_destroy(Maintenance);
Maintenance=lookup_widget(button,"Maintenance");
 windowcapteur = create_windowcapteur ();
  gtk_widget_show (windowcapteur);

treeview2=lookup_widget(windowcapteur,"treeview2");
afficherrr(treeview2);


// itoa(nb,nb1,10);
tnb1 = lookup_widget(button, "label24");
gtk_label_set_text(GTK_LABEL(tnb1),n1);
}


void
on_button3_ajouter_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

FILE *f=NULL;
equipement E;
char id[10];

GtkWidget *windowajoute;
GtkWidget *input1, *input2, *input3, *input4 ,*output1,*output2,*output3,*output4;





windowajoute=lookup_widget(button,"windowajoute");


input1=lookup_widget(button,"comboboxentry1");
input2=lookup_widget(button,"combobox1");
input3=lookup_widget(button,"entry10_id");
input4=lookup_widget(button,"entry9_prix");

strcpy(E.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(E.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(E.id,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E.prix,gtk_entry_get_text(GTK_ENTRY(input4)));




output1=lookup_widget(button,"comboboxentry1");
output2=lookup_widget(button,"combobox1");
output3=lookup_widget(button,"label10_id");
output4=lookup_widget(button,"entry9_prix");
ajouter(E);


 windowajoute = create_windowajoute ();
  gtk_widget_show (windowajoute);

}


void
on_button4_afficher_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *Maintenance;
GtkWidget *treeview1;

ajouter=lookup_widget(button,"ajouter");

gtk_widget_destroy(ajouter);
Maintenance=lookup_widget(button,"Maintenance ");
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);

treeview1=lookup_widget(Maintenance,"treeview1");


afficher(treeview1);

}


void
on_retour_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*ajouter;

ajouter=lookup_widget(button,"ajouter");

gtk_widget_destroy(ajouter);
Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_button5_supp_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *window1;
GtkWidget *input;
char id[30];



supprimer=lookup_widget(button,"supprimer");
window1=lookup_widget(button,"window1");

input=lookup_widget(button,"entry15_id");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));



supprimerr(id);
window1 = create_window1 ();
  gtk_widget_show (window1);
}


void
on_retour_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*supprimer;

supprimer=lookup_widget(button,"supprimer");

gtk_widget_destroy(supprimer);
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);
}


void
on_afficherS_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *Maintenance;
GtkWidget *treeview1;

supprimer=lookup_widget(button,"supprimer");

gtk_widget_destroy(supprimer);
Maintenance=lookup_widget(button,"Maintenance ");
Maintenance= create_Maintenance ();
  gtk_widget_show (Maintenance);

treeview1=lookup_widget(Maintenance,"treeview1");


afficher(treeview1);

}


void
on_retour_MT_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window1,*supprimer;

window1=lookup_widget(button,"window1");

gtk_widget_destroy(window1);
}


void
on_retour_MA_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajoute,*ajouter;

windowajoute=lookup_widget(button,"windowajoute");

gtk_widget_destroy(windowajoute);
}


void
on_retour_MM_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window3,*modifier;

window3=lookup_widget(button,"window3");

gtk_widget_destroy(window3);
}


void
on_retour_capteur_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance;
GtkWidget *windowcapteur;
windowcapteur=lookup_widget(button,"windowcapteur");

gtk_widget_destroy(windowcapteur);
}


void
on_button3_c_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
admin c;
GtkWidget *nom,*prenom,*password,*numero,*pays,*cin;
GtkWidget *window4 ,*window2;

window4 = create_window4();


nom=lookup_widget(button,"entry9_c");
prenom=lookup_widget(button,"entry10_c");
password=lookup_widget(button,"entry8_c");
numero=lookup_widget(button,"entry12_c");
pays=lookup_widget(button,"entry11_c");
cin=lookup_widget(button,"entry7_c");

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(c.numero,gtk_entry_get_text(GTK_ENTRY(numero)));
strcpy(c.pays,gtk_entry_get_text(GTK_ENTRY(pays)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
ajouter_c(c);


window2 = create_window2();
window4=lookup_widget(button,"window4");

gtk_widget_show (window2);
gtk_widget_hide (window4);
}


void
on_button2_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2,*input1,*input2, *output;
  GtkWidget *window5;
FILE *f;
f=fopen("users.txt","r");
char nom[20];
char password[20];
admin c;
window2 = create_window2();
input1=lookup_widget(button,"entry13_c");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1))); 
input2=lookup_widget(button,"entry14_c");
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2))); 
output=lookup_widget(button,"label57_c");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s \n",c.nom,c.prenom,c.password)!=EOF)
{
if ((strcmp(nom,c.nom)==0)&&(strcmp(password,c.password)==0))
{

window2=lookup_widget(button,"window2");
gtk_widget_destroy(window2);
window5=lookup_widget(button,"window5");
window5 = create_window5 ();
  gtk_widget_show (window5);
window5=lookup_widget(window2,"window5");

}
else
gtk_label_set_text(GTK_LABEL(output),"Not Found!");
}
}
}



void
on_button2_creation_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
  GtkWidget *window4;


window2=lookup_widget(button,"window2");

window4=lookup_widget(button,"window4");
window4 = create_window4 ();
  gtk_widget_show (window4);
window4=lookup_widget(window2,"window4");
}





void
on_g_capteurs_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_g_calendrier_clicked                (GtkWidget      *button,
                                        gpointer         user_data)
{

}


void
on_g_ouvrier_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_g_equipement_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Maintenance,*window5;

window5=lookup_widget(button,"window5");

gtk_widget_destroy(window5);
Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
}

