#include "ui.h"

static int			get_state_of_scale(const char *str, GtkWidget *widget)		
{
	int		 	dst;
	gboolean	state;

	dst = -1;
	if ((ft_strcmp(str, "Rainbow") == 0 ) || (ft_strcmp(str, "Checkboard") == 0))
	{
		if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)) == TRUE)
			dst = 1;
	}
	return (dst);
}

static void			check_textures(GtkSizeGroup *group, const char *label, 
	gboolean label_state)
{
	GtkWidget		*button;
	GtkWidget		*scale;
	GSList			*lst;
	const char 		*str;
	gboolean		state;

	state = FALSE;
	scale = NULL;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		if (GTK_IS_CHECK_BUTTON((GtkWidget*)lst->data))
		{
			button = (GtkWidget*)lst->data;
			str = gtk_button_get_label(GTK_BUTTON(button));
			if (label && ft_strcmp(str, label) == 0)
				gtk_widget_set_sensitive(button, label_state);
			if (get_state_of_scale(str, button) == 1)
				state = TRUE;
		}
		else if (GTK_IS_SCALE((GtkWidget*)lst->data))
			scale = (GtkWidget*)lst->data;
		lst = lst->next;
	}
	if (scale)
		gtk_widget_set_sensitive(scale, state);
}

void		check_checkboard(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;
	GtkWidget 		*son;
	GSList			*lst;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (state == TRUE)
		check_textures(group, "Rainbow", FALSE);
	else
		check_textures(group, "Rainbow", TRUE);
	if (state == TRUE)
		g_data->objs[g_ui->page_obj].color_type = COLOR_CHECKERBOARD;
	else
		g_data->objs[g_ui->page_obj].color_type = COLOR_SIMPLE;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_BUTTON(son) == TRUE && GTK_IS_CHECK_BUTTON(son) == FALSE)
			gtk_widget_set_sensitive(son, state);
		lst = lst->next;
	}
}

void		check_rainbow(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	if (state == TRUE)
	{
		check_textures(group, "Checkboard", FALSE);	
		g_data->objs[g_ui->page_obj].color_type = COLOR_RAINBOW;
	}
	else
	{
		check_textures(group, "Checkboard", TRUE);
		g_data->objs[g_ui->page_obj].color_type = COLOR_SIMPLE;
	}
}

void		check_perlin(GtkWidget *widget, gpointer param)
{
	GtkSizeGroup	*group;
	gboolean		state;	
	GSList			*lst;
	GtkWidget 		*son;
	
	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	group = (GtkSizeGroup*)param;
	state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	set_group_widget_active(group, state);
	if (state == FALSE)
		g_data->objs[g_ui->page_obj].perl_type = PERLIN_NONE;
	if (state == FALSE)
		return ;
	g_data->objs[g_ui->page_obj].perl_type = PERLIN_CLASSIC;
	lst = gtk_size_group_get_widgets(group);
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_CHECK_BUTTON(son))
		{
			state = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(son));
			if (state == TRUE)
				g_data->objs[g_ui->page_obj].perl_type = PERLIN_COSINE;
		}
		lst = lst->next;
	}
}

void		change_color_scale(GtkWidget *widget, gpointer param)
{
	int		value;

	if (g_ui->is_active == 0 || (!widget && !param))
		return ;
	value = (int)gtk_range_get_value(GTK_RANGE(widget));
	g_data->objs[g_ui->page_obj].color_scale = value;
}