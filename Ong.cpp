#include "Ong.h"


// Preconditions - None
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong(): Cipher() {

}


// Preconditions - Pass it the message and isEncrypted
// Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong(string message, bool isEncrypted): Cipher(message, isEncrypted) {

}


// Preconditions - ~Ong exists
// Postconditions - Ong destroyed
Ong::~Ong() {

}


// Preconditions - Message exists
// Postconditions - Returns true or false as above
bool Ong::IsVowel(char c) {
    // if the character is a space
    if (c == ' ')
    return true;
    // if the character is vowel - uppercase
    if (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
        return true;
    // if the character is vowel - lowercase
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
        return true;
    // if character is a punctuation
    if (ispunct(c))
        return true;

    return false;
}


// Preconditions - Message exists
// Postconditions - Encrypts as above
void Ong::Encrypt() {
    string m_message = GetMessage(); // gets message and stores it as m_message
    string newMessage = "";
    if (GetIsEncrypted() == false) { // if string isn't encrypted
        for (int i = 0; i < m_message.length(); i++) { // traverses through m_message
            char c = m_message[i];
            if (IsVowel(c)) {
                if (isalpha(c)) { // if its an alphabet letter
                    newMessage += c;

                } else {
                    newMessage += c;
                }
            }
            else {
                    newMessage += c;
                    newMessage += "ong";
                }
            if (m_message[i] != ' ' && m_message[i+1] != ' ' && !ispunct(m_message[i]) && !ispunct(m_message[i+1]) )
                // if not a space or punctuation mark, add -
                newMessage += '-';

        }
        newMessage.pop_back();
        SetMessage(newMessage); // calls setmessage and toggleencrypted
        ToggleEncrypted();
    }
}

// Preconditions - Message exists
// Postconditions - Original message is displayed
void Ong::Decrypt() {
    string m_message = GetMessage();
    string newMessage = "";
    if (GetIsEncrypted()) { // if message IS encrypted, continue
        for (int i = 0; i < m_message.length(); i++) {
            char c = m_message[i];
            if (IsVowel(c)) { // if character is a vowel or space
                if (isalpha(c)) { // if the character is in alphabet
                    newMessage += c;

                    if (m_message[i + 1] != ' ') {
                        i += 1; // increment i if its a space
                    }
                } else {
                    newMessage += c;


                }
            }
                else if (m_message[i] == '(') {
                    i += 2;
                    newMessage += c;// increment i if its a bracket
            } else {
                newMessage += c;

                if (m_message[i+4] != ' ') {
                    i += 4;
                } else {
                    i += 3;
                }

            } if (m_message[i+1] == '-')
                // if not a space or punctuation mark, add -
                i += 1;


        }
        SetMessage(newMessage); // calls setmessage and toggleencrypted
        ToggleEncrypted();
    }

}


// Preconditions - The object exists
// Postconditions - The subtype is returned (Ong in this case)
string Ong::ToString() {
    return "Ong";
}


// Preconditions - The object exists (use stringstream)
// Postconditions - o, delimiter, isencrypted, delimiter,
//                  message, delimiter, blank are output
string Ong::FormatOutput() {
    stringstream s;
    s << "o" << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << // matches output of document
      DELIMITER << endl;
    return s.str();

}