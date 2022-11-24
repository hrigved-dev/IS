#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char message[100];
    cout<<"Enter the message:\n ";
    cin.getline(message,100);

    int i, j, length, choice, key;
    key = 3; // Since it is Caesar Cipher

    length = strlen(message);

    while(1) {
        cout<<"Enter your choice: \n1.Encryption \n2. Decryption \n3. Exit \n";
        cin>>choice;

        if(choice == 1) {
            char ch;
            for(i=0; message[i] != '\0'; i++) {
                ch = message[i];
                if(ch >= 'a' && ch <= 'z') {
                    ch = ch + key;
                    if(ch > 'z') {
                        ch = ch - 'z' + 'a' - 1;
                    }
                    message[i] = ch;
                }

                else if(ch >= 'A' && ch <= 'Z') {
                    ch = ch + key;
                    if (ch > 'Z') {
                        ch = ch - 'Z' + 'A' - 1;
                    }
                    message[i] = ch;
                }
            }
            cout<<"Encrypted message: "<<message<<endl;
        }
        else if(choice == 2) {
            char ch;
            for(i=0; message[i] != '\0'; i++) {
                ch = message[i];
                if(ch >= 'a' && ch <= 'z') {
                    ch = ch - key;
                    if(ch < 'a') {
                        ch = ch + 'z' - 'a' + 1;
                    }
                    message[i] = ch;
                }

                else if(ch >= 'A' && ch <= 'Z') {
                    ch = ch - key;
                    if (ch < 'A') {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                    message[i] = ch;
                }
            }
            cout<<"Decrypted message: "<<message<<endl;
        }
        else if(choice == 3) {
            break;
        }
        else {
            cout<<"Enter a valid input";
        }
    }
    return 0;
}
