#include <iostream>
#include <time.h>
#include "BigInteger.h"
#include "User.h"
#include "KeyGenerator.h"

using namespace std;

int main()
{
	srand(time(NULL));

	User user1 = User();
	User user2 = User();

	KeyGenerator generator1 = KeyGenerator(user1);
	KeyGenerator generator2 = KeyGenerator(user2);


	string encoded = user1.encode("ABC", user2.getPublicKey(), user2.getN());
	string decoded = user2.decode(encoded);

	cout << "user1" << endl;
	user1.getKeys();
	cout << "user2" << endl;
	user2.getKeys();
	cout << "Encoded:" << encoded << endl;
	cout << "Decoded:" << decoded << endl;
}
