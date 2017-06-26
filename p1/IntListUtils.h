#ifndef INTLISTUTILS
#define INTLISTUTILS
#include "IntList.h"

template<bool b, int A, int B>
struct EQL {
    constexpr static int big = A;
    constexpr static int small = B;
};

template<int A, int B>
struct EQL<false, A, B> {
    constexpr static int big = B;
    constexpr static int small = A;
};

template<typename A>
struct IntListUtils {
    typedef IntList<> reversed;
};


template<int A>
struct IntListUtils<IntList<A>> {
    constexpr static int max = A;
    constexpr static int min = A;
    typedef IntList<A> reversed;
};

template<int A, int B>
struct IntListUtils<IntList<A, B>> {
    constexpr static int max = EQL<(A>B),A,B>::big;
    constexpr static int min = EQL<(A>B),A,B>::small;
    typedef IntList<B,A> reversed;
};

template<int A, int B, int... RS>
struct IntListUtils<IntList<A,B,RS...>> {
    constexpr static int max = IntListUtils<IntList<EQL<(A>B),A,B>::big,RS...>>::max;
    constexpr static int min = IntListUtils<IntList<EQL<(A>B),A,B>::small,RS...>>::min;
    typedef typename IntListUtils<IntList<RS...>>::reversed res;
    typedef typename ConcatedIntLists< res, IntList<B,A>>::list reversed;
};


#endif // !INTLISTUTILS
