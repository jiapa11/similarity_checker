#include "gmock/gmock.h"
#include "similarity_checker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
    SimilarityChecker checker{ "ABC" };

    void checkLengthSimilarity(int expectedScore, const std::string& target) {
        int actual = checker.getLengthScore(target);
        EXPECT_EQ(expectedScore, actual);
    }

};

TEST_F(SimilarityCheckerFixture, length) {
    checkLengthSimilarity(SimilarityChecker::MAX_LENGTH_SCORE, "ABC");
    checkLengthSimilarity(0, "ABCABCA");
    checkLengthSimilarity(40, "DEFE");
    checkLengthSimilarity(0, "A");
    checkLengthSimilarity(20, "ZZZXE");
    checkLengthSimilarity(0, "");
}

//TEST_F(SimilarityCheckerFixture, letterMatch) {
//    EXPECT_EQ(40, 40);
//}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}