#include "lib.h"

void	ft_init_proc(t_x *proc)
{
	int	a;
	int	b;

	a = 0;
	b = 0;

	proc->fd = open("date.txt", O_RDONLY);
	proc->lon = 1920;
	proc->lar = 1080;

	proc->blank = mlx_xpm_file_to_image(proc->mlx, "Tiles/blank.xpm", &a, &b);
	proc->w = mlx_xpm_file_to_image(proc->mlx, "Tiles/w.xpm", &a, &b);
	proc->b_lon = (proc->lon - 565) / 2;
	proc->b_lar = ((proc->lar - 834) * 1) / 4;

	proc->zero0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/zero0.xpm", &a, &b);
	proc->one0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/one0.xpm", &a, &b);
	proc->two0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/two0.xpm", &a, &b);
	proc->three0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/three0.xpm", &a, &b);
	proc->four0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/four0.xpm", &a, &b);
	proc->five0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/five0.xpm", &a, &b);
	proc->six0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/six0.xpm", &a, &b);
	proc->seven0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/seven0.xpm", &a, &b);
	proc->eight0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/eight0.xpm", &a, &b);
	proc->nine0 = mlx_xpm_file_to_image(proc->mlx, "Tiles/b/nine0.xpm", &a, &b);

	proc->zero1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/zero1.xpm", &a, &b);
	proc->one1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/one1.xpm", &a, &b);
	proc->two1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/two1.xpm", &a, &b);
	proc->three1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/three1.xpm", &a, &b);
	proc->four1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/four1.xpm", &a, &b);
	proc->five1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/five1.xpm", &a, &b);
	proc->six1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/six1.xpm", &a, &b);
	proc->seven1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/seven1.xpm", &a, &b);
	proc->eight1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/eight1.xpm", &a, &b);
	proc->nine1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/r/nine1.xpm", &a, &b);
	proc->n_lar = proc->b_lar - 64;

	proc->g1 = mlx_xpm_file_to_image(proc->mlx, "Tiles/g/g1.xpm", &a, &b);
	proc->g2 = mlx_xpm_file_to_image(proc->mlx, "Tiles/g/g2.xpm", &a, &b);
	proc->g_lon = proc->b_lon;
	proc->g_lar = proc->b_lar + 64;
}

void	ft_purge(t_x *proc)
{
	mlx_destroy_image(proc->mlx, proc->blank);
	mlx_destroy_image(proc->mlx, proc->w);

	mlx_destroy_image(proc->mlx, proc->zero0);
	mlx_destroy_image(proc->mlx, proc->one0);
	mlx_destroy_image(proc->mlx, proc->two0);
	mlx_destroy_image(proc->mlx, proc->three0);
	mlx_destroy_image(proc->mlx, proc->four0);
	mlx_destroy_image(proc->mlx, proc->five0);
	mlx_destroy_image(proc->mlx, proc->six0);
	mlx_destroy_image(proc->mlx, proc->seven0);
	mlx_destroy_image(proc->mlx, proc->eight0);
	mlx_destroy_image(proc->mlx, proc->nine0);

	mlx_destroy_image(proc->mlx, proc->zero1);
	mlx_destroy_image(proc->mlx, proc->one1);
	mlx_destroy_image(proc->mlx, proc->two1);
	mlx_destroy_image(proc->mlx, proc->three1);
	mlx_destroy_image(proc->mlx, proc->four1);
	mlx_destroy_image(proc->mlx, proc->five1);
	mlx_destroy_image(proc->mlx, proc->six1);
	mlx_destroy_image(proc->mlx, proc->seven1);
	mlx_destroy_image(proc->mlx, proc->eight1);
	mlx_destroy_image(proc->mlx, proc->nine1);

	mlx_destroy_image(proc->mlx, proc->g1);
	mlx_destroy_image(proc->mlx, proc->g2);
}

int	ft_close(t_x *proc)
{
	ft_purge(proc);
	if (proc->win)
		mlx_destroy_window(proc->mlx, proc->win);
	mlx_destroy_display(proc->mlx);

	free(proc->mlx);
	close(proc->fd);
	return (exit(0), 0);
}

int	ft_handler(int key, t_x *proc)
{
	if (key == ESC)
		ft_close(proc);
	else if (key == SPC)
		ft_animate(proc);
	return (0);
}
