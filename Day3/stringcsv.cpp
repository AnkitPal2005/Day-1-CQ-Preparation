#include<iostream>
using namespace std;

void tokinizer(char*str1){
    int i=0;
    int s=0;
    while(true){
        if(str1[i]==','||str1[i]=='\0'){
            cout<<"[";
        
        for(int j=s;j<i;j++){
            cout<<str1[j]<<" ";
        }
        cout<<"]"<<endl;
        if(str1[i]=='\0'){
            break;
        }
        s=i+1;
    }
    i++;
}
}
int main(){
char str1[100];
cout<<"Enter the string";
cin>>str1;
tokinizer(str1);
return 0;
}