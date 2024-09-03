#include <iostream>
#include "inc/A.h"
#include "inc/B.h"

int main()
{
    Base* bs[8]{};

    for (int i = 0; i < 8; i++)
    {
        if (i & 0x1)
            bs[i] = new A();
        else
            bs[i] = new B();
    }

    for (int i = 0; i < 8; i++)
    {
        delete bs[i];
    }

    for (int i = 0; i < 8; i++)
    {
        if (i & 0x1)
            bs[i] = new A();
        else
            bs[i] = new B();
    }

    for (int i = 0; i < 8; i++)
    {
        delete bs[i];
    }
}
