#ifndef MERGEDLIST
#define MERGEDLIST

#include "ConcatedIntLists.h"
#include "IntList.h"

template<typename L1, typename L2>
struct MergedIntLists {
    typedef IntList<> list;
};

template<int H1, int... RS1>
struct MergedIntLists<IntList<>,IntList<H1,RS1...>> {
    typedef IntList<H1,RS1...> list;

};

template<int H1, int... RS1>
struct MergedIntLists<IntList<H1,RS1...>,IntList<>> {
    typedef IntList<H1,RS1...> list;

};

template<int H1, int... RS1, int H2, int... RS2>
struct MergedIntLists<IntList<H1,RS1...>,IntList<H2,RS2...>> {
    typedef typename MergedIntLists<IntList<RS1...>,IntList<RS2...>>::list rest;
    typedef typename ConcatedIntLists<IntList<H1,H2>,rest>::list list;

};


#endif // !MERGEDLIST