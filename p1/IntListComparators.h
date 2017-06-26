#ifndef INTLISTCOMPARATORS
#define INTLISTCOMPARATORS
#include "IntList.h"

template<bool b1, bool b2>
struct AND {
    constexpr static bool b = true;
};

template<>
struct AND<false, true> {
    constexpr static bool b = false;
};

template<>
struct AND<true, false> {
    constexpr static bool b = false;
};

template<>
struct AND<false, false> {
    constexpr static bool b = false;
};

template<typename L1, typename L2>
struct IntListsEqual {
    constexpr static bool value = true;
};
template<>
struct IntListsEqual<IntList<>,IntList<>> {
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
    constexpr static bool rest = IntListsEqual<IntList<RS1...>, IntList<RS2...>>::value;
    constexpr static bool value = AND<(H1==H2), rest>::b ;
};

/*
 * ===========================
 * OR
 * ===========================
 */


template<bool b1, bool b2>
struct OR {
    constexpr static bool b = true;
};

template<>
struct OR<false, true> {
    constexpr static bool b = true;
};

template<>
struct OR<true, false> {
    constexpr static bool b = true;
};

template<>
struct OR<false, false> {
    constexpr static bool b = false;
};

/*
 * ===========================
 * IntListContains
 * ===========================
 */

template<typename A,int... B>
struct IntListContains {
	constexpr static bool value = false;
};
template<>
struct IntListContains<IntList<>> {
	constexpr static bool value = true;
};

template<int Y>
struct IntListContains<IntList<>,Y> {
	constexpr static bool value = false;
};

template<int... XS>
struct IntListContains<IntList<XS...>> {
	constexpr static bool value = false;
};

template<int X,int... XS,int Y,int... YS>
struct IntListContains<IntList<X,XS...>,Y,YS...> {
	constexpr static bool value = AND<(X==Y),IntListContains<IntList<XS...>,YS...>::value>::b;
};


/*
 * ==========================
 * IntListIndexEquals
 * ==========================
 */

template<typename A,int... XS>
struct IntListIndexEquals {
	constexpr static bool value = false;
};

template<int... XS>
struct IntListIndexEquals<IntList<>,XS...> {
	constexpr static bool value = false;
};

template<int X,int... XS,int N>
struct IntListIndexEquals<IntList<X,XS...>,0,N> {
	constexpr static bool value = X==N;
};

template<int X,int... XS,int I,int N>
struct IntListIndexEquals<IntList<X,XS...>,I,N> {
	constexpr static int idx = I-1;
	constexpr static bool value = IntListIndexEquals<IntList<XS...>,idx,N>::value;
};


#endif // !INTLISTCOMPARATORS
