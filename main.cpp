#include "write.h"
#include "checkEmail.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>


using namespace  std;
int main(){
    // write("kashish@gmail.com","kashish@1234","9087654334","Kashish Kasaudhan","14/09/2004","Enginerr");
    cout << checkEmail("kashish@gmail.com");
    return 0;
}