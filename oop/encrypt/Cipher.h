//
// Created by liu on 17-2-17.
//

#pragma once

#include <string>
#include <vector>
#include <stdint.h>

typedef __int128 int128_t;

class Cipher
{
public:
    // Default Constructor
    Cipher();

    // Copy Constructor
    Cipher(const Cipher &that);

    // Constructor from a encrypted string and a password
    Cipher(const std::string &encrypted, const std::string &password);

    static uint64_t hashPassword(const std::string &password);

    void addInt8(int8_t data);

    void addInt16(int16_t data);

    void addInt32(int32_t data);

    void addInt64(int64_t data);

    void addInt128(int128_t data);

    int8_t getInt8();

    int16_t getInt16();

    int32_t getInt32();

    int64_t getInt64();

    int128_t getInt128();

    std::string encrpyt(const std::string &password);

    void decrypt(const std::string &encrypted, const std::string &password);

    static std::string base64_encode(const std::vector<int64_t> &data);

    static std::vector<int64_t> base64_decode(const std::string &str);

protected:
    static const char BASE64_SYMBOLS[65];

    enum MODE
    {
        MODE_ENCRYPT, MODE_DECRYPT
    };

    std::vector<int64_t> m_data;
    MODE m_mode;

    // The position of current
    uint64_t m_pos = 0;

    // Can only be 0,1,2,3
    uint8_t m_offset = 0;

    void _addInt(int128_t data, uint8_t length = 8);

    int128_t _getInt(uint8_t length = 8);
};


