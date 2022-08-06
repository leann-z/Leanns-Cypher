#include "Vigenere.h"

Vigenere::Vigenere(){
    m_shift = "";
}

Vigenere::Vigenere(string message, bool isEncrypted, string shift): Cipher(message, isEncrypted) {
     int i = 0;
     m_shift = "";
     while (m_shift.length() != message.length()) {

         if (i == shift.length()) {
          i = 0;
         }
         m_shift += toupper(shift[i]);
         i++;
     }
}

Vigenere::~Vigenere()  {}

void Vigenere::Encrypt() {
    string ct = "";
    string m_message = GetMessage();
    int j = 0;
    if (GetIsEncrypted() == false) {
        for (int i = 0; i < m_message.length(); i++) {
            if (isalpha(m_message[i])) {
                char upper = toupper(m_message[i]);
                char c = (char) (((int) upper - 'A' + (int) m_shift[j] - 'A') % 26);
                c += 'A';
                ct += c;
                j++;
            } else {
                ct += m_message[i];
            }
        }
    }


    SetMessage(ct); // calls set message and toggle encrypted
    ToggleEncrypted();
}

void Vigenere::Decrypt() {
    string pt = "";
    string m_message = GetMessage();
    int j = 0;
    if (GetIsEncrypted()) {
        for (int i = 0; i < m_message.length(); i++) {
            if (isalpha(m_message[i])) {
                char upper = toupper(m_message[i]);
                char c = (char) ((((int) upper - 'A' - ((int) m_shift[j] - 'A')) + 26) % 26);
                c += 'A';
                pt += c;
                j++;
            } else {
                pt += m_message[i];
            }
        }
    }
    SetMessage(pt);
    ToggleEncrypted();
}


string Vigenere::ToString() {
    return "Vigenere";
}

string Vigenere::FormatOutput() {
    stringstream s;
    s << "v" << DELIMITER << GetIsEncrypted() << DELIMITER << GetMessage() << // matches output of the document
      DELIMITER << m_shift << endl;
    return s.str(); // returns it as a string
}