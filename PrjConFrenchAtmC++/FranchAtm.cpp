#include<iostream>
#include<string>
#include"AtmHeader.h"
#include<fstream>

using namespace std;

void main()
{
	
	account Acc[3];

	//title
	Displaytitle("BANQUE ROYALE");
	Displaytitle2("Guichet Automatique Bancaire");
	
	
	ReadAllAcc(Acc);
	
	ReadAllAccInfo(Acc);





	system("pause");




}

//Thank you
//Alireza Gholami