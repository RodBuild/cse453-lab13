#include <math.h>
/********************************************************************
 * Header:
 *    Implement your cipher here. You can view 'example.h' to see the
 *    completed Caesar Cipher example.
 ********************************************************************/
#ifndef HILLCIPHER_H
#define HILLCIPHER_H

/********************************************************************
 * CLASS
 *******************************************************************/
class HillCipher : public Cipher
{
public:
    float cipherText[255][1];
    float plainText[255][1];
    float** o_matrix;
    float** r_matrix;
    ~HillCipher()
    {
        delete o_matrix;
        delete r_matrix;
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
        s += "PrivacyCanada.net (2022), ";
        s += "\"Privacy Canada - Hill Cipher\', \n   retrieved: ";
        s += "https://privacycanada.net/hill-cipher/";
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
        str += "    keyMatrix_Size = ceil(password / 2)\n";
        str += "    keyMatrix = createMatrix(key)\n";
        str += "    textMatrix = text[i][0]\n";
        str += "    encryptedMatrix[255][255]\n";
        str += "    for (i < text.length())\n";
        str += "        for (j < 1)\n";
        str += "            for (x < keyMatrix_size)\n";
        str += "                encryptedMatrix[i][j] += keyMatrix[row(0 - keyMatrix_size)][x] * textMatrix[i][j]\n";
        str += "    for (i < text.length())\n";
        str += "        cipherText += (char)((fmod(encryptedMatrix[i][0], 94) + 32)\n";
        str += "    return cipherText\n\n";
        

        // The decrypt pseudocode
        // str += "insert the decryption pseudocode\n";
        str += "decrypt(cipher, key)\n";
        str += "    reversedMatrix = reverseMatrix(keyMatrix);\n";
        str += "    cipherMatrix = cipher[i][0]\n";
        str += "    unencryptedMatrix[255][255]\n";
        str += "    for (i < cipher.length())\n";
        str += "        for (j < 1)\n";
        str += "            for(x < keyMatrix_size)\n";
        str += "                unencryptedMatrix[i][j] += reversedMatrix[row(0 - keyMatrix_size)][x] * cipherMatrix[i][j]\n";
        str += "            plainText += (char)\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        
        str += "\n";
        str += "\n";
        str += "\n";
        
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";
        str += "\n";

        return str;
    }

    /************************************************************
     * ENCRYPT
     * Returns a cipher text of the plainText using the password
     ************************************************************/
    virtual std::string encrypt(const std::string &plainText,
                                const std::string &password)
    {
        //initate matrix
        this->o_matrix = new float *[plainText.size()];
        for (int i = 0; i < plainText.length(); i++) {
            this->o_matrix[i] = new float[plainText.size()];
        }

        int position = 0;
        std::string cipherText = "";
        for (int i = 0; i < password.length(); i++) {
            for (int j = 0; j < plainText.length(); j++) {
                this->o_matrix[i][j] = password[position];
                position++;
                std::cout << " " << this->o_matrix[i][j] << " ";
            }
            std::cout << std::endl;
            if (position == password.length())
                break;
        }
        



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
        return plainText;
    }

    void generateMatrix(std::string password)
    {
       
    }
    void reverseMatrix()
    {
       
    }
};

#endif // HILLCIPHER_H