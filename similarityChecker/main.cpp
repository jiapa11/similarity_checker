#include "gmock/gmock.h"
#include "similarity_checker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
    SimilarityChecker checker;

    void checkLengthSimilarity(int expectedScore, const std::string& str1, const std::string& str2) {
        int actual = checker.getLengthScore(str1, str2);
        EXPECT_EQ(expectedScore, actual);
    }

    void checkAlphabetSimilarity(int expectedScore, const std::string& str1, const std::string& str2) {
        int actual = checker.getAlphabetScore(str1, str2);
        EXPECT_EQ(expectedScore, actual);
    }

    void checkStringSimilarity(int expectedScore, const std::string& str1, const std::string& str2) {
        int actual = checker.getScore(str1, str2);
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

TEST_F(SimilarityCheckerFixture, alpha_exactmatch) {
    checkAlphabetSimilarity(SimilarityChecker::MAX_ALPHABET_SCORE, "ABC", "ABC");
    checkAlphabetSimilarity(SimilarityChecker::MAX_ALPHABET_SCORE, "XYZE", "XYZE");
}

TEST_F(SimilarityCheckerFixture, alpha_zeromatch) {
    checkAlphabetSimilarity(0, "XYZ", "ABC");
    checkAlphabetSimilarity(0, "NNNAS", "POWYE");
}

TEST_F(SimilarityCheckerFixture, alpha_lowercase) {
    checkAlphabetSimilarity(0, "abc", "ABC");
    checkAlphabetSimilarity(26, "AbC", "ABC");
}

TEST_F(SimilarityCheckerFixture, alpha_normal) {
    checkAlphabetSimilarity(20, "XYA", "ZXY");
    checkAlphabetSimilarity(24, "ABCDE", "ABC");
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}