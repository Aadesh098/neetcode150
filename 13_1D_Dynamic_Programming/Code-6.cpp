// Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/description/

void middleOut(string s, int i, int j, int& result) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            result++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            middleOut(s, i, i, result);
            middleOut(s, i, i + 1, result);
        }
        return result;
    }