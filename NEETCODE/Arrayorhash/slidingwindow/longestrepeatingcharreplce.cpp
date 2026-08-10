// brute force 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            int freq[26] = {0};
            int maxFreq = 0;
            
            for(int j = i; j < s.size(); j++){
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                
                int windowSize = j - i + 1;
                if(windowSize - maxFreq <= k){
                    maxLen = max(maxLen, windowSize);
                }
            }
        }
        return maxLen;
    }
};

/*
Take s = "AAABABB", k = 1

i = 0 (start at 'A'):

j=0, char='A', freq[A]=1, maxFreq=1, windowSize=1, 1-1=0 ≤ 1 ✅ maxLen=1

j=1, char='A', freq[A]=2, maxFreq=2, windowSize=2, 2-2=0 ≤ 1 ✅ maxLen=2

j=2, char='A', freq[A]=3, maxFreq=3, windowSize=3, 3-3=0 ≤ 1 ✅ maxLen=3

j=3, char='B', freq[B]=1, maxFreq=3, windowSize=4, 4-3=1 ≤ 1 ✅ maxLen=4

j=4, char='A', freq[A]=4, maxFreq=4, windowSize=5, 5-4=1 ≤ 1 ✅ maxLen=5

j=5, char='B', freq[B]=2, maxFreq=4, windowSize=6, 6-4=2 > 1 ❌ invalid

j=6, char='B', freq[B]=3, maxFreq=4, windowSize=7, 7-4=3 > 1 ❌ invalid

i = 1 (start at second 'A'):

Windows from here will be smaller than 5 so maxLen stays 5.

Same for all remaining starting points.

Final answer = 5 */

// optimal solution 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        
        for(int right = 0; right < s.size(); right++){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
            int windowSize = right - left + 1;
            if(windowSize - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};