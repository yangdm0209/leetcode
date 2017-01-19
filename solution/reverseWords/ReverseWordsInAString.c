// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : daming
// Date   : 2017-01-19

/*************************************************************************************** 
 *
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 * 
 * click to show clarification.
 * 
 * Clarification:
 * 
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 * 
 ***************************************************************************************/

void reverseWords(char *s) {
    int len = strlen(s);
    char* tmp = (char*)malloc(len);
    char* dest = tmp + len;
    int i = 0;
    int wordLen = 0;
    for (i = 0; i < len; i++) {
        if (s[i] != ' ') {
            wordLen++;
        }
        else if (wordLen > 0) {
            dest -= (wordLen+1);
            memcpy(dest + 1, s + i - wordLen, wordLen);
            wordLen = 0;
            *dest = s[i];
        }
    }

    dest -= wordLen;
    memcpy(dest, s + i - wordLen, wordLen);
    while (*dest == ' ') dest++;
    memset(s, 0, len);
    memcpy(s, dest, len - (dest - tmp));
    free(tmp);
}
