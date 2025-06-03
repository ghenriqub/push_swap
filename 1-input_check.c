/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-input_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:57:46 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/03 13:08:54 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nbcmp(const char *n1, const char *n2)
{
	int	str1;
	int	str2;

	str1 = ft_atol(n1);
	str2 = ft_atol(n2);
	if (str1 == str2)
		return (0);
	return (1);
}

static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (i != j && nbcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
		i++;
	if (argv[i] != '\0' && !(argv[i] >= '0' && argv[i] <= '9'))
		return (0);
	return (1);
}

static int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] && (argv[i] == '0'))
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = -1;
	while (argv[++i])
	{
		if (!is_number(argv[i]))
		{
			exit_error(NULL, NULL);
			return (0);
		}
		nb_zero += is_zero(argv[i]);
	}
	if (nb_zero > 1 || have_duplicates(argv))
	{
		exit_error(NULL, NULL);
		return (0);
	}
	return (1);
}
