/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:15:30 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 14:26:00 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 5);

    Point p(3.5f, 3.0f);
    //  Point p(4.9f, 2.9f)
    //  Point p(11, 10);
    //  Point p(5, 0);
    //Point p(7, 7);

    if (bsp(A, B, C, p))
        std::cout << "That's true, man 🦅 🦅 " << std::endl;
    else
        std::cout << "False, man 🦃 🦃" << std::endl;

    return 0;
}
