#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>  
#include <algorithm> 

using namespace std;

int findMissingElement(vector<int>& arr) {

    int d = arr[1]-arr[0];
    int temp = arr[0];
    for(int i = 1; i < arr.size(); i++) {
      temp += d;
        if(temp != arr[i]){
          return temp;
        }
    }
    return -1; 
}

int main(int argc, char* argv[]) {

    ifstream file("file1.txt");
    if (!file) {
        cout << "Error opening input file!" << endl;
        exit(1);
    }

    vector<int> nums;
    int num;
    
    while (file >> num) {
        nums.push_back(num);
    }
    file.close(); 

    if (nums.size() < 2) {
        cout << "The series is too short to find a missing element." << endl;
        exit(1);
    }

    
    sort(nums.begin(), nums.end());

    
    int a = findMissingElement(nums);
    if (a == -1) {
        cout << "No missing element found in the series." << endl;
        exit(1);
    }

    // Open the output file
    ofstream files("file2.txt");
    if (!files) {
        cout << "Error opening output file!" << endl;
        exit(1);
    }

    files << "The missing element in the series is: " << a << endl;
    files.close();  

    cout << "Missing element found: " << a << endl;

    return 0;
}
