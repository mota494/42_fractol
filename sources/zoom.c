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

void	movement(int keysym, t_win_info *wininfo)
{
	if (keysym == 65361)
		wininfo->move_x = wininfo->move_x - 0.08;
	else if (keysym == 65363)
		wininfo->move_x = wininfo->move_x + 0.08;
	else if (keysym == 65362)
		wininfo->move_y = wininfo->move_y - 0.08;
	else if (keysym == 65364)
		wininfo->move_y = wininfo->move_y + 0.08;
	maps_select(wininfo);
}
