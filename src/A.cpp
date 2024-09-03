#include "../inc/A.h"

A::A()
{
    std::cout << "create A" << std::endl;
}

A::~A()
{
    std::cout << "destroy A" << std::endl;
}

void A::say_hello() const
{
    std::cout << "hello from A~" << std::endl;
}
