#include "rtv1.h"

static void		fill_vec(t_vec *vec, double nb)
{
	static int i = 0;

	if (!vec)
		return ;
	if (i > 2)
		i = 0;
	if (i == 0)
		vec->x = nb;
	else if (i == 1)
		vec->y = nb;
	else if (i == 2)
		vec->z = nb;
	i++;
}

static t_vec	get_vector_from_group_widget(GSList *lst)
{
	double		value;
	GtkWidget	*son;
	t_vec		vec;
	char		*str;

	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_SCALE(son))
		{
			value = gtk_range_get_value(GTK_RANGE(son));
			fill_vec(&vec, value);
		}
		if (GTK_IS_ENTRY(son))
		{
			str = ft_dbtoa(value);
			gtk_entry_set_text(GTK_ENTRY(son), str);
			ft_strdel(&str);
		}
		lst = lst->next;
	}
	return (vec);
}

void			change_vec_from_scale(GtkWidget *widget, gpointer param)
{
	t_widget_vec	*wid_vec;
	char			*str;
	GSList			*lst;

	if (!widget || !param)
		return ;
	wid_vec = (t_widget_vec*)param;
	if (GTK_IS_SIZE_GROUP(wid_vec->group))
	{
		lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(wid_vec->group));
		*wid_vec->vec = get_vector_from_group_widget(lst);
	}
}
