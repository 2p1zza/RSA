#include "KeyGenerator.h"

KeyGenerator::KeyGenerator(User& user)
{
	n = BigInteger(createN()); //������������ ������� �����
	d = BigInteger(createD()); //�������� ������� ������
	s = BigInteger(createS()); 
	e = BigInteger(createE(s, d));

	/*
	cout << "p = " << p.getNumber()
		 << " q = "<< q.getNumber()
		 << " N = "<< n.getNumber()
		 << " d = "<< d.getNumber()
		 << " s = "<< s.getNumber()
		 << " e = "<< e.getNumber()
		 << endl;
	*/

	user.setPublicKey(s);
	user.setPrivateKey(e);
	user.setN(n);
}

BigInteger KeyGenerator::createN()
{
	p = BigInteger(createPrime());
	q = BigInteger(createPrime());

	return p * q;
}

BigInteger KeyGenerator::createPrime() //������� �����
{
	BigInteger number = BigInteger(rand() % 100 + 2);

	while (!checkForPrime(number)) {
		number = rand() % 100 + 2;
	}

	return number;
}

bool KeyGenerator::checkForPrime(BigInteger number) //�������� �� ��������
{
	bool isPrime = true;
	if (number == 0 || number == 1) {
		isPrime = false;
	}
	else {
		for (BigInteger i = 2; i <= number / 2; ++i) {
			if (number % i == 0) {
				isPrime = false;
				break;
			}
		}
	}
	return isPrime;
}

BigInteger KeyGenerator::createD()
{
	return (p - 1) * (q - 1);
}

BigInteger KeyGenerator::createS()
{
	BigInteger number = BigInteger(rand() % 100 + 2);

	while (!checkCoPrime(number, KeyGenerator::d) || s > d) {
		number = rand() % 100 + 2;
	}
	return number;
}

bool KeyGenerator::checkCoPrime(BigInteger a, BigInteger b) //�������� ���� �����: ������� ������� ����� ��� ���
{
	return gcd(a, b) == 1;
}

BigInteger KeyGenerator::gcd(BigInteger a, BigInteger b) //����� ���
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

BigInteger KeyGenerator::createE(BigInteger s, BigInteger d)
{
	BigInteger e;
	BigInteger k = 1;

	while (true) {
		k = k + d;

		if (k % s == 0) {
			e = (k / s);
			return e;
		}
	}
}