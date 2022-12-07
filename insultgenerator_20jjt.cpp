#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <time.h>
#include "insultgenerator_20jjt.h"

using namespace std;

FileException :: FileException(const string& m) : msg(m) {}
string FileException::what() const { 
    return msg; 
    }

NumInsultsOutOfBounds :: NumInsultsOutOfBounds(const string& m) : msg(m) {}
string NumInsultsOutOfBounds::what() const { 
    return msg;
    }

InsultGenerator :: InsultGenerator() : fileSize(0) {
	srand(time(0));
} 

int InsultGenerator :: random(int x) const{
    int num;
    num = static_cast<int>(1 * x * rand() / RAND_MAX);
    return num;
}

void InsultGenerator :: initialize(){
    string phrase;
    ifstream file(sourceFile);

    if (file.fail()) {
        throw FileException("Error: " + sourceFile + " cannot be opened");
        return;
    }

    for(fileSize = 0; !file.eof(); fileSize++){
        file >> phrase;
        adjective1.push_back(phrase);
        file >> phrase;
        adjective2.push_back(phrase);
        file >> phrase;
        adjective3.push_back(phrase);
    }

    file.close();
}

string InsultGenerator :: talkToMe() const {
    string insult("Thou ");
    insult = insult + adjective1.at(random(fileSize)) + "\t";
    insult = insult + adjective2.at(random(fileSize)) + "\t";
    insult = insult + adjective3.at(random(fileSize)) + "!";
    return insult;
}

vector<string> InsultGenerator :: generate(int num) const {
    int maxnum = 10000;

    if(num > maxnum || num <= 0){
        throw NumInsultsOutOfBounds("Error: Too many insults");
    }

    string insult;
    vector<string> insults;
    bool boolArray[fileSize][fileSize][fileSize];
    
    for (int num1 = 0; num1 < fileSize; num1++){
	    for (int num2 = 0; num2 < fileSize; num2++){
			for (int num3 = 0; num3 < fileSize; num3++){
				boolArray[num1][num2][num3] = false;
            }
        }
    }

    for(int count = 0; count < num;){
        int num1 = random(fileSize);
        int num2 = random(fileSize);
        int num3 = random(fileSize);
        if (boolArray[num1][num2][num3] == false) {
            boolArray[num1][num2][num3] = true;
            count++;
        }
    }

    int count = 0;
    for(int num1 = 0; num1 < fileSize && count < num; num1++){
        for(int num2 = 0; num2 < fileSize && count < num; num2++){
            for(int num3 = 0; num3 < fileSize && count < num; num3++){
                if(boolArray[num1][num2][num3] == true){
                    insult = "Thou " + adjective1.at(num1) + " " + adjective2.at(num2) + " " + adjective3.at(num3) + "!";
                    insults.push_back(insult);
                    count++;
                }
            }
        }
    }

    return insults;
}

void InsultGenerator :: generateAndSave(string fileName, int num) const {
    int maxnum = 10000;

    if(num > maxnum || num <= 0){
        throw NumInsultsOutOfBounds("Error: Too many insults");
    }

    vector<string> insults(generate(num));
    ofstream file(fileName);

    if(file.fail()){
        throw FileException("Error: " + fileName + " cannot be opened");
    }

    for(int count = 0; count < num; count++){
        file << insults[count] << endl;
    }

    file.close();
}
