#include "lib.h"

/*	int	screen_x;
	int 	screen_y;

	system("xrandr -q | grep -w Screen | awk '{print $8}'");
	printf(" ");
	system("xrandr -q | grep -w Screen | awk '{print $10}'");

	screen_x = GetSystemMetrics(SM_CXSCREEN);
	printf("%d\n", screen_x);*/

int	main(void)
{
	t_x	proc;

	proc.mlx = mlx_init();
	if (!proc.mlx)
		return (0);
	ft_init_proc(&proc);
	proc.win = mlx_new_window(proc.mlx, proc.lon, proc.lar, "CronoGasy");
	if (!proc.win)
		return (0);
	mlx_put_image_to_window(proc.mlx, proc.win, proc.w, 0, 0);
	mlx_hook(proc.win, KeyPress, KeyPressMask, ft_handler, &proc);
	mlx_hook(proc.win, 17, 0, ft_close, &proc);
	mlx_loop(proc.mlx);
	return (0);
}
	
