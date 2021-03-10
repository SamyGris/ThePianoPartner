#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
  gtk_init(NULL, NULL);
  GtkBuilder* builder = gtk_builder_new_from_file("interface.glade");
  GtkWindow* window = GTK_WINDOW(gtk_builder_get_object(builder, "interface"));
  gtk_window_set_title(window, "The Piano Partner");
  gtk_window_set_icon_from_file(window, "icon.png", NULL);
  
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_builder_connect_signals(builder, NULL);
  gtk_widget_show((GtkWidget*)window);
  gtk_main();

  return 0;
}
