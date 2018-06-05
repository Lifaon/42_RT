#include "events.h"

void		translateW(t_data *data)
{
	data->cams[data->i].pos.y += 75;
	choose_cam(data, data->i);
}

void		translateA(t_data *data)
{
	data->cams[data->i].pos.x -= 75;
	choose_cam(data, data->i);
}

void		translateS(t_data *data)
{
	data->cams[data->i].pos.y -= 75;
	choose_cam(data, data->i);
}

void			translateD(t_data *data)
{
	data->cams[data->i].pos.x += 75;
	choose_cam(data, data->i);
}

void			translateQ(t_data *data)
{
	data->cams[data->i].pos.z -= 75;
	choose_cam(data, data->i);
}

void			translateE(t_data *data)
{
	data->cams[data->i].pos.z += 75;
	choose_cam(data, data->i);
}