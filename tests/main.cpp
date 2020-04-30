//#include "tst_test1.h"
//#include "fibonachi_test.h"
#include "move_test.h"
#include "plb_test.h"
#include "save_test.h"
#include "split_test.h"
#include "common_test.h"
//#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
