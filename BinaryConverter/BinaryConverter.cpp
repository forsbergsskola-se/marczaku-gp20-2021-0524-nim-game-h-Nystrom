#include <valarray>
#include <vector>
using namespace std;
#include <iostream>
#include <string>
#include <limits>

    vector<bool> ConvertUnsignedIntToBinary(uint32_t inputValue){
        auto boolArray = new vector<bool>;
        
        for (int i = 31; i >= 0; i--){
            const uint32_t bitValue = pow(2, i);
            if (!(inputValue >= bitValue)){
                boolArray->push_back(false);
                continue;
            }   
            boolArray->push_back(true);
            inputValue -= bitValue;
        }
        return *boolArray;
    } 
    void PrintBinaryNumber(const vector<bool> boolArray){
        cout << "Logical operators 32bit uInt: " << endl;
        cout << "0b" << flush;
        for (int i = 0; i < boolArray.size(); i++){
            const char numberCharacter = boolArray.at(i) ? '1' : '0';
            cout << numberCharacter << flush;
        }
        cout << "" << endl;
    }
    void BitwiseConvertAndPrint(const uint32_t inputValue){
        cout << "Bitwise operators 32bit uInt: " << endl;
        cout << "0b" << flush;
        for (int i = 31; i >= 0; i--){
            if(inputValue & 1 << i){
                cout << 1 << flush;
            }
            else{
                cout << 0 << flush;    
            }
        }
        cout << "" << endl;
    }
    bool BooleanInputCheck(string valueCheck, string message) {
            string inputValue;
            cout << message << endl;
            getline(cin, inputValue);
            return inputValue == valueCheck;
    }

    void ResetCin(){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    uint32_t GetUserInputValue(){
        const uint32_t maxValue = numeric_limits<uint32_t>::max(); 
        while (true){
            uint64_t userInputValue;
            cout << "Input a positive integer: " << endl;
            cin >> userInputValue;
            if(cin.good()){
                if(userInputValue >= 0 && userInputValue <= maxValue){
                    ResetCin();
                    return userInputValue;
                }
                    
            }
            ResetCin();
            cout << "Input needs to be a positive number between: 0 and " + to_string(maxValue) + "!"<< endl;
        }
    }
    int main(){
        while (true){
            const uint32_t userInputValue = GetUserInputValue();
            const vector<bool> boolArray = ConvertUnsignedIntToBinary(userInputValue);
            PrintBinaryNumber(boolArray);
            BitwiseConvertAndPrint(userInputValue);
            if(BooleanInputCheck("x", "Press x to quit!"))
                break;
        }
        cout << "Shutting down!" << endl;
        return 0;
    }
