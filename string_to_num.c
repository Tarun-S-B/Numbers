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

int main()
{
    char str[20];
    printf("Enter the string of numbers (No of digits<=19)");
    scanf("%s",str);

    long long int num = string_to_num(str);
    printf("IN MAIN\n");
    printf("long long int = %llu",num);

}


