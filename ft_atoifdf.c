/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoifdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:50:58 by dvauthey          #+#    #+#             */
/*   Updated: 2024/12/16 12:00:43 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_ismin(const char *str)
{
	char	*max;

	max = "-2147483648";
	if (str == max)
		return (1);
	return (0);
}

static char	*cut_str(const char *str, int start, int end)
{
	int		i;
	char	*str_cut;

	i = 0;
	str_cut = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!str_cut)
		return (NULL);
	while (i + start < end)
	{
		str_cut[i] = str[i + start];
		i++;
	}
	str_cut[i] = '\0';
	return (str_cut);
}

int	ft_atoifdf(const char *str, int start, int end)
{
	int		i;
	int		result;
	int		isneg;
	char	*str_cut;

	i = 0;
	result = 0;
	isneg = 1;
	str_cut = cut_str(str, start, end);
	if (ft_ismin(str_cut))
		return (-2147483648);
	while ((str_cut[i] >= 9 && str_cut[i] <= 13) || str_cut[i] == ' ')
		i++;
	if (str_cut[i] == '+' || str_cut[i] == '-')
	{
		if (str_cut[i] == '-')
			isneg = -1;
		i++;
	}	
	while (str_cut[i] && (str_cut[i] >= '0' && str_cut[i] <= '9'))
	{
		result = result * 10 + (str_cut[i] - '0');
		i++;
	}
	return (result * isneg);
}
