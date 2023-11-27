#ifndef GETDATASEC_H
#define GETDATASEC_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<string>
using namespace std;

void getDataSec(const string& email){
    vector<string> data;
    string path = "user.csv";
    ifstream file;
    string read;
    // int f = 0;
    
    file.open(path);
    while (getline(file,read)){
        istringstream line(read);
        string word;
        while (getline(line,word,','))
        {
            data.push_back(word);
        }
        
    }
    file.close();

    int i = 6;
    string dataStr;
    int n = data.size();;
    while(i<n){
        if(email == data[i]){
            cout << "\nUser Name: "+data[i+3]+ "    Date Of Birth: " + data[i+4] + "    Profession: " + data[i+5] +"    Email: " + data[i] + "    Mobile No: " + data[i+2] + "\n"<<endl;
        }
        i+=6;
    }
}

#endif