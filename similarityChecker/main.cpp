#include "gmock/gmock.h"
#include "similarity_checker.cpp"

//class SimilarityCheckerFixture : public testing::Test {
//public:
//    
//};
//
//TEST_F(SimilarityCheckerFixture, numOfLetters) {
//    EXPECT_EQ(60, 60);
//}
//
//TEST_F(SimilarityCheckerFixture, letterMatch) {
//    EXPECT_EQ(40, 40);
//}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}