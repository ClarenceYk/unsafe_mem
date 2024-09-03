#ifndef _MAX_TYPE_SIZE_
#define _MAX_TYPE_SIZE_

#include <cstddef>

template<typename... TYPES>
struct MetaTypeMaxSize;

template<typename T>
struct MetaTypeMaxSize<T>
{
    static constexpr std::size_t value = sizeof(T);
};

template<typename T, typename... Rof_TYPES>
struct MetaTypeMaxSize<T, Rof_TYPES...>
{
private:
    static constexpr std::size_t rest_val = MetaTypeMaxSize<Rof_TYPES...>::value;

public:
    static constexpr std::size_t value = sizeof(T) > rest_val ? sizeof(T) : rest_val;
};

#endif