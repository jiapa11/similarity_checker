#include <iostream>
#include <string>
#include <algorithm>

using std::string;

typedef int bitmap;

class SimilarityChecker {
public:
    static const int MAX_LENGTH_SCORE = 60;
    static const int MAX_ALPHABET_SCORE = 40;

    SimilarityChecker() = default;

    int getScore(const std::string& str1, const std::string& str2) {
        if (str1 == str2) return MAX_LENGTH_SCORE + MAX_ALPHABET_SCORE;
        if (hasEmptyString(str1, str2)) return 0;
        
        return getLengthScore(str1, str2) + getAlphabetScore(str1, str2);
    }

    int getLengthScore(const std::string& str1, const std::string& str2) {
        if (str1 == str2) return MAX_LENGTH_SCORE;
        if (hasEmptyString(str1, str2)) return 0;

        size_t length_longer = str1.length();
        size_t length_shorter = str2.length();
        if (length_shorter > length_longer) std::swap(length_longer, length_shorter);

        if (isLengthDiffMoreThanDouble(length_longer, length_shorter)) return 0;

        return getPartialLengthScore(length_shorter, length_longer);
    }

    int getAlphabetScore(const std::string& str1, const std::string& str2) {
        if (str1 == str2) return MAX_ALPHABET_SCORE;
        if (hasEmptyString(str1, str2)) return 0;

        int totalCnt = getTotalAlphabetCount(str1, str2);
        int sameCnt = getSameAlphabetCount(str1, str2);

        if (totalCnt == 0 || sameCnt == 0) return 0;

        return getPartialAlphabetScore(totalCnt, sameCnt);
    }


private:
    const std::string EMPTY_STRING = "";
    static const int NUM_OF_ALPHABET = 30; // 26 + @

    bool hasEmptyString(const std::string& str1, const std::string& str2)
    {
        return (str1 == EMPTY_STRING || str2 == EMPTY_STRING);
    }

    bool isLengthDiffMoreThanDouble(size_t length_longer, size_t length_shorter)
    {
        return (length_longer / length_shorter) >= 2;
    }

    int getPartialLengthScore(size_t length_shorter, size_t length_longer)
    {
        double shorter = static_cast<double>(length_shorter);
        double longer = static_cast<double>(length_longer);
        double score = ((shorter * 2 - longer) / shorter) * MAX_LENGTH_SCORE;

        return static_cast<int>(score);
    }

    int getPartialAlphabetScore(int totalCnt, int sameCnt)
    {
        double percentage = static_cast<double>(sameCnt) / static_cast<double>(totalCnt);
        double score = static_cast<double>(MAX_ALPHABET_SCORE) * percentage;

        return static_cast<int>(score);
    }

    int getTotalAlphabetCount(const std::string& str1, const std::string& str2) {
        bool alphabetInString[NUM_OF_ALPHABET] = { false };
        int count = 0;

        for (const char& ch : str1) {
            if (ch >= 'A' && ch <= 'Z') {
                if (alphabetInString[ch - 'A'] == true) continue;
                alphabetInString[ch - 'A'] = true;
                count++;
            }
        }

        for (const char& ch : str2) {
            if (ch >= 'A' && ch <= 'Z') {
                if (alphabetInString[ch - 'A'] == true) continue;
                count++;
            }
        }

        return count;
    }

    int getSameAlphabetCount(const std::string& str1, const std::string& str2) {
        bool alphabetInString[NUM_OF_ALPHABET] = { false };
        int count = 0;

        for (const char& ch : str1) {
            if (ch >= 'A' && ch <= 'Z') {
                if (alphabetInString[ch - 'A'] == true) continue;
                alphabetInString[ch - 'A'] = true;
            }
        }

        for (const char& ch : str2) {
            if (ch >= 'A' && ch <= 'Z') {
                if (alphabetInString[ch - 'A'] == true) {
                    count++;
                }
            }
        }

        return count;
    }
};