#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		print_line(int len, int item)
{
	if (len > 0)
	{
		if (len == 1)
			ft_putchar(item);
		else
		{
			ft_putchar(item);
			print_line(len - 1, item);
		}
	}
}

void		build_pyramid(int height, int width, int og_width)
{
	if (height == 1)
	{
		if (width != 1)
			ft_putchar('\n');
		print_line((og_width - width) / 2, 32);
		ft_putchar(47);
		print_line(width, 42);
		ft_putchar(92);
	}
	else
	{
		build_pyramid(height - 1, width - 2, og_width);
		ft_putchar('\n');
		print_line((og_width - width) / 2, 32);
		ft_putchar(47);
		print_line(width, 42);
		ft_putchar(92);
	}
}

void		build_door(int width, int height, int square, int *og)
{
	int og_height;
	int og_width;

	og_height = og[0];
	og_width = og[1];
	if (height == og_height - square)
		build_pyramid(height, width, og_width);
	else
	{
		build_door(width - 2, height - 1, square, og);
		ft_putchar('\n');
		print_line((og_width - width) / 2, 32);
		ft_putchar(47);
		print_line(og_width / 2 - square / 2 - (og_width - width) / 2, 42);
		if (og_height - height == square / 2 && square > 3)
		{
			print_line(square - 2, 124);
			ft_putchar(36);
			ft_putchar(124);
		}
		else
			print_line(square, 124);
		print_line(width / 2 - square / 2, 42);
		ft_putchar(92);
	}
}

void		sastantua(int size)
{
	int all[4];
	int og[2];

	all[2] = 3 * size * size / 2 + 7 * size - 3;
	all[1] = 3;
	all[3] = 0;
	all[0] = 5;
	if (size > 0)
	{
		while (all[1] < size + 2)
		{
			if (all[1] % 2 == 1)
				all[3] = ((all[1] - 3) / 2) * 2 + 4;
			build_pyramid(all[1], all[0], all[2]);
			all[1]++;
			all[0] = all[0] + (all[1]) * 2 + all[3];
		}
		og[0] = size + 2;
		og[1] = all[2];
		if (size % 2 == 1)
			build_door(all[2], size + 2, size, og);
		else
			build_door(all[2], size + 2, size - 1, og);
		ft_putchar('\n');
	}
}

int		main(void)
{
	sastantua(10);
	return (0);
}
