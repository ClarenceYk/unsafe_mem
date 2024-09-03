#ifndef _B_H_
#define _B_H_

#include "base.h"

class B : public Base
{
public:
    B();
    ~B();
    void say_hello() const override;
};

#endif
