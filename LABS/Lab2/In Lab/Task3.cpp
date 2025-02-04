#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout<< argv[0] << endl;
        return 1;
    }

    vector<int> nums;

    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }

    sort(nums.begin(), nums.end());

    cout << "Sorted integers: ";
    
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
