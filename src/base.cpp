#include "../inc/A.h"
#include "../inc/B.h"
#include "../inc/unsafe_mem_impl.h"

Unsafe_Mem<MetaTypeMaxSize<A, B>::value, 8> Base_Mem;

Base::Base()
{
    std::cout << "create Base" << std::endl;
}

Base::~Base()
{
    std::cout << "destroy Base" << std::endl;
}

void Base::say_hello() const
{
    std::cout << "hello from Base~" << std::endl;
}

void* Base::operator new(std::size_t)
{
    std::cout << "new for Base~" << std::endl;
    return Base_Mem.Get_Obj();
}

void Base::operator delete(void* p)
{
    std::cout << "delete for Base~" << std::endl;
    Base_Mem.Rel_Obj(p);
}