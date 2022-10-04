/**
 * Exercise 2.4
 *
 * Let us write a version of squeeze(s1,s2) that deletes each
 * character in the string 1 that matches any character in the string s2
 * 
 * SOLUTION: make the hash table (unfortunately that hash table is not availbale in C) then count the frequency of char in s2, (in C++ can use bool , unordered_map<char, bool> u_m; because
 * we only need to know whether the char exists in s2. 
 *  after hving the hash table we traveser the s1, if (um[curr_char] == 0) (not exist in s2) then s1[j++]  = s[i]; and i++; else only increase  i++
 * 
 *   
 **/

#include <stdio.h>
#include <stdlib.h> // for calloc
#define NUM_CHAR 256 // we have maximum 256 char in ASCII

int* countCharMask(const char* mask ){ // in C++ u_m[mask[i]++; or u_m[mask[i] =1; ]

    int* count = (int*)calloc(sizeof(int), NUM_CHAR);
    for(int i = 0; mask[i] != '\0'; ++i){
        count[mask[i]]++;
    }
    return count;
}

char* remCharInMask(char* target, const char* mask){

    // put the char in mask to the hash table
    int * charInMask = countCharMask(mask);
    
    int idx1 = 0, idx2 = 0;
    /*traveser string target */
    while (target[idx1] != '\0'){
        
        char curr_char = target[idx1];
        /*if the curr_char does not present in mask, --> count[curr_char] == 0*/
        if(charInMask[curr_char] == 0){
            target[idx2] = target[idx1];
            idx2++;
        }
        idx1++;
    }
    target[idx1] = '\0';
    return target;

}

int main(){

    char target[] = "Light in the ground";
    char mask[] = "i";
    //char* result = remCharInMask(target, mask);
    printf("%s \n", remCharInMask(target, mask));
    return 0;
}