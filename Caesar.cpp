#include "Caesar.h"


// Preconditions - None
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar(): Cipher(){
    m_shift = 3;
}


// Preconditions - Pass it the message, isEncrypted, and shift (any integer)
// Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar(string message, bool isEncrypted, int shift): Cipher(message, isEncrypted) {
   m_shift = shift % 26; // adjusts m_shift

}



// Preconditions - ~Caesar exists
// Postconditions - Caesar destroyed
Caesar::~Caesar() {

}


// Preconditions - Message exists
// Postconditions - Shifts each character "right".
void Caesar::Encrypt() {
    string m_message = GetMessage();

    // checks if the string is encrypted
    if (GetIsEncrypted() == false) {
        // encrypting a string
        for (int i = 0; i < m_message.length(); i++) {
            // shifts to the right depending on m_shift
            if (isalpha(m_message[i])) { //checks if in alphabet

                if ((m_message[i] + m_shift) > 90 && m_message[i] + m_shift < 61) { // checks the string with the shifts
                  m_message[i] = m_message[i] - 26 + m_shift;
                } else if (m_message[i] + m_shift > 122) {
                    m_message[i] = m_message[i] - 26 + m_shift; // adjusts the message depending on m_shift
                } else
                m_message[i] = m_message[i] + m_shift;
            }

        }
        SetMessage(m_message); // calls set message and toggle encrypted
        ToggleEncrypted();

    }
}


// Preconditions - Message exists
// Postconditions - Shifts each character "left".
void Caesar::Decrypt() {
    string m_message = GetMessage();
    // decrypting a string
    if (GetIsEncrypted()) {
        for (int i = 0; i < m_message.length(); i++)
            // shifts to left depending on m_shift
            if (isalpha(m_message[i])) {
                if ((m_message[i] - m_shift) < 97 && m_message[i] - m_shift > 90) { // if statement to shift to the left
                    m_message[i] = m_message[i] + 26 - m_shift;
                } else if (m_message[i] - m_shift < 65) { // if the result is less than 65
                    m_message[i] = m_message[i] + 26 - m_shift;
                } else
                    m_message[i] = m_message[i] - m_shift; // if its greater than 65
            }
        SetMessage(m_message); // calls setmessage and toggleencrypted
        ToggleEncrypted();
    }
}


// Preconditions - The object exists
// Postconditions - The subtype is returned (Caesar in this case)
string Caesar::ToString() {
    return "Caesar";
}


// Preconditions - The object exists (use stringstream)
// Postconditions - c, delimiter, isencrypted, delimiter,
//                  message, delimiter, m_shift are returned for output
string Caesar::FormatOutput() {
    stringstream s;
    s << "c" << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << // matches output of the document
    DELIMITER << m_shift << endl;
    return s.str(); // returns it as a string

}