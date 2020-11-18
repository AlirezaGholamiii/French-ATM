#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

struct account
{
	string  NB;
	string Name;
	string Pin;
	float Balance;


};

void Displaytitle(string anytitle)
{
	cout << "\t\t";

	for (short i = 0; i < anytitle.length(); i++)
	{
		cout << (char)toupper(anytitle[i]);
	}

	cout << endl;
	cout << "\t\t";
	for (short i = 0; i < anytitle.length(); i++)
	{
		cout << "-";
	}
	cout << endl;
}

void Displaytitle2(string anytitle)
{
	cout << "\t";

	for (short i = 0; i < anytitle.length(); i++)
	{
		cout << anytitle[i];
	}

	cout << endl;
	cout << "\t";
	for (short i = 0; i < anytitle.length(); i++)
	{
		cout << "-";
	}
	cout << endl;
}



void ReadAllAcc(account ACC[])
{
	string line;
	float balance;
	ifstream F1("Info.txt");

	for (short i = 0; i < 3; i++)
	{
		getline(F1, line);
		ACC[i].NB = line;

		getline(F1, line);
		ACC[i].Name = line;

		getline(F1, line);
		ACC[i].Pin = line;

		getline(F1, line);
		balance = stof(line);
		ACC[i].Balance = balance;

	}
	F1.close();

}

string ReadPin(account INFO)
{
	string NIP;
	do
	{
		cout << "Entrez votre nip: ";
		cin >> NIP;
	} while (!(NIP == INFO.Pin));
	return NIP;
}
string ReadNb()
{
	string code;
	cout << "Entrez votre numero de compete: ";
	cin >> code;
	return code;
}

void DisplayList()
{
	cout << "Choisir votre transaction" << endl;
	cout << "\t1-Pour Deposer" << endl;
	cout << "\t2-Pour retirer" << endl;
	cout << "\t3-Pour Consulter" << endl;

}

short ChooseOne(short max, short min)
{
	short cho;
	do
	{
		cout << "Entrez votre cohix <1-3> :";
		cin >> cho;

	} while (cho > max || cho < min);

	return cho;
}

void DoTransaction(account INF, short CHO)
{
	float Depo;
	int Withdraw;
	int newblance;
	ofstream myfile;

	switch (CHO)
	{
	case 1:

		do
		{
			cout << "Combien voulez-vous deposer : $ ";
			cin >> Depo;
		} while (Depo < 2 || Depo>20000);

		cout << "\n--- la transaction a reussi---" << endl;

		cout << "\nLes infos de compte" << endl;
		cout << "\t\tNumero: " << INF.NB << endl;
		cout << "\t\tClient: " << INF.Name << endl;
		cout << "\t\tNip: " << INF.Pin << endl;
		newblance = INF.Balance + Depo;
		cout << "\t\tSolde $: " << fixed << setprecision(2) << newblance << endl;

		myfile.open("Info.txt", std::ios::app);
		if (INF.Balance != newblance)
		{

			myfile << endl << newblance << endl;
		}
		myfile.close();


		cout << "\nMerci d'avoir utiliser nos services" << endl;



		break;
	case 2:
		do
		{
			cout << "Entrez le montant a retirer $ : ";
			cin >> Withdraw;

		} while (Withdraw < 20 || Withdraw>500 || Withdraw % 20 != 0 || Withdraw > INF.Balance);
		cout << "\n--- la transaction a reussi---" << endl;

		cout << "\nLes infos de compte" << endl;
		cout << "\t\tNumero: " << INF.NB << endl;
		cout << "\t\tClient: " << INF.Name << endl;
		cout << "\t\tNip: " << INF.Pin << endl;
		newblance = INF.Balance - Withdraw;
		cout << "\t\tSolde $: " << fixed << setprecision(2) << newblance << endl;

		myfile.open("Info.txt", std::ios::app);
		if (INF.Balance != newblance)
		{

			myfile << endl << newblance << endl;
		}
		myfile.close();

		cout << "\nMerci d'avoir utiliser nos services" << endl;

		break;
	default:
		cout << "\n--- la transaction a reussi---" << endl;

		cout << "\nLes infos de compte" << endl;
		cout << "\t\tNumero: " << INF.NB << endl;
		cout << "\t\tClient: " << INF.Name << endl;
		cout << "\t\tNip: " << INF.Pin << endl;
		cout << "\t\tSolde $: " << fixed << setprecision(2) << INF.Balance << endl;
		cout << "\nMerci d'avoir utiliser nos services" << endl;
	}


}

account ReadOneAccInfo(account Ac[])
{
	short choice;
	account info;
	info.NB = ReadNb();
	for (short i = 0; i < 3; i++)
	{


		if (info.NB == Ac[i].NB)
		{
			cout << "\n\tBienvenue " << Ac[i].Name << "\n";
			info.Pin = Ac[i].Pin;
			info.Name = Ac[i].Name;
			info.Balance = Ac[i].Balance;

			ReadPin(info);

			DisplayList();

			choice = ChooseOne(3, 1);

			DoTransaction(info, choice);


		}



	}


	return info;

}


void ReadAllAccInfo(account ACC[])
{

	for (short i = 0; i < 3; i++)
	{
		ACC[i] = ReadOneAccInfo(ACC);
		break;
	}

}


//Thank you 
//Alireza Gholami