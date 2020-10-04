#pragma once
#include "context.h"
#include "yield.h"
namespace coro {

template<class GT>
struct coroutine {
    template<class Func>
    coroutine(Func&& f) 
    : ctx_ {[f = std::forward<Func>(f)](context&& parent) {
        context_stack_guard guard(std::move(parent));
        f();
        return std::move(guard.get_parent_context());
    }}
    {}
    GT operator()() {
        ctx_ = std::move(ctx_).resume();
    }
    operator bool() {
        return (bool)ctx_;
    }
private:
    context ctx_;
};

} // namespace coro 
