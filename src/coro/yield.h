#pragma once
#include <vector>
#include "context.h"

// namespace coro {
// 
// template<class GT> struct coroutine;
// 
// }

namespace coro {
struct context_stack_guard {

    template<class GT> 
    friend struct coroutine;
    
    context_stack_guard(context&& ctx);
    ~context_stack_guard();
private:
    context& get_parent_context();
};

void yield();

}