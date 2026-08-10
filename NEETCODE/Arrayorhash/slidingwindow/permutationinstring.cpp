class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        int freq1[26] = {0};
        int freq2[26] = {0};
        int matches = 0;
        
        
        for(int i = 0; i < s1.size(); i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
   
        for(int i = 0; i < 26; i++){
            if(freq1[i] == freq2[i]) matches++;
        }

        for(int i = s1.size(); i < s2.size(); i++){
            if(matches == 26) return true;
       
            int right = s2[i] - 'a';
            freq2[right]++;
            if(freq2[right] == freq1[right]) matches++;
            else if(freq2[right] == freq1[right] + 1) matches--;
            
            int left = s2[i - s1.size()] - 'a';
            freq2[left]--;
            if(freq2[left] == freq1[left]) matches++;
            else if(freq2[left] == freq1[left] - 1) matches--;
        }
        
        return matches == 26;
    }
};