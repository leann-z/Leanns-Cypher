#include "Cipher.h"

// Preconditions - None
// Postconditions - A message is stored in a Cipher object
Cipher::Cipher() {
    m_message = "";
    m_isEncrypted = false; // sets m_message and m_isencrypted to default

}


// Preconditions - A message is passed to this constructor, and if it is encrypted
// Postconditions - A message is stored in a Cipher object
Cipher::Cipher(string message, bool isEncrypted) {
    m_message = message;
    m_isEncrypted = isEncrypted; // sets m_message and m_isEncrypted

}

// Preconditions - A derived class is being deleted
// Postconditions - A base class is deleted
Cipher::~Cipher() {

}

// Preconditions - The message exists
// Postconditions - A message is returned
string Cipher::GetMessage() {
    return m_message;
}

// Preconditions - The cipher exists
// Postconditions - A bool is returned
bool Cipher::GetIsEncrypted() {
    return m_isEncrypted;
}

// Preconditions - The message exists
// Postconditions - A message is updated
void Cipher::SetMessage(string message) {
    m_message = message;

}

// Preconditions - The cipher exists
// Postconditions - The m_isEncrypted is toggled
void Cipher::ToggleEncrypted() {
    if (m_isEncrypted) {
        m_isEncrypted = false; //if message is encrypted, toggle to false
    }
    else if (m_isEncrypted == false) {
        m_isEncrypted = true; // if message is not encrypted, toggle to true
    }

}





