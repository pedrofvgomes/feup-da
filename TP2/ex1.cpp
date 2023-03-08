// By: Gonçalo Leão

#include "exercises.h"
/* a)
 * if(T<3) return false;
    nums[0] = nums[1] = nums[2] = 1;
    while(true){
        for(int i=1; i<=T; i++)
            for(int j=1; j<=T; j++)
                for(int k=1; k<=T; k++)
                    if(i+j+k==T){
                        nums[0] = i;
                        nums[1] = j;
                        nums[2] = k;
                        return true;
                    }
    }
 */

// b)
bool sum3(unsigned int T, unsigned int nums[3]) {
    if(T<3) return false;
    nums[0] = nums[1] = nums[2] = 1;
    unsigned int sum = 3;
    while(true){
        for(int i=1; i<=T; i++)
            for(int j=1; j<=i-1; j++){
                unsigned int k = T-i-j;
                if(i+j+k==T){
                    nums[0] = i;
                    nums[1] = j;
                    nums[2] = k;
                    return true;
                }
            }
    }
}

/// TESTS ///
#include <gtest/gtest.h>

void compareSums(unsigned int selected[3], unsigned int expectedSum) {
    EXPECT_EQ(selected[0] + selected[1] + selected[2], expectedSum);
}

TEST(TP2_Ex1, 3sumExists) {
    unsigned int selected[3];

    unsigned int T = 10;
    EXPECT_EQ(sum3(T,selected), true);
    compareSums(selected,T);

    T = 18;
    EXPECT_EQ(sum3(T,selected), true);
    compareSums(selected,T);
}

TEST(TP2_Ex1, 3sumNotExists) {
    unsigned int selected[3];

    unsigned int T = 1;
    EXPECT_EQ(sum3(T,selected), false);
}