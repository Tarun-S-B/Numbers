#include<stdio.h>
#include<stdlib.h>
#include<string.h>


long long int string_to_num(char str[20])
{
    long long int num = 0;
    int len = strlen(str) - 1;
    for(int i = len; i>=0; i--)
        num = num * 10 + (str[i] - 48);

    return num;
}


int * string_to_array(char str[])
{
    int n = strlen(str);
    int *a = (int *) malloc (sizeof(int) * n);

    for(int i=0; str[i]; i++)
        a[i] = str[i] - 48;

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


