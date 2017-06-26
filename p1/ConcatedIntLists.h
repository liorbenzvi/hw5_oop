#ifndef CONCATEDINTLISTS
#define CONCATEDINTLISTS
#include "IntList.h"
template<typename ... XS>
struct ConcatedIntLists {
    typedef IntList<> list;
};

template<int... XS>
struct ConcatedIntLists<IntList<XS...>> {
    typedef IntList<XS...> list;
};

template<int... XS,int... YS>
struct ConcatedIntLists<IntList<XS...>,IntList<YS...>> {
    typedef IntList<XS...,YS...> list;

};

template<int... XS,int... YS,typename... ZS>
struct ConcatedIntLists<IntList<XS...>,IntList<YS...>,ZS...> {
    typedef typename ConcatedIntLists<IntList<XS...>,IntList<YS...>>::list temp;
    typedef typename ConcatedIntLists<temp,ZS...>::list list;
};


#endif // !CONCATEDINTLISTS
