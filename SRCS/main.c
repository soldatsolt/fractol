#include "fractol.h"

int		cclose(void *param)
{
	free(param);
	exit(0);
}

int		deal_key(int key, t_fractol *f)
{
	if (key == B_ESC)
		return(cclose((void *)f));
	if (key == B_DOWN)
	{
		ft_putendl("DOWN");
		f->map.y += 30;
	}
	if (key == B_UP)
	{
		ft_putendl("UP");
		f->map.y -= 30;
	}
	if (key == B_LEFT)
	{
		ft_putendl("LEFT");
		f->map.x -= 30;
	}
	if (key == B_RIGHT)
	{
		ft_putendl("RIGHT");
		f->map.x += 30;
	}
	return (0);
}

int		deal_mouse(int key, t_fractol *f)
{
	if (key == 53)
		return(cclose((void *)f));
	if (key == M_SCRL_UP)
		ft_putendl("scrolls up");
	if (key == M_SCRL_DOWN)
		ft_putendl("scrolls down");
	if (key == M_L_CLCK)
		ft_putendl("CLICK");
	if (key == M_R_CLCK)
		ft_putendl("RIGHT CLICK");
	return (0);
}

int		mouse_move(int x, int y, t_fractol *f)
{
	ft_printf("x:%4d\ty:%4d\n", x, y);
	return (0);
}


int		doloop(t_fractol *f)
{
	mlx_clear_window(f->mlx.ptr, f->mlx.win);
	// makefongray(*fdf);
	// make1stgrid(fdf);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
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
	f->map.x = 0;
	f->map.y = 0;
	if (!ft_strcmp(argv[1], "mandelbrot"))
		mandelbrot(f);
	else if (!ft_strcmp(argv[1], "brsh"))
		brsh(f);
	mlx_put_image_to_window(f->mlx.ptr, f->mlx.win, f->mlx.img, 0, 0);
	mlx_hook(f->mlx.win, 17, 0, cclose, f);
	mlx_hook(f->mlx.win, 2, 0, deal_key, f);
	mlx_hook(f->mlx.win, 4, 0, deal_mouse, f);
	mlx_hook(f->mlx.win, 6, 0, mouse_move, f);
	mlx_loop_hook(f->mlx.ptr, doloop, f);
	mlx_loop(f->mlx.ptr);
	return (0);
}
