/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:56:54 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/03 15:56:55 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.i = 42;
    data.c = 'A';

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer     : " << originalPtr << std::endl;
    std::cout << "Serialized integer   : " << raw << std::endl;
    std::cout << "Deserialized pointer : " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr)
        std::cout << "Pointers are equal" << std::endl;
    else
        std::cout << "Pointers are not equal" << std::endl;

    std::cout << "Data integer value   : " << deserializedPtr->i << std::endl;
    std::cout << "Data character value : " << deserializedPtr->c << std::endl;

    return 0;
}