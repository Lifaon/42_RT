#include "rtv1.h"
#include "ui.h"

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

void			change_vec_from_scale(GtkSizeGroup *group, t_vec *vec)
{
	double		value;
	GtkWidget	*son;
	char		*str;
	GSList		*lst;

	lst = gtk_size_group_get_widgets(GTK_SIZE_GROUP(group));
	while (lst)
	{
		son = (GtkWidget*)lst->data;
		if (GTK_IS_SCALE(son))
		{
			value = gtk_range_get_value(GTK_RANGE(son));
			fill_vec(vec, value);
		}
		if (GTK_IS_ENTRY(son))
		{
			str = ft_dbtoa(value);
			gtk_entry_set_text(GTK_ENTRY(son), str);
			ft_strdel(&str);
		}
		lst = lst->next;
	}
}
