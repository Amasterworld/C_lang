#include<stdio.h>
 
 #define  MAXSIZE 10
 #define SIZE(x)  sizeof(x)/ sizeof(x[0]) // to calculate the sizeof array in C

int get_length(char line[], int lim);

void copy_str(char to[], char from[]);

int main(){
    
    char lines[MAXSIZE];
    char longest_line[MAXSIZE];
    int max = 0;
    int len = 0;

    while((len = get_length(lines, MAXSIZE)) >=1){ // >=1 because event with the empty string  the enter to make a newline also count+1
        printf("len = %d \n", len);
        if(len > max){
            max = len;
            copy_str(longest_line, lines);
        }

    }

    if(max > 0){/*when max  > 0 that means at least a line is input and get*/
        printf("The longest line is %s", longest_line);
    }
    else{
        printf("the input is empty string");
    }
    return 0;
}

int get_length(char line[], int lim){  // the array line after passing as an argument decayed into pointer, it is not an array anymore, so cannot use SIZE(macro above) to measure its size anymore
    int ans = 0, c;
    
    
    
    for(int i = 0; i < MAXSIZE-1; ++i){
        c = getchar();
        if(c != EOF && c !='\n'){
            line[i] = c;
            ++ans;
        }  
        else{
            break;
        }
    }
    
    if(c == '\n'){
        printf("ans = %d \n", ans);
        line[ans] = '\n';
        ++ans;
    }
        
    line[ans] ='\0';
    printf("ans after = %d ", ans);
    return (ans-1);
}
void copy_str(char to[], char from[]){
    /*we  can use do while loop to make it implicit*/
    int i = 0;
    while((to[i] = from[i]) != 0 ){
        ++i;
    }
}