#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("output.txt");
  if(!file.is_open()){
    cerr << "Unable to open file";
    return 1;
  }
  else{
    cout<<"File Open successfuly";
  }
  char word[100];
  int count=0;
  while(file >> word){
    count++;
  }
  file.close();
  cout << "Total number of word in file is : " << count << endl;
  return 0;

}
