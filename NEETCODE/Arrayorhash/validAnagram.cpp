// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
//An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// brute force approach O(nlogn + mlogm)
class Solution {
public:
    bool isAnagram(string s, string t) {
     if(s.length()!= t.length()) return false;

     sort(s.begin() , s.end());
     sort(t.begin(), t.end());

     return s == t;   
    }
};

// optimal hashing approach O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char,int> count;
        
        for(int i=0; i<s.length(); i++) count[s[i]]++;
        for(int i=0; i<t.length(); i++) count[t[i]]--;
        
        for(auto x : count){
            if(x.second != 0) return false;
        }
        return true;
    }
};


