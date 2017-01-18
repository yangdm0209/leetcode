// Source : https://leetcode.com/problems/longest-absolute-file-path/
// Author : daming
// Date   : 2017-01-18

/*************************************************************************************** 
 *
 * Suppose we abstract our file system by a string in the following manner:
 * 
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 * 
 * dir
 *     subdir1
 *     subdir2
 *         file.ext
 * 
 * The directory dir contains an empty sub-directory subdir1 and a sub-directory 
 * subdir2 containing a file file.ext.
 * 
 * The string 
 * "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile
 * 2.ext" represents:
 * 
 * dir
 *     subdir1
 *         file1.ext
 *         subsubdir1
 *     subdir2
 *         subsubdir2
 *             file2.ext
 * 
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains 
 * a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 
 * contains a second-level sub-directory subsubdir2 containing a file file2.ext.
 * 
 * We are interested in finding the longest (number of characters) absolute path to a 
 * file within our file system. For example, in the second example above, the longest 
 * absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not 
 * including the double quotes).
 * 
 * Given a string representing the file system in the above format, return the length 
 * of the longest absolute path to file in the abstracted file system. If there is no 
 * file in the system, return 0.
 * 
 * Note:
 * 
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 * 
 * Time complexity required: O(n) where n is the size of the input string.
 * 
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another 
 * path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 ***************************************************************************************/

int lengthLongestPath(char* input) {
    char* p = input;
    int deps[255] = { 0 };
    int maxLen = 0;
    int tabs = 0;
    bool isFile = false;
    char* nameHead = input;
    bool newDir = false;

    while (*p++ != '\0') {
        if (*p == '.') isFile = true;
        else if (*p == '\t') tabs++;
        else if (*p == '\n') {
            deps[tabs] = p - nameHead;
            if (tabs > 0) deps[tabs] += (deps[tabs - 1] + 1);
            if (isFile && deps[tabs] > maxLen) maxLen = deps[tabs];
            tabs = 0;
            isFile = false;
            newDir = true;
        }
        else if (newDir) {
            nameHead = p;
            newDir = false;
        }
    }
    if (isFile) {
        deps[tabs] = p -1 - nameHead;
        if (tabs > 0) deps[tabs] += (deps[tabs - 1] + 1);
        if (deps[tabs] > maxLen) maxLen = deps[tabs];
    }
    return maxLen;
}
