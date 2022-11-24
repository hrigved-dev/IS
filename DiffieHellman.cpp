#include <cmath>
#include <iostream>
using namespace std;

// Power function to return value of Xa ^ Xb mod q
long long int power(long long int Xa, long long int Xb,
                    long long int q)
{
    if (Xb == 1)
        return Xa;

    else
        return (((long long int)pow(Xa, Xb)) % q);
}

// Driver program
int main()
{
    long long int q, alpha, Ya, Xa, Yb, Xb, ka, kb;

    // Both the persons will be agreed upon the
    // public keys alpha and q
    q = 23; // A prime number q is taken
    cout << "The value of q : " << q << endl;

    alpha = 9; // A primitive root for q, alpha is taken
    cout << "The value of alpha : " << alpha << endl;

    // Alice will choose the private key Xa
    Xa = 4; // Xa is the chosen private key
    cout << "The private key Xa for Alice : " << Xa << endl;

    Ya = power(alpha, Xa, q); // gets the generated key

    // Bob will choose the private key Xb
    Xb = 3; // Xb is the chosen private key
    cout << "The private key Xb for Bob : " << Xb << endl;

    Yb = power(alpha, Xb, q); // gets the generated key

    // Generating the secret key after the exchange
    // of keys
    ka = power(Yb, Xa, q); // Secret key for Alice
    kb = power(Ya, Xb, q); // Secret key for Bob
    cout << "Secret key for the Alice is : " << ka << endl;

    cout << "Secret key for the Alice is : " << kb << endl;

    return 0;
}