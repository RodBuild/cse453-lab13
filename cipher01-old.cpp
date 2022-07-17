
#include<iostream>
using namespace std;
 
// Function to extend the key to the length of plaintext
string get_full_key(string pt, string k){
    // Increase the size of the key so it matches the lenght of the plaintext
    // we use the same key over and over.
    if(k.size() >= pt.size())
        return k;
    else{
        int psize = pt.size()-k.size();
        int ksize = k.size(); 
        while(psize >= ksize){
            k += k;
            psize -= ksize;
        }
 
        k += k.substr(0, psize);
        return k;
    }
}
 
// Encryption Function
string get_encryption(string pt, string k){
 
    string ct = "";
    //95 for all symbols
    //26 before
    for(int i=0;i<pt.size();i++)
        ct += (char) (((int)pt[i]-' ' + (int)k[i]-' ') % 95) + ' ';
 
    return ct;
}
 
// Decryption Function
string get_decryption(string ct, string k){
 
    string pt = "";
    for(int i=0;i<ct.size();i++)
        pt += (char) ((((int)ct[i]- ' ' - (k[i] -' ')) + 95) % 95) + ' ';
 
    return pt;
}
 
int main(){
 
    // The Plaintext
    string plaintext = "Testing1234567890";
 
    // The key
    string key = "BEST";
 
    // Function call to extend the key size
    key = get_full_key(plaintext, key);
 
    cout<<" THE PLAINTEXT: "<< plaintext <<endl;
 
    cout<<" THE KEY: "<< key <<endl;
 
    // Function call to encode the data
    string ciphertext = get_encryption(plaintext, key);
 
    cout<<" THE CIPHERTEXT: "<< ciphertext <<endl;
 
    // Function call to decode the data
    plaintext = get_decryption(ciphertext, key);
 
    cout<<" THE DECODED PLAINTEXT: "<< plaintext <<endl;
 
    return 1;
}