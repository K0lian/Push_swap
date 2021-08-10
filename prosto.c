#include "push_swap.h"

void	moves(t_str *str, int i)
{
	str->num_move -= 2;
	str->hiy[i] = -1;
	str->hiy[i + 1] = -1;
}

void	lot_ifs(t_str *str, int i)
{
	if ((str->hiy[i] == 5 && str->hiy[i + 1] == 7) || (str->hiy[i] == 7
			&& str->hiy[i + 1] == 5))
		moves(str, i);
	if ((str->hiy[i] == 6 && str->hiy[i + 1] == 8) || (str->hiy[i] == 8
			&& str->hiy[i + 1] == 6))
		moves(str, i);
	if (str->hiy[i] == 1 && str->hiy[i + 1] == 1)
		moves(str, i);
	if (str->hiy[i] == 2 && str->hiy[i + 1] == 2)
		moves(str, i);
	if ((str->hiy[i] == 3 && str->hiy[i + 1] == 4) || (str->hiy[i] == 4
			&& str->hiy[i + 1] == 3))
		moves(str, i);
}

void	movez(t_str *str, int i, int h)
{
	str->num_move -= 1;
	str->hiy[i] = -1;
	str->hiy[i + 1] = h;
}

void	prosto(t_str *str)
{
	int	i;

	i = -1;
	while (++i < str->num_move * 2)
	{
		if (!str->hiy[i])
			break ;
		lot_ifs(str, i);
		if ((str->hiy[i] == 8 && str->hiy[i + 1] == 7) || (str->hiy[i] == 7
				&& str->hiy[i + 1] == 8))
			movez(str, i, 9);
		if ((str->hiy[i] == 5 && str->hiy[i + 1] == 6) || (str->hiy[i] == 6
				&& str->hiy[i + 1] == 5))
			movez(str, i, 10);
		if ((str->hiy[i] == 1 && str->hiy[i + 1] == 2) || (str->hiy[i] == 2
				&& str->hiy[i + 1] == 1))
			movez(str, i, 11);
	}
}
