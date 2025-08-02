#include <stdio.h>
int str_len(char*str1){
    int length=0;
    int i=0;
    while(str1[i]!='\0'){
        length++;
        i++;
    }
    return length;
}
int str_cmp(char*str1,char*str2){
    int i=0;
    while(str1[i]!='\0'&&str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            return str1[i]-str2[i];
        }
        i++;
    }
    return str1[i]-str2[i];
}
void str_cpy(char*str1,char*str2){
    int i=0;
    while(str2[i]!='\0'){
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
}
void str_cat(char*str1,char*str2){
    int i=0;
    int j=0;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i]='\0';
}
int str_chr(char*str1,char ch){
    int i=0;
    while(str1[i]!='\0'){
        if(str1[i]==ch){
            return i;
        }
        i++;
    }
    return -1;
}
int str_str(char*str1,char*str2){
    int i;
    int j;
    for(i=0;str1[i]!='\0';i++){
        for(j=0;str2[j]!='\0';j++){
            if(str1[i+j]!=str2[j]){
            break;
        }
    }
    if (str2[j] == '\0')
    {
        return i;
    }
}
return -1;
}
char*reverse(char*str1){
    int length=str_len(str1);
    for(int i=0;i<length/2;i++){
        char temp=str1[i];
        str1[i]=str1[length-i-1];
        str1[length-i-1]=temp;
    }
    return str1;
}
int is_palindrome(char*str1){
   char arr[100];
   str_cpy(arr,str1);
   reverse(arr);
   if(str_cmp(arr,str1)==0){
    return 1;
   }
    return -1;
}
