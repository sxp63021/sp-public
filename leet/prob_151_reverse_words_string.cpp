/*
151. Reverse Words in a String
Level: Medium

Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single 
space in the reversed string.

Note:

    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed 
    string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in 
    the reversed string.

Follow up:
For C programmers, try to solve it in-place in O(1) extra space.

*/

    string reverseWords(string s) {
        string outputstr;
        
        int slen = s.length();
        
        if (slen == 0) return outputstr;
        
        size_t findpos = s.find(" ");
        size_t startpos = 0;
        
        while (findpos == startpos) { // space at the beginning has to be skipped
            startpos += 1;
            findpos = s.find(" ", startpos);
        }
        string filler;
        
        while ((findpos != string::npos)) {
              outputstr = s.substr(startpos, (findpos - startpos)) + filler + outputstr;
              filler = " ";
              // advance findpos until you don't see delimiter
              while((s.at(findpos) == ' ') && (findpos < s.length() - 1)) findpos++;
            
              if ((findpos + 1) == s.length()) {
                  findpos += 1;
                  break;
              }
              startpos = findpos;
              findpos = s.find(" ", startpos);
        }
        
        if (findpos != s.length()) {
            outputstr = s.substr(startpos, (slen - startpos)) + filler + outputstr;
        }
        
        return outputstr;
    }
