#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

#include "getPassword.h"
#include "write.h"
#include "checkEmail.h"
#include "getDataSec.h"


using namespace std;

struct UserData {
    string email;
    string password;
    string mobileNumber;
    string userName;
    string dateOfBirth;
    string profession;
};


UserData parseCSVLine(const string& line) {
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while (getline(iss, token, ',')) {
        tokens.push_back(token);
    }


    return {tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]};
}


void updateData(string filename, string email, string option) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    vector<UserData> userDataList;
    string line;
    while (getline(inputFile, line)) {
        UserData userData = parseCSVLine(line);
        
        if (userData.email == email) {
            if (option == "email"){
                cout << "\nEnter new email: " <<endl;
                cin >> userData.email;
            } else if (option == "password"){
                cout << "\nEnter new password: " << endl;
                cin >> userData.password;
            } else if(option == "mobno"){
                cout << "\nEnter new mobile number: " << endl;
                cin >> userData.mobileNumber;
            } else if(option == "username"){
                cout << "\nEnter your new user name: " << endl;
                cin.ignore();
                getline(cin,userData.userName);
            } else if(option == "dob"){
                cout << "\nEnter your new dob: " << endl;
                cin >> userData.dateOfBirth;
            } else if (option == "profession"){
                cout << "\nEnter your new profession: " << endl;
                cin.ignore();
                getline(cin, userData.profession);
            } else {
                cout << "\nOpps! Wrong option: " << endl;
            }
            
        }
        userDataList.push_back(userData);
    }

    inputFile.close();

    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing" << endl;
        return;
    }

    for (const auto& userData : userDataList) {
        outputFile << userData.email << ',' << userData.password << ',' << userData.mobileNumber << ',' <<
                       userData.userName << ',' << userData.dateOfBirth << ',' << userData.profession << '\n';
    }

    outputFile.close();
}


int signup(){
    string email;
    string password;
    string mobno;
    string profession;
    string dob;
    string name;
    cout << "\nEnter your email: " << endl;
    cin >> email;
    int already = checkEmail(email);
    if(already == 1){
        cout << "Email already registered **** Try Sign in: \n"<<endl;
        return 0;
    } else {
        cout << "\nEnter password: " << endl;
        cin >> password;
        while(password.length() < 7){
            cout << "Password invalid" << endl;
            cout << "Enter password greater than 6 character: " << endl;
            cin >> password;
        }
        cout << "\nEnter your mobile number: " << endl;
        cin >> mobno;
        
        cout << "\nEnter your name: " <<endl;
        cin.ignore();
        getline(cin, name);

        cout << "\nEnter your date of birth: " << endl;
        cin >> dob;

        cout << "\nEnter your profession: " << endl;
        cin.ignore();
        getline(cin, profession);
        
        write(email, password, mobno, name, dob, profession);
        cout << "\nUser Name: "+ name + "    Date Of Birth: " + dob + "    Profession: " + profession +"    Email: " + email + "    Mobile No: " + mobno + "\n"<<endl;

        return 1;
    }
}


int login(const string& email){
    int result = checkEmail(email);
    string pass;
    string userPass = getPassword(email);
    if(result == 1){
        cout << "Enter your password: ";
        cin >> pass;
        while(userPass != pass){
            cout << "Opps! Password Incorrect, Try again\nEnter your Password:  " << endl;
            cin >> pass;
        }
        if(pass == userPass) return 1;
    } 
    return 0;
}

int signin(string email, string option){
    string dataupdate;
    string password;
    if(option == "signin"){
        while(checkEmail(email) != 1){
            cout << "Email invalid, Enter your email again or 'exit' to exit: " << endl;
            cin >> email;
            if(email == "exit"){
                return 0;
            }
            
        }
        if(checkEmail(email) == 1){
            cout << "Enter your password: " << endl;
            cin >> password;
            while(getPassword(email) != password){
                cout << "Password incorrect, Enter 'Your password' to try again || 'exit' to exit: ";
                cin >>password;
                if(password == "exit"){
                    break;
                }
            }
            if(password == getPassword(email)){
                cout << "\nLogin successfull";
                getDataSec(email);
                cout << "Enter 'email' to update Email || 'username' for Name || 'mobno' for Mobile No || 'dob' for Date Of Birth || 'password' for Password || 'profession' for Profession || 'exit' for Exit: ";
                cin >> dataupdate;
                while(dataupdate != "exit"){
                    updateData("user.csv", email, dataupdate);
                    cout << "Data after updation: " << endl;
                    getDataSec(email);
                    cout << "Enter 'email' to update Email || 'username' for Name || 'mobno' for Mobile No || 'dob' for Date Of Birth || 'password' for Password || 'profession' for Profession || 'exit' for Exit: ";
                    cin >> dataupdate;
                }
                if(dataupdate == "exit"){
                    return 0;
                }
            } else {
                cout << "Enter 'update' to update password || 'exit' to exit: ";
                cin >> option;
                while(option == "update"){
                    updateData("user.csv",email,"password");
                    cout << "Your new password is " << getPassword(email);
                    getDataSec(email);
                    cout << "Enter 'email' to update Email || 'username' for Name || 'mobno' for Mobile No || 'dob' for Date Of Birth || 'password' for Password || 'profession' for Profession || 'exit' for Exit: ";
                    cin >> dataupdate;
                    while(dataupdate != "exit"){
                        updateData("user.csv", email, dataupdate);
                        cout << "Data after updation: " << endl;
                        getDataSec(email);
                        cout << "Enter 'email' to update Email || 'username' for Name || 'mobno' for Mobile No || 'dob' for Date Of Birth || 'password' for Password || 'profession' for Profession || 'exit' for Exit: ";
                        cin >> dataupdate;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

int main(){
    string option;
    string email;
    string password;
    string dataupdate;
    cout << "\n****************************************    Welcome to User Login System    **************************************** \n" << endl;
    cout << "Enter 'signup' to create account && 'signin' to login && 'exit' to exit: ";
    cin >> option;
    while(option != "exit"){
        if(option == "signup"){
            int ans = signup();
            if(ans == 1){
                cout << "Signup Successfull, Enter details to login: " << endl;
                cout << "Enter your email: " << endl;
                cin >> email;
                int out1 = signin(email,"signin");
                if(out1 == 0){
                    break;
                }
            } else {
                cout << "Try signin: " << endl;
                cout << "Enter your Email: ";
                cin >> email;
                int out1 = signin(email,"signin");
                if(out1 == 0){
                    break;
                }
            }
        } else {
            cout << "Enter your email: " << endl;
            cin >> email;
            int out = signin(email,option);
            if(out == 0){
                break;
            }
        }
    }

}