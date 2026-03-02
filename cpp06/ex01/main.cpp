#include "Serializer.hpp"

int main()
{
    Data data;

    data.i = 42;
    data.c = 'A';

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer     : " << originalPtr << std::endl;
    std::cout << "Deserialized pointer : " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr)
        std::cout << "Pointer'lar ESIT ✅" << std::endl;
    else
        std::cout << "Pointer'lar ESIT DEGIL ❌" << std::endl;

    std::cout << "Data.i = " << deserializedPtr->i << std::endl;
    std::cout << "Data.c = " << deserializedPtr->c << std::endl;

    return 0;
}