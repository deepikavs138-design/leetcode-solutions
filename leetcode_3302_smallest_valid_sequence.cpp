#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // last[j] stores the largest index in word1 from which 
        // the suffix word2[j...m-1] can be matched exact subsequence-wise.
        vector<int> last(m + 1, -1);
        last[m] = n; // Base case: empty suffix can start at index n

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;
        bool changed = false;
        j = 0; // Pointer for word2

        for (int i = 0; i < n && j < m; i++) {
            // Case 1: Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } 
            // Case 2: Character mismatch, but we can change word1[i] to word2[j]
            // We verify if word2[j+1...] can be matched in word1[i+1...]
            else if (!changed && last[j + 1] > i) {
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        if (ans.size() == m) {
            return ans;
        }
        return {};
    }
};
