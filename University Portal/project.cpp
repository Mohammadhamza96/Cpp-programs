#include "stupor.h"

main () {
	int pin;
	int roll;
	
	cout << "Roll Number: "; cin >> roll;
	cout << "Password: "; cin >> pin;
	if (pin==12345678) {
		display ();
	} else {
		cout << "Wrong Password!" << endl;
	}
}
