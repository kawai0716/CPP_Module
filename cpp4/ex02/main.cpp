/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:44:39 by marvin            #+#    #+#             */
/*   Updated: 2025/09/26 15:44:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal *a = new Animal();
    
    const int N = 4;
    Animal *zoo[N];

    for(int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    for(int i = 0; i < N; i++)
    {
        std::cout << zoo[i]->getType() << ": ";
        zoo[i]->makeSound();
    }

    for(int i = 0; i < N; i++)
        delete zoo[i];

    return 0;
}