/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:50 by nranna            #+#    #+#             */
/*   Updated: 2024/08/04 03:26:49 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void		print_info(char **argv);
void		start_simulation(t_table *table, char **argv);
static int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5)
	{
		print_info(argv);
		start_simulation(&table, argv);
		//TODO: end_simulation(&table); PHILOS FULL || SOMEONE DIED
	}
	else if (argc == 6)
	{
		print_info(argv);
		printf("Philosophers must eat [%d] times\n", atoi(argv[5]));
		start_simulation(&table, argv);
		//TODO: end_simulation(&table); PHILOS FULL || SOMEONE DIED
	}
	else
		error_exit("Wrong input.");
	return (0);
}

//delete this function in the future
void	print_info(char **argv)
{
	printf("Number of philosophers: %d\n", atoi(argv[1]));
	printf("Time to die in ms: %d\n", atoi(argv[2]));
	printf("Time to eat in ms: %d\n", atoi(argv[3]));
	printf("Time to sleep in ms: %d\n", atoi(argv[4]));
	return ;
}

void	start_simulation(t_table *table, char **argv)
{
	t_rules	rules;

	rules.philo_amount = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules.max_meals = ft_atoi(argv[5]);
	*table = create_table(rules.philo_amount);
	give_forks(table, rules.philo_amount);
	give_threads(table, rules.philo_amount);
	return ;
}

static int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			nbr = (nbr * 10) + (str[i] - '0');
			i++;
		}
	}
	return (nbr * sign);
}
