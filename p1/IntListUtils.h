#ifndef INTLISTUTILS
#define INTLISTUTILS
#include "IntList.h"


template<int H1, int... RS1>
struct IntListUtils<IntList<>,IntList<H1,RS1...>> {
    typedef IntList<H1,RS1...> list;

};


#endif // !INTLISTUTILS
