//Title: Ong.h
//Author: Jeremy Dixon
//Date: 4/1/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC

#ifndef ONG_H
#define ONG_H
#include "Cipher.h"
#include <istream>
#include <string>
#include <vector>
using namespace std;

//Constant for use with the ong cipher
const string ong = "ong";

class Ong: public Cipher{
 public:
  // Name: Ong (Default Constructor)
  // Desc: Constructor to build an empty Ong Cipher
  // Preconditions - None
  // Postconditions - Creates a Ong cipher to be encrypted
  Ong();
  // Name: Ong (Overloaded Constructor)
  // Desc: Constructor to build a populated Ong Cipher
  // Preconditions - Pass it the message and isEncrypted
  // Postconditions - Creates a Ong cipher to be encrypted
  Ong(string, bool);
  // Name: Ong (Destructor)
  // Desc: Destructor - Anything unique to Ong to delete?
  // Preconditions - ~Ong exists
  // Postconditions - Ong destroyed
  ~Ong();
  // Name: IsVowel (Helper function)
  // Desc: Returns true if vowel, space, or punctuation
  // Preconditions - Message exists
  // Postconditions - Returns true or false as above
  bool IsVowel(char);
  // Name: Encrypt
  // Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
  // If consonant then consonant and ong and dash displayed.
  // Preconditions - Message exists
  // Postconditions - Encrypts as above
  void Encrypt();
  // Name: Decrypt
  // Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
  // Double check words like "wrong" so that they work correctly!
  // Preconditions - Message exists
  // Postconditions - Original message is displayed
  void Decrypt();
  // Name: ToString
  // Desc - A function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Ong in this case)
  string ToString();
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - o, delimiter, isencrypted, delimiter,
  //                  message, delimiter, blank are output
  string FormatOutput();
};

#endif
