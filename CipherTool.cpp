#include "CipherTool.h"

// Preconditions - Input file passed and populated with Cipher
// Postconditions - CipherTool created
CipherTool::CipherTool(string fileName) {
    m_filename = fileName;
}

// Preconditions - m_ciphers is populated
// Postconditions - m_ciphers deallocated and vector emptied
CipherTool::~CipherTool() {
    for (int i = 0; i < m_ciphers.size(); i++) {
        delete m_ciphers.at(i); // deletes to ensure no memory leaks
    }

}

// Preconditions - Input file passed and populated with Ciphers
// Postconditions - m_ciphers populated with Ciphers
void CipherTool::LoadFile() {
    ifstream file(m_filename);  // loads file
    string next;
    while (getline(file, next, DELIMITER)) { // while loop to iterate through file
        char c;
        c = next[0];
        getline(file, next, DELIMITER); // uses getline
        bool isEncrypted = StringToBoolean(next); // stores stringtoboolean in a boolean
        getline(file, next, DELIMITER);
        string message = next;

        int num = 0;
        getline(file, next);
        if (c == 'c' or c == 'r') { // if character is cesear or railfence
            num = stoi(next);
        }
        if (c == 'c') {
            m_ciphers.push_back(new Caesar(message, isEncrypted, num)); // push back in vector if its cesar
        } else if (c == 'r') {
            m_ciphers.push_back(new RailFence(message, isEncrypted, num)); // push back in vector if its railfence
        } else if (c == 'o') {
            m_ciphers.push_back(new Ong(message, isEncrypted)); // push back in vector if its ONG
        } else if (c == 'v') {
        m_ciphers.push_back(new Vigenere(message, isEncrypted, next));
    }

    }
}

// Preconditions - Passed string of either 0 or 1
// Postconditions - Returns false if 0 else true
bool CipherTool::StringToBoolean(string input) {
    if (input == "0") { // if false
        return false;
    } else {
        return true; // if true
    }
}

// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Displays ciphers
void CipherTool::DisplayCiphers() {
    for (int i = 0; i < m_ciphers.size(); i++) {
        cout << i + 1 << ". \"" << m_ciphers.at(i)->GetMessage() << "\" (" << // displays numbered ciphers
        m_ciphers.at(i)->ToString() << ")" << endl;
    }

}


// Preconditions - Input file passed and m_ciphers populated
// Postconditions - Either Encrypts or Decrypts each cipher in m_ciphers
void CipherTool::EncryptDecrypt(bool encrypt) {
    int count = 0;
    for (int i = 0; i < m_ciphers.size(); i++) { // iterate through m_ciphers
        if (encrypt) {
            if (!m_ciphers.at(i)->GetIsEncrypted()) { // if it isn't encrypted
                m_ciphers.at(i)->Encrypt();
                count++;
            }
        } else {
            if (m_ciphers.at(i)->GetIsEncrypted()) { // if it is encrypted
                m_ciphers.at(i)->Decrypt();
                count++;
            }
        }
    }
    if (encrypt) {
        cout << count << " ciphers Encrypted" << endl; // displays the amount of ciphers encrypted
    } else {
        cout << count << " ciphers Decrypted" << endl; // displays the amount of ciphers decrypted
    }
}


// Preconditions - Input file passed and m_ciphers populated
// Postconditions - All ciphers exported
void CipherTool::Export() {
    cout << "What would you like to call the export file?" << endl;
    string fileName;
    cin >> fileName; // input in file content
    ofstream out(fileName);
    for (int i = 0; i < m_ciphers.size(); i++) {
        out << m_ciphers.at(i)->FormatOutput();
    }
    out.close(); // close file
    cout << m_ciphers.size() << " ciphers exported" << endl;
}

// Preconditions - m_ciphers all populated
// Postconditions - Returns choice
int CipherTool::Menu() {
    int choice = 0; // displays menu
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Ciphers" << endl;
    cout << "2. Encrypt All Ciphers" << endl;
    cout << "3. Decrypt All Ciphers" << endl;
    cout << "4. Export All Ciphers" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
    return choice;
}


// Preconditions - m_ciphers populated with ciphers
// Postconditions - none
void CipherTool::Start() {
    LoadFile();
    int choice = 0;
    while (choice != 5) { // if it isn't quit
        choice = Menu();
        if (choice == 1)
            DisplayCiphers(); // if user choice is 1, display ciphers
        if (choice == 2)
            EncryptDecrypt(true); // if user choice is 2, encrypt ciphers
        if (choice == 3)
            EncryptDecrypt(false); // if user choice is 3, decrypt ciphers
        if (choice == 4)
            Export(); // if user choice is 4, export all ciphers

    }
    cout << "Thanks for using UMBC Encryption" << endl;
}