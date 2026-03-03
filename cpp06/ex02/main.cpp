/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:55:14 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/03 15:55:16 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    std::srand(std::time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    std::cout << std::endl;
    delete base;

    Base *base2 = generate();
    identify(base2);
    identify(*base2);
    std::cout << std::endl;
    delete base2;
}

//  #include <iostream>
// #include "Base.hpp"
// #include "A.hpp"
// #include "B.hpp"

// int main()
// {
//     A a;
//     B b;

//     Base *pa = &a;
//     Base *pb = &b;

//     if (dynamic_cast<A *>(pa))
//         std::cout << "pa  A\n";
//     if (!dynamic_cast<A *>(pb))
//         std::cout << "pb not A  (nullptr)\n";

//     try
//     {
//         A &ra = dynamic_cast<A &>(a);
//         (void)ra;
//         std::cout << "ra  A\n";
//     }
//     catch(const std::exception& e){}
//     {
//     }

//     try
//     {
//         A &rb = dynamic_cast<A &>(b); 
//          (void)rb;
//         std::cout << "rb  A\n";
//     }
//     catch(const std::exception& e){}
//     {
//         std::cout << "rb not A (exception)\n";
//     }

//     return 0;
// } 