#include<iostream>
#include<vector>
#include<cstdlib>  
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> nums;
    int sum = 0, avg = 0;
    for(int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }
    
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    
    if (argc > 1) {
        avg = sum / (argc - 1);  
    }
    cout << "Sum of Array: " << sum << endl;
    cout << "Average of Array: " << avg << endl;
    return 0;
}
