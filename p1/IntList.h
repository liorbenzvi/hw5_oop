#ifndef INTLIST
#define INTLIST

template<int...>
struct IntList;

template<int H, int... Rs>
struct IntList<H, Rs...>{
    constexpr static int head = H;
    constexpr static int size =  (sizeof...(Rs))+ 1 ;
    constexpr static bool empty = false;
    typedef IntList<Rs...> next;
};

template<>
struct IntList<>{
    constexpr  static int size = 0 ;
    constexpr static bool empty = true;
};

#endif