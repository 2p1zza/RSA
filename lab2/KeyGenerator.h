#pragma once
#include <iostream>
#include "BigInteger.h"
#include "User.h"
using namespace std;
class KeyGenerator
{
public:
	KeyGenerator(User& user);

private:
	BigInteger p;
	BigInteger q;
	BigInteger n;
	BigInteger d;
	BigInteger s;
	BigInteger e;

private:
	BigInteger createN();
	BigInteger createPrime();
	bool checkForPrime(BigInteger number);

	BigInteger createD();
	BigInteger createS();
	bool checkCoPrime(BigInteger a, BigInteger b);
	BigInteger gcd(BigInteger a, BigInteger b);

	BigInteger createE(BigInteger s, BigInteger d);

};

