#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int			check_across_2(int ns, int nu, int nd, int board)
{
	if (board % 10 == 0)
		return (1);
	if (board % 10 == ns || board % 10 == nu || board % 10 == nd)
		return (0);
	else
	{
		if (0 == check_across_2(ns, nu + 1, nd - 1, board / 10))
			return (0);
		else
			return (1);
	}
}

int			check_board_2(int b)
{
	int tab;
	int c;

	c = 0;
	tab = b;
	while (c < 8)
	{
		if ((tab % 10) == (tab / 10) % 10 || (tab % 10) == (tab / 100) % 10)
			return (0);
		if ((tab % 10) == 0 || (tab % 10) > 8)
			return (0);
		tab = tab / 10;
		c++;
	}
	while (b / 10 != 0)
	{
		if (check_across_2(b % 10, b % 10 + 1, b % 10 - 1, b / 10) == 0)
			return (0);
		b = b / 10;
	}
	return (1);
}

void		ft_eight_queens_puzzle(void)
{
	int	init_board;
	int div;

	init_board = 15863724;
	while (init_board < 84136276)
	{
		if (check_board_2(init_board) == 1)
		{
			div = 10000000;
			while (div != 0)
			{
				ft_putchar((init_board / div) % 10 + 48);
				div = div / 10;
			}
			ft_putchar('\n');
		}
		init_board = init_board + 9;
	}
}

int			main(void)
{
	ft_eight_queens_puzzle();
	return (0);
}
