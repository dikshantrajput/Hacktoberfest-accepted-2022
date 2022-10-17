// Problem Statement
//Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of all the given words exactly once without any overlapping of words.
//It is given that all words are of the same length
/*
Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat"
*/
// My code

#include <bits/stdc++.h>
using namespace std;

 vector<int> findSubstring(string s, vector<string>words) {
        unordered_map<string,int>word_mp;
        vector<int>res;
        int wordcount=words.size();
        int wordlen=words[0].size();//because every word is of same length
        if(s.size()<wordlen*wordcount) return {};
        for(auto str:words){
            word_mp[str]++;
        }
        //size of final concatenated string = wordlen*wordcount
        for(int i=0;i<=s.size()-wordlen*wordcount;i++){
            unordered_map<string,int>seen;
            for(int j=0;j<wordcount;j++){
                //this is our window basically which will only goes upto the size of count of words
                //becuse we will jump from words to words inside this
                //extract the index of word
                int wordpos=i+j*wordlen;
                string word=s.substr(wordpos,wordlen);
                //if it is not present in the word map then just break the loop
                if(word_mp.find(word)==word_mp.end()) break;
                else
                seen[word]++;
                // no need to process further if the word has higher frequency than required
                 if (seen[word] > word_mp[word]) {
                break;
        } 
                //else if you have vistited all the words then you have a result index
                if(j+1==wordcount)
                res.push_back(i);
            }
        }
        return res;
    }
int main()
{
    vector<int> result =
   findSubstring("abcdefabc",{"abc", "def"});
  for (auto num : result) {
    cout << num << " ";
  }
}
/*
Algorithm:
-Keep the frequency of every word in a HashMap.
-Starting from every index in the string, try to match all the words,but keep one thing in mind we only have to iterate up until (string len-concatneation).
-In each iteration, in the inner loop keep track of all the words that we have already seen in another HashMap,inner loop will basically be our window
-If a word is not found or has a higher frequency than required, we can move on to the next character in the string.
-Store the index if we have found all the words.
Time Complexity --> O(N∗M∗Len) 
N is the number of characters in the given string
M is the total number of words 
Len is the length of a word
Space Complexity --> O(M+N)
*/