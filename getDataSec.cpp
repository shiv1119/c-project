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

string getData(string email){
    int i = 6;
    string dataStr;
    int n = read();
    while(i<n){
        if(email == data[i]){
            dataStr = "\nUser Name: "+data[i+3]+ "\nDate Of Birth: " + data[i+4] + "\nProfession: " + data[i+5] +"\nEmail: " + data[i] + "\nPassword: " + data[i+1] + "\nMobile No: " + data[i+2] + "\n";
        }
        i+=6;
    }
    return dataStr;
}

string getMobNo(string email){
    int i = 6;
    string dataStr;
    int n = read();
    while(i<n){
        if(email == data[i]){
            dataStr = "\n Your mobile number is: " + data[i+2] + "\n";
        }
        i+=6;
    }
    return dataStr;
}

string getProfession(string email){
    int i = 6;
    string dataStr;
    int n = read();
    while(i<n){
        if(email == data[i]){
            dataStr = "\nYour profession is: " + data[i+5] + "\n";
        }
        i+=6;
    }
    return dataStr;
}

string getDOB(string email){
    int i = 6;
    string dataStr;
    int n = read();
    while(i<n){
        if(email == data[i]){
            dataStr = "\nYour date of birth is: " + data[i+4] + "\n";
        }
        i+=6;
    }
    return dataStr;
}

string getUserName(string email){
    int i = 6;
    string dataStr;
    int n = read();
    while(i<n){
        if(email == data[i]){
            dataStr = "\nYour User Name is: " + data[i+3] + "\n";
        }
        i+=6;
    }
    return dataStr;
}

string getEmail(string email){
    int i = 6;
    string dataStr;
    int n = read();
    while(i<n){
        if(email == data[i]){
            dataStr = "\nYour E-mail is: " + data[i] + "\n";
        }
        i+=6;
    }
    return dataStr;
}


int main(){

    cout << getProfession("Shivnandanverma@gmail.com") << endl;
}