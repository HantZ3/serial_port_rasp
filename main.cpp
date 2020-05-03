#include <iostream>
using namespace std;
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
		cout << "Ecrire le chiffre qui correspond a votre demande" << '\n' << '\n';
		cout << "[1] Faire rentrer une personne" << '\n';
		cout << "[2] Faire sortir une personne" << '\n';
	}
	else {
		cout << "Une erreur est survenue";
	}
	while (arduino.isConnected()) {
		int nbr;
		string command;
		cin >> command;
		nbr = atoi(command.c_str()); // convertit command en int pour que nbr = command, pour pouvoir utiliser if
		

		if (nbr == 1) {
			char* charArray = new char[command.size() + 1];
			copy(command.begin(), command.end(), charArray);
			charArray[command.size()] = '\n';

			arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
			arduino.readSerialPort(output, MAX_DATA_LENGTH);

			 cout << output; // sort la valeur envoyé de l'arduino
			 system("wget http://xxxxxxxxx.alwaysdata.net/php/add.php");

			delete[]charArray;
		}
		else if (nbr == 2) {
			char* charArray = new char[command.size() + 1];
			copy(command.begin(), command.end(), charArray);
			charArray[command.size()] = '\n';

			arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
			arduino.readSerialPort(output, MAX_DATA_LENGTH);

			cout << output; // sort la valeur envoyé de l'arduino
			system("wget http://xxxxxxxx.alwaysdata.net/php/remove.php");

			delete[]charArray;
		}
		else 
		{
			cout << "Erreur lors de la saisie" << '\n';
		}
	}
	return 0;
}
