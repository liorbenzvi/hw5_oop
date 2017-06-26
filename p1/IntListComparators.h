#ifndef INTLISTCOMPARATORS
#define INTLISTCOMPARATORS
#include "IntList.h"

template<bool b1, bool b2>
struct BOOL {
    constexpr static bool b = true;
};

template<>
struct BOOL<false, true> {
    constexpr static bool b = false;
};

template<>
struct BOOL<true, false> {
    constexpr static bool b = false;
};

template<>
struct BOOL<false, false> {
    constexpr static bool b = false;
};

template<typename L1, typename L2>
struct IntListsEqual {
    constexpr static bool value = true;
};

template<int... L1>
struct IntListsEqual<IntList<L1...>,IntList<>> {
    constexpr static bool value = false;
};

template<int... L1>
struct IntListsEqual<IntList<>, IntList<L1...>> {
    constexpr static bool value = false;
};

template<int H1, int H2>
struct IntListsEqual<IntList<H1>, IntList<H2>> {
    constexpr static bool value = (H1==H2);
};

template<int H1, int... RS1, int H2, int... RS2>
struct IntListsEqual<IntList<H1,RS1...>,IntList<H2,RS2...>> {
    typedef typename IntListsEqual<IntList<RS1...>, IntList<RS2...>>::value rest;
    constexpr static bool value = BOOL<(H1==H2), rest>::b ;
};

#endif // !INTLISTCOMPARATORS
