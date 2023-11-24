#ifndef GETPASSWORD_H
#define GETPASSWORD
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string getPassword(string email){
    string path = "user.csv";
    vector<string> data;
    ifstream file;
    string read;    
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
    int n = data.size();
    string pass;
    while(i<=n){
        if(email == data[i]){
            pass = data[i+1];
        }
        i+=6;
    }
    return pass;
}

#endif