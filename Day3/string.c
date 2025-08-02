#include<stdio.h>
#include"string.h"
int main()
{
    int choice;
    char str1[100], str2[100], ch;

    int found;
    while (1)
    {
        printf("<----------Menu Of String Functions---------->\n");
        printf("1.for Finding the length of string\n");
        printf("2.for compare two strings\n");
        printf("3.for copy one string to another\n");
        printf("4.for concatenate two strings\n");
        printf("5.for find the character in string\n");
        printf("6.for strstr function\n");
        printf("7.for reverse a String\n");
        printf("8.for check palindrome\n");
        printf("9.for exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the string: \n");
            scanf("%s", str1);
            printf("length of string is:%d\n", str_len(str1));
            break;
        case 2:
            printf("Enter the first string: \n");
            scanf("%s", str1);
            printf("Enter the second String: \n");
            scanf("%s", str2);
            printf("compare result is:%d\n", str_cmp(str1, str2));
            break;
        case 3:
            printf("Enter the first string: \n");
            scanf("%s", str1);
            printf("Enter the second String: \n");
            scanf("%s", str2);
            str_cpy(str1, str2);
            printf("Your Copy New String is : %s\n", str1);
            break;
        case 4:
            printf("Enter the first string: \n");
            scanf("%s", str1);
            printf("Enter the Second String: \n");
            scanf("%s", str2);
            str_cat(str1, str2);
            printf("Your Conctination String is : %s\n", str1);
            break;
        case 5:
            printf("Enter the string: \n");
            scanf("%s", str1);
            printf("Enter the character: \n");
            scanf(" %c", &ch);
            found = str_chr(str1, ch);
            if (found != -1)
            {
                printf("character found at position %d\n", found);
            }
            else
            {
                printf("character not found\n");
            }
            break;
        case 6:
            printf("Enter the first string\n");
            scanf("%s", str1);
            printf("Enter the second string\n");
            scanf("%s", str2);
            int pos = str_str(str1, str2);
            if (pos != -1)
            {
                printf("The string %s is found at position %d\n", str2, pos);
            }
            else
            {
                printf("The string %s is not found\n", str2);
            }
            break;
        case 7:
            printf("Enter the string: \n");
            scanf("%s", str1);
            printf("Your Reversed String is %s\n", reverse(str1));
            break;

        case 8:
            printf("Enter the string: \n");
            scanf("%s", str1);
            int plaindrome = is_palindrome(str1);
            if (plaindrome == 1)
            {
                printf("The string %s is a palindrome\n", str1);
            }
            else
            {
                printf("The string %s is not a palindrome\n", str1);
            }
            break;

        case 9:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}