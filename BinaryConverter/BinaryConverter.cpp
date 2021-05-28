using namespace std;
#include <iostream>
#include <string>
#include <limits>

int GetUserInputValue(){
    while (true){
        int userInputValue;
        cout << "Input a positive integer: " << endl;
        cin >> noskipws >> userInputValue;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(userInputValue && userInputValue > -1)
            return userInputValue;
        
        cout << "Input needs to be a positive number!"<< endl;
    }
}

int main(){
    // while (true){
        //TODO: Read value positive integer:
    int userInputValue;
    
    userInputValue = GetUserInputValue();

        //TODO: convert to binary 0b110 etc...
        
    // }
    return 0;
}
