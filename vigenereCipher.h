#include <math.h>
/********************************************************************
 * Header:
 *    Implement your cipher here. You can view 'example.h' to see the
 *    completed Caesar Cipher example.
 ********************************************************************/
#ifndef VIGENERE_H
#define VIGENERE_H

/********************************************************************
 * CLASS
 *******************************************************************/
class VigenereCipher : public Cipher
{
public:
    std::string fullKey = "";
    ~VigenereCipher()
    {
    }
    virtual std::string getAuthor() { return "Rodrigo Rodriguez"; } // TODO: return your name
    virtual std::string getCipherName() { return "Hill Cipher"; }   // TODO: return the cipher name

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        // TODO: Return a citation for your cipher
        std::string s;
        s += "JournalDev (2022), ";
        s += "'Vigenere Cipher and its implementation in C++\', \n   retrieved: ";
        s += "https://www.journaldev.com/43346/vigenere-cipher";
        // return std::string("citation");
        return s;
    }

    /**********************************************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual std::string getPseudocode()
    {
        std::string str;

        // TODO: please format your pseudocode
        // The encrypt pseudocode
        str =  "encrypt(text, key)\n";
        str += "    string fullKey\n";
        str += "    while(text.size() > password.size())\n";
        str += "        fullKey += fullKey\n";
        str += "    string cipherText\n";
        str += "    for (i <text.size())\n";
        str += "        cipherText += ((text[i] - ' ' + fullKey[i] - ' ') % 95) + ' ' \n";
        str += "    return cipherText\n\n";
        

        // The decrypt pseudocode
        // str += "insert the decryption pseudocode\n";
        str += "decrypt(cipher, key)\n";
        str += "    string plainText\n";
        str += "    for (i < cipher.size())\n";
        str += "        plainText += (((cipherText[i] + ' ' - this->fullKey[i] - ' ') + 95) % 95) + ' '\n";
        str += "    return plainText\n";

        return str;
    }

    /************************************************************
     * ENCRYPT
     * Returns a cipher text of the plainText using the password
     ************************************************************/
    virtual std::string encrypt(const std::string &plainText,
                                const std::string &password)
    {   
        // password cannot be bigger than plainText in lenght
        assert(plainText.size()>= password.size());
        // We match the size of the password with the size of the plainText
        std::string fullKey = password;
        if (password.size() >= plainText.size())
            return fullKey;
        else {
            int psize = plainText.size()-password.size();
            int ksize = password.size();
            while (psize >= ksize) {
                fullKey += fullKey;
                psize -= ksize;
            }
            fullKey += fullKey.substr(0, psize);
        }
        this->fullKey = fullKey;

        std::string cipherText;
        // ' ' -> 32 ASCII -> first value for vigenere's table
        // %95 -> total amount of characters - > 32 - 126 ASCII
        for (int i = 0; i < plainText.size(); i++){
            std::cout << "( ( ("<< (int)plainText[i] << " - 32) + (" << (int)fullKey[i] << " - 32) ) %95 ) + 32 => ";
            cipherText += (char)( ( (int)plainText[i] - ' ' + (int)fullKey[i] - ' ' ) % 95) + ' ';
            std::cout << cipherText[i] << std::endl;
        }
        
        // std::cout << cipherText << std::endl;
        return cipherText;
    }

    /************************************************************
     * DECRYPT
     * Return the plainText of a cipher text using the password
     ************************************************************/
    virtual std::string decrypt(const std::string &cipherText,
                                const std::string &password)
    {
        std::string plainText = "";
        for (int i = 0; i < cipherText.size(); i++) {
            plainText += (char) ((((int)cipherText[i] - ' ' - (fullKey[i] - ' ')) + 95) % 95) + ' ';
        }
        // std::cout << plainText << std::endl;
        return plainText;
    }
};

#endif // VIGENERE_H