#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# include "X11/X.h"
# include "X11/keysym.h"

# include "minilibx-linux/mlx.h"

typedef struct s_x
{
	int		fd;

	void	*mlx;
	void	*win;

	int		lon;
	int		lar;

	void	*blank;

	int		b_lon;
	int		b_lar;

	void	*zero0;
	void	*one0;
	void	*two0;
	void	*three0;
	void	*four0;
	void	*five0;
	void	*six0;
	void	*seven0;
	void	*eight0;
	void	*nine0;

	void	*zero1;
	void	*one1;
	void	*two1;
	void	*three1;
	void	*four1;
	void	*five1;
	void	*six1;
	void	*seven1;
	void	*eight1;
	void	*nine1;

	int		n_lar;

	void	*g1;
	void	*g2;

	int		g_lon;
	int		g_lar;

	void	*w;
}	t_x;

int		ft_close(t_x *proc);
int		ft_handler(int key, t_x *proc);

void	ft_init_proc(t_x *proc);
void	ft_number(int n, int l, t_x *proc, int b);
void	ft_date(t_x *proc);
void	ft_animate(t_x *proc);
void	ft_purge(t_x *proc);

# define ESC 65307
# define SPC 32

#endif
