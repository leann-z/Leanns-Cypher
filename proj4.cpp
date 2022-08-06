//Title: proj4.cpp
//Author: Jeremy Dixon
//Date: 4/2/2022
//Description: This is main for project 4.
#include "CipherTool.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

//Inside the parameters for main, we can pass arguments
//argc is the count of arguments
//argv are the parameters themselves
int main(int argc, char* argv[]) {
  cout << "Welcome to UMBC Encryption" << endl;
  while (argc < 2) { //Checks to make sure the user passes a file to load
    cout << "You are missing a data file." << endl;
    cout << "Expected usage ./proj4 proj4_test1.txt" << endl;
    cout << "The input file should have some strings to encrypt or decrypt" << endl;
    return 0;
  }
  CipherTool myCipher(argv[1]); //Creates a new ciphertool passing the filename
  myCipher.Start(); //Starts the cipherTool
  return 0;
}
