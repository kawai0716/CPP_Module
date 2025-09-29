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
    std::cout << "----- leak check test -----" << std::endl;
    const int N = 6;
    Animal* animal[N];

    for(int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
    }
    for(int i = 0; i < N; i++)
        animal[i]->makeSound();
    for(int i = 0; i < N; i++)
        delete animal[i];

    std::cout << "----- Deep copy test (Dog)-----" << std::endl;
    Dog a;
    a.setIdea(0, "eat");

    Dog b = a;
    std::cout << "a[0]=" << a.getIdea(0) << ", b[0]=" << b.getIdea(0) << std::endl;

    b.setIdea(0, "sleep");
    std::cout << "a[0]=" << a.getIdea(0) << ", b[0]=" << b.getIdea(0) << std::endl;

    std::cout << "----- Deep copy test (Cat)-----" << std::endl;
    Cat x;
    x.setIdea(0, "play");

    Cat y;
    y = x;
    std::cout << "x[0]=" << x.getIdea(0) << ", y[0]=" << y.getIdea(0) << std::endl;
    y.setIdea(0, "hunt");
    std::cout << "x[0]=" << x.getIdea(0) << ", y[0]=" << y.getIdea(0) << std::endl;

    std::cout << "----- destructor -----" << std::endl;
    return 0;
}