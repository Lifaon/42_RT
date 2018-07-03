/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 04:26:11 by mlantonn          #+#    #+#             */
/*   Updated: 2018/07/03 02:15:02 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	add_alpha(t_obj *obj)
{
	uint8_t		*tmp;
	GtkWidget	*img;
	t_point		size;
	t_color		color;
	int			i;

	if (!(tmp = (uint8_t*)malloc(3 * obj->tex->size.x * obj->tex->size.y)))
		return (-1);
	tmp = memcpy(tmp, obj->tex->pxl, 3 * obj->tex->size.x * obj->tex->size.y);
	img = obj->tex->widget;
	size = obj->tex->size;
	pixelbuf_free(&obj->tex);
	obj->tex = pixelbuf_new(size, img);
	i = -1;
	while (++i < obj->tex->size.x * obj->tex->size.y)
	{
		color.argb.a = 255;
		color.argb.r = tmp[i * 3];
		color.argb.g = tmp[(i * 3) + 1];
		color.argb.b = tmp[(i * 3) + 2];
		obj->tex->pxl[i] = color.c;
	}
	free(tmp);
	return (0);
}

static char	*get_file_name(char *str, int *index)
{
	char	*ret;
	int		size;
	int		i;

	size = -1;
	while (str[++size] && str[size] != '\"');
	if (!size || str[size] != '\"')
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = str[i];
	ret[i] = '\0';
	*index += i;
	return (ret);
}

void		parse_texture(t_obj *obj, char *str, int *index)
{
	char	*file_name;
	int		i;

	i = -1;
	while (str[++i] && str[i] != ':');
	if (str[i] != ':')
		return ;
	while (str[++i] && str[i] != '\"');
	if (str[i] != '\"')
		return ;
	*index += ++i;
	if (!(file_name = get_file_name(str + i, index)))
		return ;
	if (!(obj->tex = pixelbuf_new_from_file(file_name)))
		return ;
	if (gdk_pixbuf_get_has_alpha(obj->tex->buf) == FALSE && add_alpha(obj))
		pixelbuf_free(&obj->tex);
	free(file_name);
}
