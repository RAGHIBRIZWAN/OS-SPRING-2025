#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
	  cout<<argv[0]<<endl;
	}
	
	ifstream file(argv[1]);
	if(!file){
	  cout<<"File could not open"<<endl;
	  return 1;
	}
	
	string readLine;
	while(getline(file,readLine)){
	  cout<<readLine<<endl;
	}
	file.close();
	return 0;
}
