#include "User.h"

User::User() {
	publicKey = BigInteger();
	privateKey = BigInteger();
	N = BigInteger();
}

BigInteger User::getPublicKey()
{
	return User::publicKey;
}

BigInteger User::getN()
{
	return User::N;
}

void User::getKeys() {
	cout << "privateKey=" << privateKey.getNumber() << endl;
	cout << "publicKey=" << publicKey.getNumber() << endl;
	cout << "N=" << N.getNumber() << endl;
}

void User::setPublicKey(BigInteger publicKey)
{
	User::publicKey = publicKey;
}

void User::setPrivateKey(BigInteger privateKey)
{
	User::privateKey = privateKey;
}

void User::setN(BigInteger N)
{
	User::N = N;
}

string User::encode(string strToEncode, BigInteger publicKey1, BigInteger N1)
{
	string encodedString = "";

	for (int i = 0; i < strToEncode.length(); i++) {
		BigInteger number = encryptChar(strToEncode[i], publicKey1, N1);

		encodedString.append(number.getNumber());
		encodedString += " ";
	}

	return encodedString;
}

BigInteger User::encryptChar(char character, BigInteger publicKey1, BigInteger N1) //ρθμβ
{
	BigInteger charPos = BigInteger((character - 64));
	BigInteger current = BigInteger(charPos.getNumber());
	BigInteger i = BigInteger(1);

	for (i; i < publicKey1; i++) {
		current *= charPos;
	}

	BigInteger ost = current % N1;
	return ost;
}

string User::decode(string strToDecode)
{
	string decoded = "";

	size_t pos = 0;
	string token;
	string delimetre = " ";

	while ((pos = strToDecode.find(delimetre)) != std::string::npos) {
		token = strToDecode.substr(0, pos);
		BigInteger character = BigInteger(token);
		BigInteger decryptedChar = decryptChar(character);

		decoded += (char)atoi(decryptedChar.getNumber().c_str());

		strToDecode.erase(0, pos + delimetre.length());
	}

	return decoded;
}

BigInteger User::decryptChar(BigInteger character)
{
	BigInteger current = BigInteger(character);
	BigInteger i = BigInteger(1);

	for (i; i < privateKey; i++) {
		current *= character;
	}

	BigInteger ost = (current % N) + 64;

	return ost;
}