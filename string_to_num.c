#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//INPUT: takes an array of characters of size 20 (including NULL character)
//OUTPUT: returns a long long int which is formed from the input string
long long int string_to_num(char str[20])
{
    long long int num = 0;
    int rem;
    int len = strlen(str) - 1;
    for(int i = len; i>=0; i--)
    {
        rem = str[i] - 48;
        if(rem>=9 || rem<=0)
        {
            printf("Invalid string\n");
            return 0;
        }
        num = num * 10 + rem;
    }

    return num;
}


//INPUT: takes an string of numbers of any size
//OUTPUT: the address of integer array containing the digits of string
int * string_to_array(char str[])
{
    int n = strlen(str);
    int x;
    int *a = (int *) malloc (sizeof(int) * n);

    for(int i=0; str[i]; i++)
    {
        x = str[i] - 48;
        if(x>=9 || x<=0)
        {
            printf("Invalid input\n");
            return NULL;
        }
        a[i] = x;
    }

    return a;
}



int main()
{
    // char str[20];
    // printf("Enter the string of numbers (No of digits<=19)");
    // scanf("%s",str);

    // long long int num = string_to_num(str);
    // printf("IN MAIN\n");
    // printf("long long int = %llu",num);

    char str[200];
    printf("Enter a string of numbers: ");
    scanf("%s",str);

    int *num_array = string_to_array(str);
    int n = strlen(str);

    for(int i=0; i<n; i++)
        printf("%d ",num_array[i]);
    

}


