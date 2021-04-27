#include <gtk/gtk.h>
#include "constantes.h"


void ajouterGamme(GtkComboBox* container); 

int main(int argc, char *argv[])
{
  // Initialisation de GTK et ouverture de l'interface
  gtk_init(NULL, NULL);
  GtkBuilder* builder = gtk_builder_new_from_file("interface.glade");
  GtkWindow* window = GTK_WINDOW(gtk_builder_get_object(builder, "interface"));
  GtkComboBox* gamme = GTK_COMBO_BOX(gtk_builder_get_object(builder, "gamme")); 
  
  ajouterGamme(gamme); 
  gtk_window_set_title(window, "The Piano Partner");
  gtk_window_set_icon_from_file(window, "icon.png", NULL);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_builder_connect_signals(builder, NULL);
  gtk_widget_show_all((GtkWidget*)window);
  gtk_main();

  return 0;
}

void ajouterGamme(GtkComboBox* container)
{
  enum
  { 
    GAMME_ID,
    GAMME_NAME,
    N_COLUMNS
  };
  GtkTreeIter iter; 
  GtkTreeStore* store;
  GtkWidget* tree; 
  GtkCellRenderer* renderer; 
  GtkTreeViewColumn* column; 
  
  store = gtk_tree_store_new(N_COLUMNS, G_TYPE_INT, G_TYPE_STRING); 
  gtk_combo_box_set_model(container, GTK_TREE_MODEL(store)); 

  renderer = gtk_cell_renderer_text_new();
  gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (container), renderer, FALSE);
  gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (container), renderer,"text", 0, NULL);

  renderer = gtk_cell_renderer_text_new();
  gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (container), renderer, FALSE);
  gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (container), renderer, "text", 1, NULL);

  
  
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 0, 1, "Do Majeur", -1);
  gtk_tree_store_append(store, &iter, NULL);  
  gtk_tree_store_set(store, &iter, 0, 1, 1, "Ré Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 2, 1, "Mi Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 3, 1, "Fa Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 4, 1, "Sol Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 5, 1, "La Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 6, 1, "Si Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 7, 1, "Do Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 8, 1, "Ré Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 9, 1, "Mi Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 10, 1, "Fa Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 11, 1, "Sol Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 12, 1, "La Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 13, 1, "Si Dièse Majeur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 14, 1, "Do Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 15, 1, "Ré Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 16, 1, "Mi Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 17, 1, "Fa Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 18, 1, "Sol Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 19, 1, "La Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 20, 1, "Si Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 21, 1, "Do Dièse Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 22, 1, "Ré Dièse Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 23, 1, "Mi Dièse Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 24, 1, "Fa Dièse Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 25, 1, "Sol Dièse Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 26, 1, "La Dièse Mineur", -1); 
  gtk_tree_store_append(store, &iter, NULL); 
  gtk_tree_store_set(store, &iter, 0, 27, 1, "Si Dièse Mineur", -1); 

}

void ajouterAccords(GtkGrid* container)
{
  // 
}