//Title: Cipher.h
//Author: Jeremy Dixon
//Date: 4/1/2022
//Description: This is part of the Cipher Project in CMSC 202 @ UMBC
#ifndef CIPHER_H
#define CIPHER_H
#include <iostream>
#include <string>
#include <sstream>      //Used to format output for each subtype for output
using namespace std;

//**Constants**
const char DELIMITER = '|';

class Cipher{
 public:
  // Name: Cipher (Default Constructor)
  // Desc - Stores a message and if it is encrypted (or not)
  // Preconditions - None
  // Postconditions - A message is stored in a Cipher object
  Cipher();
  // Name: Cipher (Overloaded Constructor)
  // Desc - Passed a message and if it is encrypted (or not)
  // Preconditions - A message is passed to this constructor, and if it is encrypted
  // Postconditions - A message is stored in a Cipher object
  Cipher(string message, bool isEncrypted);
  // Name: ~Cipher (Destructor)
  // Desc - Virtual destructor
  // Preconditions - A derived class is being deleted
  // Postconditions - A base class is deleted
  virtual ~Cipher();
  // Name: Decrypt
  // Desc - A purely virtal function to decrypt a message
  // Preconditions - The message is not already decrypted
  // Postconditions - A message is decrypted based on the child class
  virtual void Decrypt() = 0;
  // Name: Encrypt
  // Desc - A purely virtal function to encrypt a message
  // Preconditions - The message is not already encrypted
  // Postconditions - A message is encrypted based on the child class
  virtual void Encrypt() = 0;
  // Name: GetMessage
  // Desc - Returns the message
  // Preconditions - The message exists
  // Postconditions - A message is returned
  string GetMessage();
  // Name: GetIsEncrypted
  // Desc - Returns isEncrypted (0 is not encrypted and 1 is encrypted)
  // Preconditions - The cipher exists
  // Postconditions - A bool is returned
  bool GetIsEncrypted();
  // Name: SetMessage
  // Desc - Updates a message
  // Preconditions - The message exists
  // Postconditions - A message is updated
  void SetMessage(string);
  // Name: ToggleEncrypted
  // Desc - Turns (true to false) or (false to true)
  // Preconditions - The cipher exists
  // Postconditions - The m_isEncrypted is toggled
  void ToggleEncrypted();
  // Name: ToString
  // Desc - A purely virtual function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned
  virtual string ToString() = 0;
  // Name: FormatOutput
  // Desc - A purely virtual function that returns the formatted data for Output
  // Preconditions - The object exists
  // Postconditions - The type, message, and key are output
  virtual string FormatOutput() = 0;
  // Name: Overloaded << Operator
  // Desc - Outputs the message
  // Preconditions - The object exists
  // Postconditions - The message from the object is returned
  friend ostream &operator<<( ostream &output, Cipher &C);
private:
  string m_message; //The message being encrypted/decrypted
  bool m_isEncrypted; //Indicates if the message is encrypted/decrypted
};

#endif
