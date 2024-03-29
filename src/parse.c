/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:34:42 by jisse             #+#    #+#             */
/*   Updated: 2023/03/15 13:24:48 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_input(t_philo *philo, int index)
{
	philo->left_fork = &(philo->bin->fork[index]);
	if (philo->bin->number_of_philo == index + 1)
		philo->right_fork = &(philo->bin->fork[0]);
	else
		philo->right_fork = &(philo->bin->fork[index + 1]);
}

int	ft_atoi_overflow(const char *str, int *numb)
{
	int	i;
	int	sign;

	i = 0;
	*numb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
				i++;
	if (str[i] == '-')
			sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*numb += str[i] - '0';
		if (*numb < 0 && (*numb != INT_MIN || sign == 1))
			return (1);
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			*numb *= 10;
		i++;
	}
	*numb *= sign;
	return (0);
}

int	argument_conversion(t_bin *bin, int argc, char *argv[])
{
	int	i;
	int	numb[5];

	i = 1;
	bin->eat_till_full = false;
	bin->each_philo_must_eat = 0;
	bin->number_of_philo_full = 0;
	if (argc == 6)
		bin->eat_till_full = true;
	while (i < argc)
	{
		if (ft_atoi_overflow(argv[i], &numb[i - 1]))
			return (EXIT_FAILURE);
		if (numb[i - 1] < 1)
			return (EXIT_FAILURE);
		i++;
	}
	bin->number_of_philo = numb[0];
	bin->time_to_die = numb[1] * MICRO_SECONDS;
	bin->time_to_eat = numb[2] * MICRO_SECONDS;
	bin->time_to_sleep = numb[3] * MICRO_SECONDS;
	if (bin->eat_till_full)
		bin->each_philo_must_eat = numb[4];
	return (EXIT_SUCCESS);
}
