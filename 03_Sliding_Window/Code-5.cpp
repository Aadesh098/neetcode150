// Minimum Window Substring 
// https://leetcode.com/problems/minimum-window-substring/description/

string minWindow(string s, string t) {
        unordered_map<char, int> check;
        for (int i = 0; i < t.size(); i++) {
            check[t[i]]++;
        }        
        int i = 0;
        int j = 0;
        int counter = t.size();        
        int minStart = 0;
        int minLength = INT_MAX;
        while (j < s.size()){
            if (check[s[j]] > 0) {
                counter--;
            }
            check[s[j]]--;
            j++;
            while (counter == 0) {
                if (j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }
                check[s[i]]++;
                if (check[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }        
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }