#include "RailFence.h"


// Preconditions - None
// Postconditions - Creates a RailFence cipher
RailFence::RailFence(): Cipher() {
 m_rails = 3;
}


// Preconditions - Pass it the message, isEncrypted, and number of rails (any integer)
// Postconditions - Creates a RailFence cipher to be encrypted
RailFence::RailFence(string message, bool isEncrypted, int rails): Cipher(message, isEncrypted) { // inheritance
    m_rails = rails; // sets m_rails as rails
}

// Preconditions - ~RailFence exists
// Postconditions - RailFence destroyed
RailFence::~RailFence() {

}


// Preconditions - Message exists
// Postconditions - A single encrypted string is stored
void RailFence::Encrypt() {
    string m_message = GetMessage();
    char rail[m_rails][m_message.length()]; // crates char called rail
    int row = 0;
    int column = 0;
    bool isUp = true; // a flag to check where I am in the multidimensional array

    if (GetIsEncrypted() == false) { // if string isn't encryped
        for (int i = 0; i < m_rails; i++) {
            for (int j = 0; j < m_message.length(); j++) {
                rail[i][j] = '\n'; // default
            }
        }

        for (int i = 0; i < m_message.length(); i++) {
            rail[row][column] = m_message[i];
            column++; // traversing the array
            if (row == 0)
                isUp = false; // flag turns to false if first row
            else if (row == m_rails - 1)
                isUp = true; // flag turns true if row is m_rails - 1
            if (isUp)
                row--;
            else
                row++;
        }

        string newMessage = "";
        for (int i = 0; i < m_rails; i++) {
            for (int j = 0; j < m_message.length(); j++) {
                if (rail[i][j] != '\n') {
                    newMessage += rail[i][j]; // adds the rail to new string
                }
            }
        }
        SetMessage(newMessage); // calls setmessage and toggleencrypted
        ToggleEncrypted();
    }

}


// Preconditions - Message exists
// Postconditions - The decrypted string is stored
void RailFence::Decrypt() {
    string m_message = GetMessage();
    char rail[m_rails][m_message.length()]; // creates same char as in ecrypt
    int row = 0;
    int column = 0;
    bool isUp = true; // same flag used in encrypt

    if (GetIsEncrypted()) { // checks if the string is encrypted
        for (int i = 0; i < m_rails; i++) {
            for (int j = 0; j < m_message.length(); j++) {
                rail[i][j] = '\n'; // sets default
            }
        }
        for (int i = 0; i < m_message.length(); i++) {
            rail[row][column] = '*'; // create s a star to check location
            column++;
            if (row == 0)
                isUp = false; // flag set to false if first row
            else if (row == m_rails - 1)
                isUp = true; // flag set to true if row is at m_rails - 1
            if (isUp)
                row--;
            else
                row++;
        }
        int count = 0; // creates count to traverse
        for (int i = 0; i < m_rails; i++) {
            for (int j = 0; j < m_message.length(); j++) {
                if (rail[i][j] == '*') { // if that's the location in rail that we're looking for
                    rail[i][j] = m_message[count];
                    count++; // increments count
                }
            }
        }
        row = 0;
        column = 0;
        isUp = true;
        string newMessage = "";
        for (int i = 0; i < m_message.length(); i++) { // for loop to go through m_message
            newMessage += rail[row][column]; // increments newMessage
            column++;
            if (row == 0)
                isUp = false; // flag turns to false if first row
            else if (row == m_rails - 1)
                isUp = true; // flag turns to true if row is at m_rails - 1
            if (isUp)
                row--;
            else
                row++;
        }
        SetMessage(newMessage); // calls setmessage toggleencrypted
        ToggleEncrypted();


    }
}


// Preconditions - The object exists
// Postconditions - The subtype is returned (RailFence in this case)
string RailFence::ToString() {
    return "RailFence";
}


// Preconditions - The object exists (use stringstream)
// Postconditions - r, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_rails are returned for output
string RailFence::FormatOutput() {
    stringstream s;
    s << "r" << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << // matches output from document
      DELIMITER << m_rails << endl;
    return s.str();
}
