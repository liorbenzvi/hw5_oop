#ifndef INTLISTUTILS
#define INTLISTUTILS
#include "IntList.h"

template<bool b, int A, int B>
struct BIG {
    constexpr static int big = A;
};

template<int A, int B>
struct BIG<false, A, B> {
    constexpr static int big = B;
};

template<typename A>
struct IntListUtils {
    typedef IntList<>reversed;
};


template<int A>
struct IntListUtils<IntList<A>> {
    constexpr static int max = A;
    typedef IntList<A>reversed;
};

template<int A, int B>
struct IntListUtils<IntList<A, B>> {
    constexpr static int max = BIG<(A>B),A,B>::big;
    typedef IntList<B,A> reversed;
};

template<int A, int B, int... RS>
struct IntListUtils<IntList<A,B,RS...>> {
    constexpr static int max = IntListUtils<IntList<BIG<(A>B),A,B>::big,RS...>>::max;
    typedef typename IntListUtils<IntList<RS...>>::reversed res;
    typedef typename ConcatedIntLists< res, IntList<B,A>>::list reversed;
};


#endif // !INTLISTUTILS
