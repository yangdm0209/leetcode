// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : daming
// Date   : 2017-01-18

/*************************************************************************************** 
 *
 * Given a string, find the length of the longest substring without repeating 
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must 
 * be a substring, "pwke" is a subsequence and not a substring.
 * 
 ***************************************************************************************/

char* repeatIndex(char* head, char* tail){
    char* op = head;
    while (op != tail) {
        // repeat here
        if (*op == *tail) return op + 1;
        op++;
    }
    return head;
}
int lengthOfLongestSubstring(char* s) {
    char* head = s;
    char* tail = s;
    int maxSub = 0;
    while(*tail!='\0'){
        head=repeatIndex(head, tail);
        if (tail-head+1>maxSub) maxSub = tail-head+1;
        tail++;
    }
    
    return maxSub;
}
