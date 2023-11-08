//this is the producer protion of the code
//written by dakota deets

#include <iostream>
#include <fstream> //the shared memory will be in this file (along with the semaphor)
#include <string>





int main(){
//overwrite any existing data or create new

int state=1;
int i = 0;
int sem = 0;
std::fstream myFile;


while(i < 99){
std::cout << "im the producer, i = " << i << std::endl;
    switch(state){
        case 0://waiting
	    myFile.open("table.txt");
	    if(myFile.peek() == std::ifstream::traits_type::eof()){
	    state = 1;
	    sem -= 2;
	    }


	myFile.close();
        break;
	case 1: //producing
	   myFile.open("table.txt");
    	    while(sem < 2){
                if(myFile.is_open()){
                myFile << i << "\n";//add 1 line to file
                i++;
                sem++;
                }
    		state = 0;//after sem = 2 set state to 0
		myFile.close();//write the file
    	    }
	break;
    }
}


myFile.close();
return 0;

}
