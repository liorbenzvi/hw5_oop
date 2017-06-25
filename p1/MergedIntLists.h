#ifndef MERGEDLIST
#define MERGEDLIST
#include "IntList.h"

template<class L1, class L2>
struct MergedIntLists<L1,L2>{
    typedef IntList<typename L1::head, typename L2::head, MergedIntLists<typename L1::next, typename L2::next>::list> list;
};

template<class L1>
struct MergedIntLists<L1>{
    typedef L1 list;
};

template<>
struct MergedIntLists<>{
    typedef IntList<> list;
};

#endif // !MERGEDLIST