    #include<stdio.h>   
    int* Bubble_Sort(int[], int arr);  
    int main ()    
    {    
        int arr[10] = { 10, 9, 7, 101, 102, 44, 12, 78, 34, 23};
        int arr_size = sizeof(arr)/sizeof(arr[0]);     
        int *p = Bubble_Sort(arr, arr_size);  
        printf("printing sorted elements ...\n");  
        for(int i=0;i<10;i++)  
        {  
            printf("%d\n", *(p+i));  
        }  
    }    
    int* Bubble_Sort(int a[], int arr_size) //array a[] points to arr.   
    {  
         
        for(int i = 0; i<arr_size; i++)    
        {    
            for(int j = i+1; j<arr_size; j++)    
            {    
                if(a[j] < a[i])    
                {    
                    int temp = a[i];    
                    a[i] = a[j];    
                    a[j] = temp;     
                }     
            }     
        }     
        return a;  
    }  