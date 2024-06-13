#include "../fractol.h"

int	mouse_hook(int mousesym, int x, int y, t_win_info *wininfo)
{
	double zoom;

	zoom = 0.2;
	printf("%d, %d", x, y);
	printf("%d, %d", wininfo->c_x, wininfo->c_y);
	if (mousesym == 4)
	{
		wininfo->zoom = wininfo->zoom + zoom;
		maps_select(wininfo);
	}
	else if (mousesym == 5)
	{
		wininfo->zoom = wininfo->zoom - zoom;
		maps_select(wininfo);
	}
	return (0);
}

/*void	movement(int keysym, t_win_info *wininfo)
{
}*/
