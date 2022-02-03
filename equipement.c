#include <stdio.h>
#include <string.h>
#include "equipement.h"
#include <gtk/gtk.h>
void ajouter( equipement E)
{
  FILE *f;
  f=fopen("equipement.txt","a");
  if(f!=NULL)
  {
  fprintf(f,"%s %s %s %s\n",E.type,E.marque,E.id,E.prix);
  fclose(f);
}
}

void afficher(GtkWidget *liste)
{

enum
{
	TYPE,         
        MARQUE,
     	ID,  
        PRIX,
	
	COLUMNS
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char type [30];
char marque[30];
char id [30];
char prix[30] ;

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",MARQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	

       
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("equipement.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("equipement.txt","a+");
		while(fscanf(f," %s %s %s %s \n",type,marque,id,prix)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,TYPE,type,MARQUE,marque,ID,id,PRIX,prix,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}


void supprimerr(char id[] )
{
equipement E;


FILE*f1;
FILE*f2;

f1=fopen("equipement.txt","r");
f2=fopen("equipement1.txt","w");
if (f1!=NULL)
{


while(fscanf(f1,"%s %s %s %s \n",E.type,E.marque,E.id,E.prix)!=EOF)
{

if(strcmp(E.id,id)!=0)
{
fprintf(f2,"%s %s %s %s \n",E.type,E.marque,E.id,E.prix);


}
}
fclose(f1);
  fclose(f2);
  remove("equipement.txt");
  rename("equipement1.txt","equipement.txt");

}

  

}
 

void modifierr(equipement E , char id[])
{
equipement E1;

FILE*f;
FILE*f1;
f=fopen("equipement.txt","r");
f1=fopen("equipement1.txt","w");
while(fscanf(f,"%s %s %s %s\n",E1.type,E1.marque,E1.id,E1.prix)!=EOF)
{
if(strcmp(E1.id,id)==0)
{
fprintf(f1,"%s %s %s %s\n",E.type,E.marque,E.id,E.prix);

}
else
{
fprintf(f1,"%s %s %s %s\n",E1.type,E1.marque,E1.id,E1.prix);
}
}
fclose(f);
fclose(f1);
remove("equipement.txt");
rename("equipement1.txt","equipement.txt");

}



int rechercher(char id[])
{
 int test; 
FILE*f; 
equipement E ;
 f=fopen("equipement.txt","r"); 
test=0; 
if (f!=NULL)
 {
 while (fscanf(f,"%s %s %s %s\n",E.type,E.marque,E.id,E.prix)!=EOF) 
{
 if (strcmp(id,E.id)==0)
 {
 test=1; 
break;
return 1;
 } 
}
 fclose(f);
 }
 if (test==0)
 {
return 0;
} 
else
 {
return 1;
} 


}
 

enum
{
	N1,         
        N2,
     	N3,  
        N4,
	N5,
	N6,
	N7,
	N8,
	N9,	
	COLUMNS
};
void afficherrr(GtkWidget *liste)
{



GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char n1[30];
char n2[30];
char n3[30];
char n4[30];
char n5[30];
char n6[30];
char n7[30];
char n8[30];
char n9[30];

store =NULL;

FILE *FL;
//FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();

	
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n1",renderer,"text",N1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n2",renderer,"text",N2,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n3",renderer,"text",N3,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n4",renderer,"text",N4,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n5",renderer,"text",N5,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n6",renderer,"text",N6,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n7",renderer,"text",N7,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n8",renderer,"text",N8,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("n9",renderer,"text",N9,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	

       
	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	FL=fopen("temp.txt","r");

	if(FL==NULL)
	{
		return;
	}
	else
	
	{ 
	FL=fopen("temp.txt","a+");
		while(fscanf(FL,"%s %s %s %s %s %s %s %s %s\n",n1,n2,n3,n4,n5,n6,n7,n8,n9)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter, N1,n1, N2,n2,N3,n3,N4,n4,N5,n5,N6,n6,N7,n7,N8,n8,N9,n9,-1);}

		fclose(FL);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}}



