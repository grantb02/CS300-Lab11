/**
 * @file vigenere.h
 * @brief Header file for the Vigenere cipher class.
 *
 * This file defines the Vigenere class, which provides methods for encrypting
 * and decrypting messages using the Vigenere cipher algorithm. It also includes
 * utility methods to verify encrypted messages and set new keys.
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

/**
 * @class Vigenere
 * @brief A class for implementing the Vigenere cipher.
 *
 * The Vigenere class uses a plaintext key to encrypt and decrypt messages.
 * The key shifts each letter in the message forward or backward based on the
 * corresponding key character's position in the alphabet.
 */
class Vigenere {
public:
    /**
     * @brief Constructs a Vigenere cipher object.
     * @param key The encryption key, consisting of uppercase letters only.
     */
    explicit Vigenere(std::string key);

    /**
     * @brief Destructor for the Vigenere cipher class.
     */
    ~Vigenere();

    /**
     * @brief Encrypts a plaintext message using the Vigenere cipher.
     * @param msg The plaintext message to encrypt.
     * @return The encrypted ciphertext.
     */
    std::string encrypt(std::string msg);

    /**
     * @brief Decrypts a ciphertext message using the Vigenere cipher.
     * @param msg The encrypted message to decrypt.
     * @return The decrypted plaintext message.
     */
    std::string decrypt(std::string msg);

    /**
     * @brief Verifies if an encrypted message matches a plaintext message.
     * @param encryptedMsg The encrypted message.
     * @param decryptedMessage The plaintext message to verify against.
     * @return True if the encrypted message corresponds to the plaintext when decrypted, false otherwise.
     */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMessage);

    /**
     * @brief Sets a new encryption key for the Vigenere cipher.
     * @param newKey The new key, consisting of uppercase letters only.
     */
    void setKey(std::string newKey);

private:
    /**
     * @brief The encryption key used for the Vigenere cipher.
     */
    std::string key;

    /**
     * @brief Shifts a character forward by a given number of positions.
     * @param ch The character to shift.
     * @param n The number of positions to shift.
     * @return The shifted character.
     */
    char shiftForward(char ch, int n);

    /**
     * @brief Shifts a character backward by a given number of positions.
     * @param ch The character to shift.
     * @param n The number of positions to shift backward.
     * @return The shifted character.
     */
    char shiftBackward(char ch, int n);
};

#endif // VIGENERE_H