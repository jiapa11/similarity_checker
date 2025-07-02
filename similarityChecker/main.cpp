#include "gmock/gmock.h"
#include "similarity_checker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
    SimilarityChecker checker;

    void checkLengthSimilarity(int expectedScore, const std::string& str1, const std::string& str2) {
        int actual = checker.getLengthScore(str1, str2);
        EXPECT_EQ(expectedScore, actual);
    }

};

TEST_F(SimilarityCheckerFixture, length) {
    checkLengthSimilarity(SimilarityChecker::MAX_LENGTH_SCORE, "ABC", "ABC");
    checkLengthSimilarity(0, "ABC", "ABCABCA");
    checkLengthSimilarity(40, "ABC", "DEFE");
    checkLengthSimilarity(0, "ABC", "A");
    checkLengthSimilarity(20, "ABC", "ZZZXE");
    checkLengthSimilarity(0, "ABC", "");
}

//TEST_F(SimilarityCheckerFixture, letterMatch) {
//    EXPECT_EQ(40, 40);
//}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}