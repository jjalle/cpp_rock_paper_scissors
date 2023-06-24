#define GTEST_LANG_CXX11 1
#include <gtest/gtest.h>


int main(int _argc, char * _argv []) {
    testing::InitGoogleTest(&_argc, _argv);
    int result = RUN_ALL_TESTS();
    return result;
}