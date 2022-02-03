/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *modifier;
  GtkWidget *Maintenance;
  GtkWidget *ajouter;
  GtkWidget *supprimer;
  GtkWidget *window1;
  GtkWidget *windowajoute;
  GtkWidget *window3;
  GtkWidget *windowcapteur;
  GtkWidget *window4;
  GtkWidget *window2;
  GtkWidget *window5;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /*modifier = create_modifier ();
  gtk_widget_show (modifier);
  Maintenance = create_Maintenance ();
  gtk_widget_show (Maintenance);
  ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
  supprimer = create_supprimer ();
  gtk_widget_show (supprimer);
  window1 = create_window1 ();
  gtk_widget_show (window1);
  windowajoute = create_windowajoute ();
  gtk_widget_show (windowajoute);
  window3 = create_window3 ();
  gtk_widget_show (window3);
  windowcapteur = create_windowcapteur ();
  gtk_widget_show (windowcapteur);*/
  window4 = create_window4 ();
  gtk_widget_show (window4);
  window2 = create_window2 ();
  gtk_widget_show (window2);
  /*window5 = create_window5 ();
  gtk_widget_show (window5);*/

  gtk_main ();
  return 0;
}
