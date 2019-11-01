#include "fractol.h"

int		cclose(void *param)
{
	free(param);
	exit(0);
}

int		deal_key(int key, t_fractol *f)
{
	if (key == 53)
		return(cclose((void *)f));
	return (0);
}

int main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc != 2 || (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "brsh")))
	{
		ft_putendl("Usage: ./fractol [mandelbrot|brsh]");
		return (0);
	}
	f = (t_fractol *)malloc(sizeof(t_fractol));
	f->mlx.ptr = mlx_init(1);
	f->mlx.win = mlx_new_window(f->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	f->mlx.img = mlx_new_image(f->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	f->mlx.data = (int *)mlx_get_data_addr(f->mlx.img, &(f->mlx.bpp), &(f->mlx.size_l),\
	&(f->mlx.endn));
	if (!ft_strcmp(argv[1], "mandelbrot"))
		mandelbrot(f);
	else if (!ft_strcmp(argv[1], "brsh"))
		brsh(f);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
	mlx_hook(f->mlx.win, 17, 0, cclose, f);
	mlx_hook(f->mlx.win, 2, 0, deal_key, f);
	mlx_loop(f->mlx.ptr);
	return (0);
}
