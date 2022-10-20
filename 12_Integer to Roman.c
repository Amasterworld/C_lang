/*
12. Integer to Roman - leetcode

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*SOLUTION: in C++, we can use vector of pair to contain the pair of int and roman number (string ) like this (1000, "M"),
(900, "CM") (500, "D") (400, "CD") and so on, but in C language we do not have vector (only array) and we do not have std::pair neither string(in C it is an array of char) we can make them by ourself but it takes time, to use the same algorithm used for C++ we can use it directly.
*/

char * intToRoman(int num){

    char* s = (char*) malloc(sizeof(char)*20);
    memset (s, 0, sizeof(char)*20);
    int i = 0;
    
    while (num > 0) {
        if (num >= 1000) {
            s[i++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            s[i++] = 'C';
            s[i++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            s[i++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            s[i++] = 'C';
            s[i++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            s[i++] = 'C';
            num -= 100;
        }else if (num >= 90) {
            s[i++] = 'X';
            s[i++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            s[i++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            s[i++] = 'X';
            s[i++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            s[i++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            s[i++] = 'I';
            s[i++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            s[i++] = 'V';
            num -= 5;
        } else if (num >= 4){
            s[i++] = 'I';
            s[i++] = 'V';
            num -= 4;
        } else if (num >= 1) {
            s[i++] = 'I';
            num -= 1;
        }
    }
    return s;
}

/* the same algorithm to solve this problem in C++, in C++, the code is really more compact 
class Solution {
public:
    string intToRoman(int num) {
        std::string ans;
        std::vector< pair<int, std::string>>  int_roman = { {1000,"M"}, {900,"CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
        
        for (auto it : int_roman){
            //std:cout<<it.first<<std::endl;
            while (num >= it.first){
                
                    ans += it.second;
                    num -= it.first;
                
            } 
        }
    
    return ans;
    }
};


*/
