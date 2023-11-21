#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> data;


int read(){
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
    return data.size();
}

string getPassword(string email){
    int i = 6;
    int n = read();
    string pass;
    while(i<=n){
        if(email == data[i]){
            pass = data[i+1];
        }
        i+=6;
    }
    return pass;
}
