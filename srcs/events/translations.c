#include "events.h"
#define TRANSLATION 150

void		translateW(t_data *data)
{
	data->cams[data->i].pos.y -= TRANSLATION;
	choose_cam(data, data->i);
}

void		translateA(t_data *data)
{
	data->cams[data->i].pos.x += TRANSLATION;
	choose_cam(data, data->i);
}

void		translateS(t_data *data)
{
	data->cams[data->i].pos.y += TRANSLATION;
	choose_cam(data, data->i);
}

void			translateD(t_data *data)
{
	data->cams[data->i].pos.x -= TRANSLATION;
	choose_cam(data, data->i);
}

void			translateQ(t_data *data)
{
	data->cams[data->i].pos.z -= TRANSLATION;
	choose_cam(data, data->i);
}

void			translateE(t_data *data)
{
	data->cams[data->i].pos.z += TRANSLATION;
	choose_cam(data, data->i);
}
