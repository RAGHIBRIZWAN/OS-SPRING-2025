#include<iostream>
#include<vector>
#include<cstdlib> 
using namespace std;

int main(int argc, char* argv[]){
  if(argc < 2){
    cout<<"Not a series!"<<endl;
  }
  
  vector<int> nums;
  for(int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
  
  int a = nums[0];
  int temp = nums[1] - nums[0];
  
  for(int i = 1; i < nums.size(); i++){
    a += temp;
    if(a != nums[i]){
      cout<<"Missing value is: "<<a;
      break;
    }
  }
  return 0;
}
