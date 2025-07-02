#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class SimilarityChecker {
public:
    static const int MAX_LENGTH_SCORE = 60;

    SimilarityChecker(const std::string& source) : original{ source } {};
    
    int getLengthScore(const std::string& target) {
        if (target == original) return MAX_LENGTH_SCORE;
        if (isTargetStringEmpty(target)) return 0;
        
        double length_longer = original.length();
        double length_shorter = target.length();
        if (length_shorter > length_longer) std::swap(length_longer, length_shorter);

        if (isLengthDiffMoreThanDouble(length_longer, length_shorter)) return 0;

        return getPartialLengthScore(length_shorter, length_longer);
    }

private: 
    const std::string original;
    const std::string EMPTY_TARGET = "";

    bool isTargetStringEmpty(const std::string& target)
    {
        return target == EMPTY_TARGET;
    }

    bool isLengthDiffMoreThanDouble(double length_longer, double length_shorter)
    {
        return (length_longer / length_shorter) >= 2;
    }

    double getPartialLengthScore(double length_shorter, double length_longer)
    {
        return ((length_shorter * 2 - length_longer) / length_shorter) * MAX_LENGTH_SCORE;
    }
};