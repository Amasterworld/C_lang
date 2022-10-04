#include<stdio.h>

//after each iteration the int increase by 10 hence we have ans  = 10* ans + convert
double atoi(const char * str){
    
    double ans = 0;
    int i = 0;
    int sign = 1; // input string number is positive
    /*if input string is negative number then*/
    if (str[0] == '-'){
        sign = -1;
        ++i;
    }
    for(; str[i] >= '0' && str[i] <= '9'; ++i){ // for example s[] =="2351" -> ans = 10* ans + s[0]-'0' -> ans = 10*0 + 2 =2 then i++; ans  = 10x2 + 3 = 23;
        ans = 10 * ans + str[i] - '0';
    }
    return sign*ans;
 }

int main (){

    char str[] = "2351.23";
    double conver = atoi(str);
    printf("%d \n", conver);

    return 0;
}