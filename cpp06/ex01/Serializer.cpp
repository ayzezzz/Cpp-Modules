/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:53:06 by zayaz             #+#    #+#             */
/*   Updated: 2026/03/03 15:53:07 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other)
{
    *this = other;
}
Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{ 
    return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}