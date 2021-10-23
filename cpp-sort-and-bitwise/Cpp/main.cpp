// Furkan Karabulut
// https://github.com/Ntelhon
// 21/10/2021 - UTC+3 00:08
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function for finding num number when you use select "enter input" section in Number Sorter.
int findNumNumbers(string numbers){
    int i = 0;
    int start = 0;
    int end = numbers.find(",");

    while (end != -1)
    {
        i++;
        start = end + 1;
        end = numbers.find(",", start);
    }

    cout << "Entered num number: " << i << "\n";
    return i;
}

// Funciton that will become active when you select "enter input" section in Number Sorter.
void ownNumbers(){
    cout << "Write your numbers separated by commas (Max: 100): ";
    string enteredNums;
    cin.ignore();
    getline(cin, enteredNums);
    enteredNums = enteredNums + ",";

    // Find entered num number and crete an array
    int numNumber = findNumNumbers(enteredNums);
    int numArray[numNumber];

    int start = 0;
    int end = enteredNums.find(",");

    // Split nums and add them to a int array
    for (int i = 0; end != -1; i++)
    {
        numArray[i] = stoi(enteredNums.substr(start, end - start));
        start = end + 1;
        end = enteredNums.find(",", start);
    }

    // Sort algorithm
    int lNum;
    for (int t = 0; t < numNumber; t++)
    {
        for (int i = 1; i < numNumber-t; i++)
        {
            if (numArray[t] > numArray[t+i])
            {
                lNum = numArray[t+i];
                numArray[t+i] = numArray[t];
                numArray[t] = lNum;
            }

            // To see what is going on:
            // for(const int& num : numArray){cout << num << " - ";}cout << "\n";
        }
    }

    // Write sorted version of nums
    for(const int& num : numArray){
        if(num != numArray[numNumber-1])
        {
            cout << num << " < ";
        }else{
            cout << num;
        }
    }
    
    cout << "\n\n";
}

// Funciton that will become active when you select "use number set" section in Number Sorter.
void numberSet(){
    vector<int> nums{102, 213, 334, 425, 563, 775, 78, 839, 11, 10};
    int lNum;
    int s = nums.size();
    
    for (int t = 0; t < s; t++)
    {
        for (int i = 1; i < s-t; i++)
        {
            if (nums[t] > nums[t+i])
            {
                lNum = nums[t+i];
                nums[t+i] = nums[t];
                nums[t] = lNum;
            }

            // To see what is going on:
            // for(const int& num : nums){cout << num << " - ";}cout << "\n";
        }
    }

    cout << "Number of numbers entered: " << s << "\n";

    for(const int& num : nums){
        if(num != nums[s-1])
        {
            cout << num << " < ";
        }else{
            cout << num;
        }
    }
    
    cout << "\n\n";
}

// Main Number Sorter function.
void numberSorter(){
    while (1)
    {
        cout << "Welcome to the Number Sorter! \n";
        cout << "Do you want to enter your own numbers (0), \nor use that {102, 213, 334, 425, 563, 775, 78, 839, 11, 10} number set? (1) \nPlease enter 0 or 1: ";
        string answer;
        cin >> answer;
        cout << "\n";

        if(answer == "0"){
            ownNumbers();
        }
        else if(answer == "1"){
            numberSet();
        }else{
            cout << "Unvalid input!";
        }

        string close;
        cout << "Press any button and enter to restart app \n";
        cout << "Press q to go main menu \n";
        cin >> close;
        if(close == "q") break;
        cout << "\n---\n---\n---\n---\n\n";
    }
    
}

// Function to convert your decimal or hexadecimal number to binary.
string numToBit(int num){
    string bits;
    unsigned int i = ~(~0u >> 1);

    while(i){
        bits += (num & i ? '1' : '0');
        i >>= 1;
    }

    // Delete the zeros at the left side.
    bits = bits.substr(bits.find("1"), -1);

    return bits;
}

// Function to write your number in decimal and binary.
void writeNumInfo(int num){
    cout << "Number at decimal: " << num;
    cout << "\nNumber at binary:  " << numToBit(num);
    cout << "\n";
}

// Main Bit Operator function.
void bitOperator(){
    cout << "Welcome to the Bit Operator!\n Please enter a number to which want to bitwise: ";
    int num;
    cin >> num;
    writeNumInfo(num);

    while(1){
        cout << "Operations:\n";
        cout << "Right shift (r)\n";
        cout << "Left shift (l)\n";
        cout << "Do n. bit zero (z)\n";
        cout << "Do n. bit one (o)\n";
        cout << "Do n. bit reverse (R)\n";
        cout << "Exit (q)\n";
        cout << "Help (h)\n";
        cout << "Enter the operation: ";

        string operation;
        cin >> operation;
        
        if(operation.find("r") != -1){
            int multiplier = stoi(operation.substr(0, operation.find("r")));
            num >>= multiplier;
            writeNumInfo(num);
        }

        if(operation.find("l") != -1){
            int multiplier = stoi(operation.substr(0, operation.find("l")));
            num <<= multiplier;
            writeNumInfo(num);
        }

        if(operation.find("z") != -1){
            int multiplier = stoi(operation.substr(0, operation.find("z")));
            num &= ~(1u << multiplier);
            writeNumInfo(num);
        }

        if(operation.find("o") != -1){
            int multiplier = stoi(operation.substr(0, operation.find("o")));
            num |= (1u << multiplier);
            writeNumInfo(num);
        }

        if(operation.find("R") != -1){
            int multiplier = stoi(operation.substr(0, operation.find("R")));
            num ^= (1u << multiplier);
            writeNumInfo(num);
        }

        if(operation == "q") break;
        if(operation == "h") cout << "Select a operation and bit, after write your bit-index and operation-letter respectively.\nFor example: for to do third bit of 18 (10010) to reverse write \"3R\", and the new number is 26 (11010).\n";
    }
}

int main(){
    while (1)
    {
        cout << "\n---\n---\n---\n---\n\n";
        cout << "Hello, I am Furkan Karabulut and welcome to the my first C++ project. \nI learnd C++ and made that app for ITU Electric Vehicle Team member election.\nI hope you will like it. \nApplications can be select with typing number in parantheses:\n";
        cout << "Number Sorter (0)\n";
        cout << "Bit Operator (1)\n";
        cout << "Select a app: ";
        string selectedApp;
        cin >> selectedApp;

        bool displayQuitMessage = true;

        if(selectedApp == "0"){
            cout << "\n---\n---\n---\n---\n\n";
            displayQuitMessage = false;
            numberSorter();
        }
        else if(selectedApp == "1"){
            cout << "\n---\n---\n---\n---\n\n";
            displayQuitMessage = false;
            bitOperator();
        }else{
            cout << "Unvalid input!\n";
        }

        if (displayQuitMessage == true)
        {
            string close;
            cout << "Press any button to restart app \n";
            cout << "Press q to exit \n";
            cin >> close;
            if(close == "q") break;
            cout << "\n---\n---\n---\n---\n\n";
        }
    }
}