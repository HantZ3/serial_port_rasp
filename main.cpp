#include <iostream>
#include <string>
#include <stdlib.h>
#include "SerialPort.h"

char output[MAX_DATA_LENGTH];
char* port;
char incoming[MAX_DATA_LENGTH];


int main() {
	port = const_cast<char*>("\\\\.\\COM5"); // numéro du port // à changer pour linux
	//
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connexion est etablie" << '\n';
	}
	else {
		cout << "Une erreur est survenue";
	}
	while (arduino.isConnected()) {
		int nbr;
		string command;
		cin >> command;
		nbr = atoi(command.c_str()); // convertit command en int pour que nbr = command, pour pouvoir utiliser if
		int test;

		if (nbr == 1) {
			char* charArray = new char[command.size() + 1];
			copy(command.begin(), command.end(), charArray);
			charArray[command.size()] = '\n';

			arduino.readSerialPort(output, MAX_DATA_LENGTH);
			test = atoi(output);
			cout << output; // sort la valeur envoyé de l'arduino
			if (test == 1) {
				//system("wget http://xxxxxxxxx.alwaysdata.net/php/add.php");
				cout << "Le add est activé";
			}
			else if (test == 0) {
				// system("wget http://xxxxxxxxx.alwaysdata.net/php/remove.php");
				cout << "Le remove est activé";
			}

				
		}
	}
	return 0;
}
