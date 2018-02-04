#include <vector>
#include <iostream> // todo remove

std::vector<int> findLongestSubsequenceImpl(const std::vector<int>& sequence,
                                            const std::vector<int>& currentLongestSubsequence,
                                            std::vector<int>::const_iterator startPos);

std::vector<int> findLongestSubsequence(const std::vector<int>& sequence)
{
    return findLongestSubsequenceImpl(sequence, {}, sequence.cbegin());
}

std::vector<int> findLongestSubsequenceImpl(const std::vector<int>& sequence,
                                            const std::vector<int>& currentLongestSubsequence,
                                            std::vector<int>::const_iterator startPos)
{
    if (startPos == sequence.cend())
    {
        return currentLongestSubsequence;
    }

    if (currentLongestSubsequence.empty() || *startPos >= currentLongestSubsequence.back())
    {
        // Return larger of the two subsequences - one that contains *startPos and other that doesn't
        std::vector<int> nextLongestSubsequence(currentLongestSubsequence);
        nextLongestSubsequence.push_back(*startPos);
        std::vector<int> longestSubsequenceWith = findLongestSubsequenceImpl(sequence, nextLongestSubsequence,
                                                                             startPos + 1);

        nextLongestSubsequence.pop_back();
        std::vector<int> longestSubsequenceWithout = findLongestSubsequenceImpl(sequence, nextLongestSubsequence,
                                                                                startPos + 1);

        return longestSubsequenceWith.size() >= longestSubsequenceWithout.size() ? longestSubsequenceWith
                                                                                 : longestSubsequenceWithout;
    }
    else
    {
        return findLongestSubsequenceImpl(sequence, currentLongestSubsequence, startPos + 1);
    }
}

int main()
{
    using namespace std;
   //  std::vector<int> sequence = {5, 2, 8, 6, 3, 6, 9, 7};
    std::vector<int> sequence = {1, 5, 3, 9, 2, 4, 8, 5, 0, 7, 6, 2, 3};
    std::vector<int> longestSubsequence = findLongestSubsequence(sequence);
    for (int num : longestSubsequence)
        cout << num << ", ";
    cout << endl;

    return 0;
}