#include <vector>
#include <boost/context/fiber.hpp>
#include "context.h"
#include "yield.h"

namespace coro {

static thread_local std::vector<context> g_context_stack;
static context& get_parent_context() {
    return g_context_stack.back();
}

context_stack_guard::context_stack_guard(context&& ctx) {
    g_context_stack.push_back(std::move(ctx));
}
context_stack_guard::~context_stack_guard() {
    g_context_stack.pop_back();
}

context& context_stack_guard::get_parent_context() {
    return coro::get_parent_context();
}



void yield() {
    auto& pc = get_parent_context();
    pc = std::move(pc).resume();
}

}