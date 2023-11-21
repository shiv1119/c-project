#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>

using namespace std;

void write(string Email, string Password,string MobNo,string Username,string DOB,string Profession){
    string path = "user.csv";
    try {
        ofstream file;
        file.open(path,std::ios::out | std::ios::app);
        if (!file) {
        throw runtime_error("File failed to open.");
        }
        string str = ""+ Email + ","+ Password + "," + MobNo + "," + Username + "," + DOB + "," + Profession;
        file << str << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }

}

