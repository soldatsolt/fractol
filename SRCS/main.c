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

// int		doloop(t_fdf *fdf)
// {
// 	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
// 	makefongray(*fdf);
// 	make1stgrid(fdf);
// 	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, \
// 	(*fdf).img_ptr, 0, 0);
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	f->mlx.ptr = mlx_init(1);
	f->mlx.win = mlx_new_window(f->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	f->mlx.img = mlx_new_image(f->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	f->mlx.data = (int *)mlx_get_data_addr(f->mlx.img, &(f->mlx.bpp), &(f->mlx.size_l),\
	&(f->mlx.endn));
	mlx_hook(f->mlx.win, 17, 0, cclose, f);
	mlx_hook(f->mlx.win, 2, 0, deal_key, f);
	mlx_loop(f->mlx.ptr);
	return (0);
}
