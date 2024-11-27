#include "vigenere.h"
#include <cctype>

/**
 * @brief Constructs a Vigenere cipher object with the provided key.
 * @param key The encryption key, consisting of uppercase letters only.
 */
Vigenere::Vigenere(std::string key) {
    this->key = key;
}

/**
 * @brief Destructor for the Vigenere cipher class.
 */
Vigenere::~Vigenere() {}

/**
 * @brief Shifts a character forward by a given number of positions.
 * @param ch The character to shift.
 * @param n The number of positions to shift.
 * @return The shifted character.
 */
char Vigenere::shiftForward(char ch, int n) {
    return 'A' + (ch - 'A' + n) % 26;
}

/**
 * @brief Shifts a character backward by a given number of positions.
 * @param ch The character to shift.
 * @param n The number of positions to shift backward.
 * @return The shifted character.
 */
char Vigenere::shiftBackward(char ch, int n) {
    return 'A' + (ch - 'A' - n + 26) % 26;
}

/**
 * @brief Encrypts a plaintext message using the Vigenere cipher.
 * @param msg The plaintext message to encrypt.
 * @return The encrypted ciphertext.
 */
std::string Vigenere::encrypt(std::string msg) {
    std::string encrypted;
    int keyLength = key.length();

    for (size_t i = 0; i < msg.length(); ++i) {
        if (std::isalpha(msg[i])) {
            int shift = key[i % keyLength] - 'A'; // Calculate shift based on key
            encrypted += shiftForward(msg[i], shift);
        } else {
            encrypted += msg[i]; // Keep non-alphabetic characters unchanged
        }
    }
    return encrypted;
}

/**
 * @brief Decrypts a ciphertext message using the Vigenere cipher.
 * @param msg The encrypted message to decrypt.
 * @return The decrypted plaintext message.
 */
std::string Vigenere::decrypt(std::string msg) {
    std::string decrypted;
    int keyLength = key.length();

    for (size_t i = 0; i < msg.length(); ++i) {
        if (std::isalpha(msg[i])) {
            int shift = key[i % keyLength] - 'A'; // Calculate shift based on key
            decrypted += shiftBackward(msg[i], shift);
        } else {
            decrypted += msg[i]; // Keep non-alphabetic characters unchanged
        }
    }
    return decrypted;
}

/**
 * @brief Verifies whether an encrypted message matches a plaintext message.
 * @param encryptedMsg The encrypted message to check.
 * @param decryptedMessage The plaintext message to verify against.
 * @return True if the encrypted message corresponds to the plaintext when decrypted.
 */
bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMessage) {
    return encryptedMsg == encrypt(decryptedMessage);
}

/**
 * @brief Sets a new encryption key for the Vigenere cipher.
 * @param newKey The new encryption key, consisting of uppercase letters only.
 */
void Vigenere::setKey(std::string newKey) {
    this->key = newKey;
}