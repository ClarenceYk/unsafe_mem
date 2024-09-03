#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>

class Base
{
public:
    Base();
    virtual ~Base();
    virtual void say_hello() const;

    void* operator new(std::size_t);
    void operator delete(void* p);

private:
    int a{};
};

#endif
