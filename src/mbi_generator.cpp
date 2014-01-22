//============================================================================
// Name        : mbi_generator.cpp
// Author      : lmetrak
// Version     :
// Copyright   : Your copyright notice
// Description : main
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include "generator/generator.h"


using namespace std;

extern bool loadArguments(int argc, char *argv[], char **pathElement, char ** pathSubelements);

int maxRand, minRand, maxRandElemenst, minRandElements;
double density;



int main(int argc, char *argv[]) {


	char *path = NULL;
	char *pathS = NULL;

	if( loadArguments(argc, argv, &path, &pathS) ) {

		srand(time(NULL));
		generate(&path, &pathS);
		return 0;
	}



	return 1;
}


bool loadArguments(int argc, char *argv[], char **pathElement, char **pathSubelements) {




	if(argc == 1 ) {

			minRandElements = 50;
			maxRandElemenst = minRandElements + 100;

			minRand = 25;
			maxRand = 100;

			density = 15.0;

			*pathElement = "plik_lancuch.txt";
			*pathSubelements = "plik_sublancuch.txt";

			return true;

	}
	else if(argc >=2) {


		if(argc == 2) {

			std::string help = argv[1];

			if(help == "-h" || help == "--help") {

				cout << "wywolanie generatora lancucha DNA" << std::endl;
				cout << "przyklad wywowlania" << std::endl;
				cout << "$ generator" << std::endl;
				cout << "pirwszy argument 	- minimalna dlugosc lancucha" << std::endl;
				cout << "drugi argument 	- maksymalna dlugosc lancucha" << std::endl;
				cout << "trzeci argument 	- minimalna ilosc podslow" << std::endl;
				cout << "czwarty argument 	- maksymalna ilosc podslow" << std::endl;
				cout << "piaty argument 	- zageszczenie podslow" << std::endl;
				cout << "szosty argument  	- nazwa pliku zawierającego lancuch" << std::endl;
				cout << "siodmy argument  	- nazwa pliku zawierającego podlancuchy" << std::endl;

				return false;
			}
			else {

				minRandElements = atoi(argv[1]);
				maxRandElemenst = minRandElements + 100;

				minRand = 50;
				maxRand = 100;

				density = 15;

				*pathElement = "plikt_gen.txt";
				*pathSubelements = "plik_sublancuch.txt";

				return true;

			}


		}
		else if(argc == 3) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = 50;
			maxRand = 100;

			density = 15;

			*pathElement = "plikt_gen.txt";
			*pathSubelements = "plik_sublancuch.txt";

			if(minRandElements <= maxRandElemenst)
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}
		else if(argc == 4) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = atoi(argv[3]);
			maxRand = minRand + 50;

			density = 15;

			*pathElement = "plikt_gen.txt";
			*pathSubelements = "plik_sublancuch.txt";

			if(minRandElements <= maxRandElemenst)
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}
		else if(argc == 5) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = atoi(argv[3]);
			maxRand = atoi(argv[4]);

			density = 15;

			*pathElement = "plikt_gen.txt";
			*pathSubelements = "plik_sublancuch.txt";

			if(minRandElements <= maxRandElemenst && minRand <= maxRand )
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}

		else if(argc == 6) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = atoi(argv[3]);
			maxRand = atoi(argv[4]);

			density = atoi(argv[5]);

			*pathElement = "plikt_gen.txt";
			*pathSubelements = "plik_sublancuch.txt";

			if(minRandElements <= maxRandElemenst && minRand <= maxRand )
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}

		else if(argc == 7) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);


			minRand = atoi(argv[3]);
			maxRand = atoi(argv[4]);


			density = atoi(argv[5]);

			*pathElement = argv[6];
			*pathSubelements = "plik_sublancuch.txt";

			if(minRandElements <= maxRandElemenst && minRand <= maxRand )
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}
		else if(argc == 8) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = atoi(argv[3]);
			maxRand = atoi(argv[4]);

			density = atoi(argv[5]);

			*pathElement = argv[6];
			*pathSubelements = argv[7];

			if(minRandElements <= maxRandElemenst && minRand <= maxRand )
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}
	}
	else {
			cout << "blad, zle argumenty" << std::endl;
			return false;
	}

	return false;

}

