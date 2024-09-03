#ifndef _UNSAFE_MEM_H_
#define _UNSAFE_MEM_H_

#include "max_type_size_impl.h"
#include <iostream>

constexpr std::size_t align = 8;

template<std::size_t ITEM_SIZE, int ITEM_COUNT>
class Unsafe_Mem
{
private:
    static constexpr std::size_t ITEM_SIZE_ALIGNED = (ITEM_SIZE%align) ? ((ITEM_SIZE/align) + 1)*align : ITEM_SIZE;
    static constexpr std::size_t TOTAL_BYTES = ITEM_SIZE_ALIGNED * ITEM_COUNT;

public:
    Unsafe_Mem()
    {
        for (int i = 0; i < ITEM_COUNT; i++)
        {
            next_free[i] = i + 1;
        }
    }

    void* Get_Obj()
    {
        if (cur_index < 0 || cur_index >= ITEM_COUNT) return nullptr;

        void* ptr = buf + cur_index * ITEM_SIZE_ALIGNED;

        int next = next_free[cur_index];
        next_free[cur_index] = -1;
        cur_index = next;

        return ptr;
    }

    void Rel_Obj(void* p)
    {
        void* p_start = buf;
        uintptr_t diff = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(p_start);
        int index = diff / ITEM_SIZE_ALIGNED;

        // this memory doesn't belong to this class
        if (index < 0 || index >= ITEM_COUNT) return;

        next_free[index] = cur_index;
        cur_index = index;
    }

    void print()
    {
        for (int i = 0; i < ITEM_COUNT; i++)
        {
            std::cout << next_free[i] << std::endl;
        }
        std::cout << TOTAL_BYTES << std::endl;
    }

private:
    uint8_t buf[TOTAL_BYTES];
    int next_free[ITEM_COUNT];
    int cur_index{};
};

#endif
