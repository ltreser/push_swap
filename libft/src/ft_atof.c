/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:32:07 by ltreser           #+#    #+#             */
/*   Updated: 2024/02/29 23:40:27 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(const char *str)
{
	double	result;
	double	power;
	char	*dec_point;
	int		sign;
	int		i;

	sign = 1;
	power = 1.0;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	result = (double)ft_atoi(str++);
	dec_point = ft_strchr(str, '.');
	if (dec_point)
	{
		i = dec_point - str + 1;
		while (ft_isdigit(str[i]))
		{
			result = result * 10.0 + (str[i++] - '0');
			power *= 10.0;
		}
	}
	return (result * sign / power);
}
