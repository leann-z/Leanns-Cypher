//Title: Caesar.h
//Author: Jeremy Dixon
//Date: 4/1/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#ifndef CAESAR_H
#define CAESAR_H
#include "Cipher.h"
#include <istream>
#include <string>
#include <sstream>
using namespace std;

class Caesar: public Cipher{
 public:
  // Name: Caesar (Default Constructor)
  // Desc: Constructor to build an empty Caesar Cipher (Defaults to shift 3)
  // Preconditions - None
  // Postconditions - Creates a Caesar cipher to be encrypted
  Caesar();
  // Name: Caesar (Overloaded Constructor)
  // Desc: Constructor to build a populated Caesar Cipher (Defaults to shift 3)
  // Preconditions - Pass it the message, isEncrypted, and shift (any integer)
  // Postconditions - Creates a Caesar cipher to be encrypted
  Caesar(string, bool, int);
  // Name: Caesar (Destructor)
  // Desc: Destructor - Anything specific to Caesar to delete?
  // Preconditions - ~Caesar exists
  // Postconditions - Caesar destroyed
  ~Caesar();
  // Name: Encrypt
  // Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
  // Preconditions - Message exists
  // Postconditions - Shifts each character "right".
  void Encrypt();
  // Name: Decrypt
  // Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
  // Preconditions - Message exists
  // Postconditions - Shifts each character "left".
  void Decrypt();
  // Name: ToString
  // Desc - A function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Caesar in this case)
  string ToString();
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - c, delimiter, isencrypted, delimiter,
  //                  message, delimiter, m_shift are returned for output
  string FormatOutput();
private:
  int m_shift; //Number of characters to shift. (A shift 3 = D) (D shift -3 = A)
};


#endif
