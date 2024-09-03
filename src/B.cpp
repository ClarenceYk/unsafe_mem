#include "../inc/B.h"

B::B()
{
    std::cout << "create B" << std::endl;
}

B::~B()
{
    std::cout << "destroy B" << std::endl;
}

void B::say_hello() const
{
    std::cout << "hello from B~" << std::endl;
}
