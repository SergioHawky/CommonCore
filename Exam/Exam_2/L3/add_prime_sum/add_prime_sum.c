/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 02:24:14 by seilkiv           #+#    #+#             */
/*   Updated: 2025/01/30 02:24:14 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_nbr(int n)
{
    if (n == 0)
    {
        write(1, "0", 1);
        return;
    }
    char digit;
    if (n >= 10)
        put_nbr(n / 10);
    digit = (n % 10) + '0';
    write(1, &digit, 1);
}

int prime(int number)
{
    int i = 2;
    
    if(number < 2)
        return 0;
    while(i <= number/2)
    {
        if(number % i == 0)
            return 0;
        i ++;
    }
    return 1;
}

int    add_prime_sum(int n)
{
    int i = 0;
    int number = 0;
    
    while(i <= n)
    {
        if(prime(i) == 1)
            number += i;
        i ++;
    }
    return(number);
}

int ft_atoi(char *str)
{
    int i = 0;
    int signal = 1;
    int number = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            signal = -1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        number = (number * 10) + (str[i] - '0');
        i++;
    }
    return (signal * number);
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        if(ft_atoi(av[1]) <= 1)
        {
            write(1, "0\n", 2);
            return 0;
        }
        else
        {
            int number = add_prime_sum(ft_atoi(av[1]));
            put_nbr(number);
            write(1, "\n", 1);
            return 0;
        }
    }
    else
        write(1, "0\n", 2);
    return 0;
}
