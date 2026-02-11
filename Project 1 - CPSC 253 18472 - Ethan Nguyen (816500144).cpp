// ===================================================
//Attached: Project 1
// ===================================================
//Program: Project 1: Securing Our Channels
// ===================================================
//Programmer: Ethan Nguyen (816500144)
//Class: CPSC 253-12 18472
// ===================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void strtoDec(const string& input, string& output, int key) 
{
    output.clear();
    for (unsigned char c : input) 
    {
        output += to_string(static_cast<int>(c) * 7) + " ";
    }
}

void revstrtoDec(const string& input, string& output, int key) 
{
    output.clear();
    string temp;
    for (size_t i = 0; i < input.length(); ++i) 
    {
        if (input[i] == ' ') 
        {
            if (!temp.empty()) 
            {
                output += static_cast<char>(stoi(temp) / 7);
                temp.clear();
            }
        } 
        else 
        {
            temp += input[i];
        }
    }

    if (!temp.empty()) 
    {
        output += static_cast<char>(stoi(temp));
    }
}

int main() 
{
    int choice;
    string inputFile, outputFile;
    string content, outputString;
    int key;

    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter the input file name: ";
    getline(cin, inputFile);
    cout << "Enter the output file name: ";
    getline(cin, outputFile);
    cout << "Enter the encryption/decryption key (integer): ";
    cin >> key;
    
    if (choice == 1) 
    {
        ifstream inFile(inputFile);
        if (!inFile.is_open()) 
        {
            cerr << "ERROR" << endl;
            return 1;
        }
        getline(inFile, content);
        inFile.close();

        strtoDec(content, outputString, key);

        ofstream outFile(outputFile);
        if (!outFile.is_open()) 
        {
            cerr << "ERROR" << endl;
            return 1;
        }
        outFile << outputString << endl;
        outFile.close();

        cout << "File encrypted successfully." << endl;

    } 
    else if (choice == 2) 
    {

        ifstream inFile(inputFile);
        if (!inFile.is_open()) 
        {
            cerr << "ERROR" << endl;
            return 1;
        }
        getline(inFile, content);
        inFile.close();

        revstrtoDec(content, outputString, key);

        ofstream outFile(outputFile);
        if (!outFile.is_open()) 
        {
            cerr << "ERROR" << endl;
            return 1;
        }
        outFile << outputString << endl;
        outFile.close();

        cout << "File decrypted successfully." << endl;

    } 
    else 
    {
        cout << "\nERROR" << endl;
    }

    return 0;
}
