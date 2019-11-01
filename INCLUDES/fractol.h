#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

# define MAX_X		1.0
# define MIN_X		-3.0
# define MIN_Y		-1.0
# define MAX_Y		MIN_Y + (MAX_X - MIN_X) * SCREEN_HEIGHT / SCREEN_WIDTH
# define SHIFT_X	(MAX_X - MIN_X) / (SCREEN_WIDTH - 1)
# define SHIFT_Y	(MAX_Y - MIN_Y) / (SCREEN_HEIGHT - 1)
# define REPEATS	30

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_l;
	int				endn;
}					t_mlx;

typedef struct		s_cmplx
{
	int				key;
	double			c_x;
	double			c_y;
	double			z_x;
	double			z_y;
	double			sqr_z_x;
	double			sqr_z_y;
}					t_cmplx;

typedef struct		s_fractol
{
	int				key;
	int				color;
	t_mlx			mlx;
	t_cmplx			cmplx;
}					t_fractol;

void				main_drow(int x, int y, t_fractol *f);
void				mandelbrot(t_fractol *fractol);
void				brsh(t_fractol *fractol);

#endif
