#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class SimilarityChecker {
public:
    static const int MAX_LENGTH_SCORE = 60;

    SimilarityChecker() = default;
    
    int getLengthScore(const std::string& str1, const std::string& str2) {
        if (str1 == str2) return MAX_LENGTH_SCORE;
        if (hasEmptyString(str1, str2)) return 0;
        
        size_t length_longer = str1.length();
        size_t length_shorter = str2.length();
        if (length_shorter > length_longer) std::swap(length_longer, length_shorter);

        if (isLengthDiffMoreThanDouble(length_longer, length_shorter)) return 0;

        return getPartialLengthScore(length_shorter, length_longer);
    }

private: 
    const std::string EMPTY_STRING = "";

    bool hasEmptyString(const std::string& str1, const std::string& str2)
    {
        return (str1 == EMPTY_STRING || str2 == EMPTY_STRING);
    }

    bool isLengthDiffMoreThanDouble(size_t length_longer, size_t length_shorter)
    {
        return (length_longer / length_shorter) >= 2;
    }

    double getPartialLengthScore(size_t length_shorter, size_t length_longer)
    {
        double shorter = static_cast<double>(length_shorter);
        double longer = static_cast<double>(length_longer);
        return ((shorter * 2 - longer) / shorter) * MAX_LENGTH_SCORE;
    }
};