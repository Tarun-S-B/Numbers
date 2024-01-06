#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//INPUT: takes an array of characters of size 20 (including NULL character)
//OUTPUT: returns a long long int which is formed from the input string
long long int string_to_num(char str[20])
{
    long long int num = 0;
    long long int rem = 0;
    int len = strlen(str);

    if(len>20)
    {
        printf("Invalid Input (size exceeded)\n");
        return 0;
    }

    for(int i = 0; i<len; i++)
    {
       
        rem = str[i] - 48;
        if(rem>9 || rem<0)
        {
            printf("Invalid string (not a integer string)\n");
            return 0;
        }
        num = (long long int)(num * (long long int)10) + rem;
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


//INPUT: takes a number as input
//OUTPUT: returns the no of digits in the base 10 format of the given input
int get_digits(long long int n)
{
    return (int)log10(n) + 1;   
}


int * num_to_array(int n)
{
    int rem;
    int size = get_digits(n);
    int i = size - 1;
    int *a = (int *) malloc (sizeof(int) * size);
    while(n)
    {
        rem = n % 10;
        a[i] = rem;
        n /= 10;
        i--;
    }
    return a;
}


void display_array(int *a, int n)
{
    for(int i=0; i<n; i++)
        printf("%d",a[i]);
}

void give_choices()
{
    printf("1. String -> long long integers\n");
    printf("2. String -> array of integers\n");
    printf("3. Number -> Array of Integers\n");
    printf("4. Display Menu\n");
}


int main()
{
    int ch = 10;
    char str[100];
    long long int num = 0;
    int * num_array;
    int size;

    give_choices();
    while(ch)
    {
        printf("\nEnter Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("Enter string (digits <= 19): ");
                    scanf("%s",str); 
                    num = string_to_num(str);
                    printf("Long Long Int = %llu\n",num);
                    break;

            case 2: printf("Enter string: ");
                    scanf("%s",str);
                    num_array = string_to_array(str);
                    size = strlen(str);
                    printf("Intger Array: ");
                    display_array(num_array,size);
                    break;       

            case 3: printf("Enter number: ");
                    scanf("%llu",&num);
                    num_array = num_to_array(num);
                    size = get_digits(num);
                    display_array(num_array, size);
                    break;

            case 4: give_choices();
                    break;

            default:exit(0); 
        }
    }    
    return 0;
}


