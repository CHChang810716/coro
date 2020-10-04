#pragma once
#include "coroutine.hpp"
namespace coro {

template<class GT = void, class Func = void>
auto make(Func&& func) {
    return coroutine<GT>(std::forward<Func>(func));
}
}
