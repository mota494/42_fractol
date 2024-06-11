#include "../fractol.h"

int	mouse_hook(int mousesym, int x, int y, t_win_info *wininfo)
{
	if (mousesym == 4)
	{
		printf("%d, %d, %d, %s\n", mousesym, x, y, wininfo->name);
	}
	return (0);
}


