//
// Created by liu on 17-2-17.
//

#include <iostream> // Debug only
#include "Cipher.h"
#include "md5.h"

Cipher::Cipher()
{
    m_mode = MODE_ENCRYPT;
}

Cipher::Cipher(const Cipher &that)
{
    m_mode = that.m_mode;
    m_data = that.m_data;
    m_pos = that.m_pos;
    m_offset = that.m_offset;
}

Cipher::Cipher(const std::string &encrypted, const std::string &password)
{
    decrypt(encrypted, password);
}

u_int64_t Cipher::hashPassword(const std::string &password)
{
    MD5 md5(password);
    auto bytes = md5.digest();
    u_int64_t hash = bytes[0];
    for (int i = 1; i < 8; i++)
    {
        hash <<= 8;
        hash |= bytes[i];
    }
    return hash;
}

void Cipher::addInt8(int8_t data)
{
    _addInt(data, 8);
}

void Cipher::addInt16(int16_t data)
{
    _addInt(data, 16);
}

void Cipher::addInt32(int32_t data)
{
    _addInt(data, 32);
}

void Cipher::addInt64(int64_t data)
{
    _addInt(data, 64);
}

void Cipher::addInt128(int128_t data)
{
    _addInt(data, 128);
}

int8_t Cipher::getInt8()
{
    return (int8_t) _getInt(8);
}

int16_t Cipher::getInt16()
{
    return (int8_t) _getInt(16);
}

int32_t Cipher::getInt32()
{
    return (int8_t) _getInt(32);
}

int64_t Cipher::getInt64()
{
    return (int8_t) _getInt(64);
}

int128_t Cipher::getInt128()
{
    return (int8_t) _getInt(128);
}

std::string Cipher::encrpyt(const std::string &password)
{
    m_mode = MODE_ENCRYPT;
    std::vector<int64_t> data;
    // Encrypt here

    return base64_encode(data);
}

void Cipher::decrypt(const std::string &encrypted, const std::string &password)
{
    m_mode = MODE_DECRYPT;
    std::vector<int64_t> data = base64_decode(encrypted);
    // Decrypt here


}

std::string Cipher::base64_encode(const std::vector<int64_t> &data)
{

}

std::vector<int64_t> Cipher::base64_decode(const std::string &str)
{

}

void Cipher::_addInt(int128_t data, u_int8_t length)
{
    if (m_mode != MODE_ENCRYPT)return;
    // Add data here
}

int128_t Cipher::_getInt(u_int8_t length)
{
    if (m_mode != MODE_DECRYPT)return -1;
    // Get data here
}
