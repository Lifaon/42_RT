#include "ui.h"

void			set_entry_and_scale_from_vector(GtkSizeGroup *group, t_vec vec)
{
	GSList		*lst;
	GtkWidget 	*son;
	int			i;
	char 		*str[3];

	lst = gtk_size_group_get_widgets(group);
	str[0] = ft_dbtoa(vec.z);
	str[1] = ft_dbtoa(vec.y);
	str[2] = ft_dbtoa(vec.x);
	i = 0;
	while (lst)
	{
		son = lst->data;
		if (GTK_IS_ENTRY(son))
			gtk_entry_set_text(GTK_ENTRY(son), str[i]);
		if (GTK_IS_SCALE(son) && ++i == 1)
			gtk_range_set_value(GTK_RANGE(son), vec.z);
		else if (GTK_IS_SCALE(son) && i == 2)
			gtk_range_set_value(GTK_RANGE(son), vec.y);
		else if (GTK_IS_SCALE(son) && i == 3)
			gtk_range_set_value(GTK_RANGE(son), vec.x);
		lst = lst->next;
	}
	while (--i >= 0)
		ft_strdel(&str[i]);
	//g_list_free(lst);
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
 	set_entry_and_scale_from_vector(g_data->ui->gp_campos, g_data->cam.pos);
	gtk_range_set_value(GTK_RANGE(g_data->ui->sc_fov), g_data->cam.fov);
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
 	set_entry_and_scale_from_vector(g_data->ui->gp_campos, g_data->cam.pos);
	gtk_range_set_value(GTK_RANGE(g_data->ui->sc_fov), g_data->cam.fov);
	g_data->ui->is_active = 1;
}