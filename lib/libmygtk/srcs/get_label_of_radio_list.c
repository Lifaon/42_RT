/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_of_radio_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchevrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:11:55 by fchevrey          #+#    #+#             */
/*   Updated: 2018/05/12 19:40:59 by fchevrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mygtk.h"

const gchar		*get_label_of_radio_list(GList *radio)
{
	GList		*lst;
	GtkWidget	*button;

	lst = radio;
	while (lst)
	{
		button = (GtkWidget*)lst->data;
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button)) == TRUE)
				return (gtk_button_get_label(GTK_BUTTON(button)));
		lst = lst->next;
	}
	return (NULL);
}
