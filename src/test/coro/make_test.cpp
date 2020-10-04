#include <coro/make.hpp>
#include <gtest/gtest.h>
using namespace coro;
TEST(example, void_coro) {
    int i = 0;
    auto co_func = make([&](){
        i ++;
        yield();
        i ++;
    });
    EXPECT_TRUE((bool)co_func);
    co_func();
    EXPECT_EQ(i, 1);
    EXPECT_TRUE((bool)co_func);
    co_func();
    EXPECT_EQ(i, 2);
    EXPECT_FALSE((bool)co_func);
}
// TEST(example, gen_int_coro) {
//     auto co_func = make<int>([](){
//         int i = 0;
//         yield(++i);
//         yield(++i);
//         yield(++i);
//     });
//     EXPECT_TRUE((bool)co_func);
//     EXPECT_EQ(co_func(), 1);
//     EXPECT_TRUE((bool)co_func);
//     EXPECT_EQ(co_func(), 2);
//     EXPECT_TRUE((bool)co_func);
//     EXPECT_EQ(co_func(), 3);
// }