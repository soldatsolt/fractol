#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

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

#endif