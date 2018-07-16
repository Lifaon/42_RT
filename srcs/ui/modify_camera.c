#include "ui.h"

void	change_left_cam(GtkWidget *widget, gpointer param)
{
	GtkWidget		*label;
	char			*str;

	label = (GtkWidget*)param;
	if (g_data->i <= 0)
		return ;	
	g_data->i--;
 	g_data->cam = g_data->cams[g_data->i];
 	str = ft_itoa(g_data->i + 1);
 	gtk_label_set_text(GTK_LABEL(label), str);
 	ft_strdel(&str);
}

void	change_right_cam(GtkWidget *widget, gpointer param)
{
	GtkWidget		*label;
	char			*str;

	label = (GtkWidget*)param;
	if (g_data->i >= CAM_NB - 1)
		return ;	
	g_data->i++;
 	g_data->cam = g_data->cams[g_data->i];
 	str = ft_itoa(g_data->i + 1);
 	gtk_label_set_text(GTK_LABEL(label), str);
 	ft_strdel(&str);
}