#include "ui.h"

void			set_entry_and_scale_from_vector(GtkWidget *container, t_vec vec)
{
	GList		*lst;
	GtkWidget 	*son;
	double		value;
	int			i;
	char 		*str[3];

	lst = gtk_container_get_children(GTK_CONTAINER(container));
	value = vec.z;
	str[0] = ft_dbtoa(vec.z);
	str[1] = ft_dbtoa(vec.y);
	str[2] = ft_dbtoa(vec.x);
	i = 0;
	while (lst)
	{
		son = lst->data;
		if (GTK_IS_ENTRY(son))
			gtk_entry_set_text(GTK_ENTRY(son), str[i]);
		if (GTK_IS_SCALE(son))
		{
			gtk_range_set_value(GTK_RANGE(son), value);
			i++;
		}
		if (i == 1)
			value = vec.y;
		else if (i == 2)
			value = vec.x;
		lst = lst->next;
	}
	while (--i >= 0)
		ft_strdel(&str[i]);
	g_list_free(lst);

}

static void		set_cam_value(GtkWidget *container)
{
	GList		*lst;
	GList		*lst2;
	GtkWidget 	*son;

	lst = gtk_container_get_children(GTK_CONTAINER(container));
	while (lst)
	{
		son = lst->data;
		if (GTK_IS_FRAME(son))
			set_entry_and_scale_from_vector(son, g_data->cam.pos);
		if (GTK_IS_SCALE(son))
			gtk_range_set_value(GTK_RANGE(son), g_data->cam.fov);
		lst = lst->next;
	}
	g_list_free(lst);
}

void			change_left_cam(GtkWidget *widget, gpointer param)
{
	GtkWidget		*label;
	char			*str;

	if (g_data->ui->is_active == 0)
		return ;
	label = (GtkWidget*)param;
	if (g_data->i <= 0)
		return ;	
	g_data->i--;
 	g_data->cam = g_data->cams[g_data->i];
 	str = ft_itoa(g_data->i + 1);
 	gtk_label_set_text(GTK_LABEL(label), str);
 	ft_strdel(&str);
 	g_data->ui->is_active = 0;
 	set_cam_value((GtkWidget*)param); 	
 	g_data->ui->is_active = 1;
}

void			change_right_cam(GtkWidget *widget, gpointer param)
{
	GtkWidget		*label;
	char			*str;
	
	if (g_data->ui->is_active == 0)
		return ;
	label = (GtkWidget*)param;
	if (g_data->i >= CAM_NB - 1)
		return ;	
	g_data->i++;
 	g_data->cam = g_data->cams[g_data->i];
 	str = ft_itoa(g_data->i + 1);
 	gtk_label_set_text(GTK_LABEL(label), str);
 	ft_strdel(&str);
	g_data->ui->is_active = 0;
	set_cam_value((GtkWidget*)param); 	
	g_data->ui->is_active = 1;
}