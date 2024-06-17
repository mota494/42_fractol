int	arrow_check(int keysym)
{
	if (keysym == 65361 || keysym == 65362)
		return (1);
	else if (keysym == 65363 || keysym == 65364)
		return (1);
	return (0);
}
