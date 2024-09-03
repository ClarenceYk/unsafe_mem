#ifndef _A_H_
#define _A_H_

#include "base.h"

class A : public Base
{
public:
    A();
    ~A();
    void say_hello() const override;
};

#endif
