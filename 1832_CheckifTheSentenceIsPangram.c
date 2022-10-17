/*1832. Check if the Sentence Is Pangram - leetcode
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.


Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false

SOLUTION: C++: at least one of very letter should appear should mean the length of sentence should be at least 26, if we can delete repeatable char in
a sentence then its length should be 26 -> using unordered_set <char> u_s to store sentence if the u_s.size() ==26 return true else return false
. The problem is in C: C does not have unordered_set, so we can make and array[26] and traverse -sentence- whenever we meet the char we count it, if it is == 1 res++ finally if res =26 return true else return false

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h> // for bool from C99
bool checkIfPangram(char* sentence){

    int res = 0;
    int ans[26] = {0}; // c

    for(int i = 0; i < strlen(sentence); ++i) {
       
        //printf("%c", sentence[i] );
        
        ans[sentence[i] - 'a']++;
        if(ans[sentence[i] - 'a'] == 1) { // if the chars in sentence can be repeatable, so we only need to count it 1 time
        //printf("%c", sentence[i] );
            res++;
        }
    }
    //printf("res = %d ", res);
    return res == 26;

}

int main(){

    char* first_sentence = "thequickbrownfoxjumpsoverthelazydoghhff";
    bool first_pangram = checkIfPangram(first_sentence);
    printf("the given sentence is %s pangram.\n", first_pangram ? "true" : "false" );
    
    char* sec_sentence = "leetcode";
    bool sec_pangram = checkIfPangram(sec_sentence);
    printf("the given sentence is %s pangram.\n", sec_pangram ? "true" : "false" );

    return 0;
}