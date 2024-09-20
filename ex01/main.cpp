#include "Serializer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

int main()
{
    Data original;
    original.id = 42;
    original.name = "Test";

    uintptr_t  raw = Serializer::serialize(&original);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original: " << &original << ", ID: " << original.id << ", Name: " << original.name << std::endl;
    std::cout << "Deserialized: " << deserialized << ", ID: " << deserialized->id << ", Name: " << deserialized->name << std::endl;

    return 0;
}