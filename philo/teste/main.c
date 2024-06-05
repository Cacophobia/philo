/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nranna <nranna@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:50 by nranna            #+#    #+#             */
/*   Updated: 2024/06/05 14:42:52 by nranna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_info(char **argv);

//each philo is a thread
int	main(int argc, char **argv)
{
	if (argc == 5)
	{

		start_simulation(atoi(argv[1]), flag); //TODO: create_philos, forks and table.

		printf("Number of philosophers: %d\n", atoi(argv[1]));
		printf("Time to die in ms: %d\n", atoi(argv[2]));
		printf("Time to eat in ms: %d\n", atoi(argv[3]));
		printf("Time to sleep in ms: %d\n", atoi(argv[4]));
	}
	if (argc == 6)
	{
		print_info(argv);
		printf("Philosophers must eat [%d] times\n", atoi(argv[5]));
	}
	return (0);
}

void	print_info(char **argv)
{
	printf("Number of philosophers: %d\n", atoi(argv[1]));
	printf("Time to die in ms: %d\n", atoi(argv[2]));
	printf("Time to eat in ms: %d\n", atoi(argv[3]));
	printf("Time to sleep in ms: %d\n", atoi(argv[4]));
	return ;	
}

void	start_simulation(t_table table, char **argv)
{
	int	philos_amount;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
	t_table	table;

	philos_amount = atoi(argv[1]);
	time_to_die = atoi(argv[2]);
	time_to_eat = atoi(argv[3]);
	time_to_sleep = atoi(argv[4]);
	if (argv[5])
		max_meals = atoi(argv[5]);
	create_table(&table, philos_amount);
}

void	create_table(t_table *table, int philos_amount)
{
	
}
