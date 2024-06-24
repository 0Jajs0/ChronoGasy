#include "lib.h"

void	ft_number(int n, int l, t_x *proc, int b)
{
	int	lon;

	lon = ((proc->lon / 2) - 128) + l;
	if (n == 0)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->zero1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->zero0, lon, proc->n_lar);
	}
	else if (n == 1)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->one1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->one0, lon, proc->n_lar);
	}
	else if (n == 2)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->two1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->two0, lon, proc->n_lar);
	}
	else if (n == 3)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->three1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->three0, lon, proc->n_lar);
	}
	else if (n == 4)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->four1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->four0, lon, proc->n_lar);
	}
	else if (n == 5)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->five1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->five0, lon, proc->n_lar);
	}
	else if (n == 6)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->six1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->six0, lon, proc->n_lar);
	}
	else if (n == 7)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->seven1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->seven0, lon, proc->n_lar);
	}
	else if (n == 8)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->eight1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->eight0, lon, proc->n_lar);
	}
	else if (n == 9)
	{
		if (!b)
			mlx_put_image_to_window(proc->mlx, proc->win, proc->nine1, lon, proc->n_lar);
		else
			mlx_put_image_to_window(proc->mlx, proc->win, proc->nine0, lon, proc->n_lar);
	}
}

void	ft_date(t_x *proc)
{
	static int	a;
	char		*str;
	int			date;
	int			l;
	int			d;
	int			b;

	a++;
	if (a % 7 == 0)
		b = 1;
	else
		b = 0;
	str = malloc(6);
	str[5] = 0;
	read(proc->fd, str, 5);
	date = atoi(str);
	if (!date)
		return ;
	free(str);
	l = 64 * 3;
	d = 4;
	while (d > 0)
	{
		ft_number(date % 10, l, proc, b);
		date /= 10;
		l -= 64;
		d--;
	}
	
}
void	ft_animate(t_x *proc)
{
	static int	z;

	z++;
	if (z == 1)
	{
		mlx_put_image_to_window(proc->mlx, proc->win, proc->blank, proc->b_lon, proc->b_lar);
		return ;
	}
	ft_date(proc);
	if (z % 2 == 0)
		mlx_put_image_to_window(proc->mlx, proc->win, proc->g1, proc->g_lon, proc->g_lar);
	else
		mlx_put_image_to_window(proc->mlx, proc->win, proc->g2, proc->g_lon, proc->g_lar);
}
