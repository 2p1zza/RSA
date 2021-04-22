#pragma once

#include "BigInteger.h"
#include <iostream>
using namespace std;
class User
{
public:
	User();

private:
	BigInteger publicKey;
	BigInteger privateKey;
	BigInteger N;

public:
	void getKeys();

	BigInteger getPublicKey();
	BigInteger getN();

	void setPublicKey(BigInteger publicKey);
	void setPrivateKey(BigInteger privateKey);
	void setN(BigInteger N);

	string encode(string strToEncode, BigInteger publicKey1, BigInteger N1);
	string decode(string strToDecode);

	BigInteger encryptChar(char character, BigInteger publicKey1, BigInteger N1);
	BigInteger decryptChar(BigInteger character);
};

