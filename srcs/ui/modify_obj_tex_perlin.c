#include "ui.h"

void		check_perlin_cosine(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].perl_type = PERLIN_COSINE;
	else
		g_data->objs[g_ui->page_obj].perl_type = PERLIN_CLASSIC;
}

void		change_perlin_scale(GtkWidget *widget, gpointer param)
{
	int		value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].perl_scale = value;
}

void		change_perlin_opacity(GtkWidget *widget, gpointer param)
{
	double	value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].perl_opacity = value;
}