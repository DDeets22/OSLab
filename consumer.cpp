//this is the producer protion of the code
//written by dakota deets

#include <iostream>
#include <fstream> //the shared memory will be in this file (along with the semaphor)

int main(){
//overwrite any existing data or create new
std::fstream myFile;
std::string line;

int state = 0;
int i = 0;
while(i <= 99){
std::cout << "im the consumer, i = " << i << std::endl;
    switch(state){
	case 0: //waiting
	myFile.open("table.txt");
	if(myFile.peek() != std::ifstream::traits_type::eof()){
	state = 1;
	}
	myFile.close();
	break;
	case 1: //consuming
	myFile.open("table.txt");
	while(getline(myFile, line)){
	    std::cout << "line: " << line << std::endl;
	    i++;
	}
	std::ofstream f("table.txt");//this should over write the file
	f.close();
	myFile.close();
	state = 0;
	break;
    }
}


myFile.close();
return 0;

}

