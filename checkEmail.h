#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


int checkEmail(string email){
    string path = "user.csv";
    ifstream file2;
    string read;
    int f = 0;
    vector<vector<string>> data;
    file2.open(path);
    while (getline(file2, read)){
        istringstream line(read);
        vector <string> row;
        string word;
        while(getline(line, word,',')){
            row.push_back(word);
        }
        data.push_back(row);
    }
    file2.close();
    for (const auto& row : data) {
        for (const auto& value : row) {
            if(email == value){
                f = 1;
                break;
            }
        }
        
    }
    return f;
}
