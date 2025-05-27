/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-input_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:57:46 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/22 12:07:09 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nbcmp(const char *n1, const char *n2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n1[i] == '+')
	{
		if (n2[j] != '+')
			i++;
	}
	else
	{
		if (n2[j] == '+')
			j++;
	}
	while (n1[i] && n2[j] && n1[i] == n2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)n1[i] - (unsigned char)n2[j]);
}

static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
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

	i = 1;
	nb_zero = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		nb_zero += is_zero(argv[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (have_duplicates(argv))
		return (0);
	return (1);
}
