//============================================================================
// Name        : mbi_generator.cpp
// Author      : lmetrak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "generator/generator.h"


using namespace std;

extern bool loadArguments(int argc, char *argv[], char **path);

int maxRand, minRand, maxRandElemenst, minRandElements;
double density;



int main(int argc, char *argv[]) {


	char *path = NULL;

	if( loadArguments(argc, argv, &path) ) {

		srand(time(NULL));
		generate(&path);
		return 0;
	}



	return 1;
}


bool loadArguments(int argc, char *argv[], char **path) {


	if(argc <= 1) {
		cout << "wywolanie generatora z niepoprawnymi flagami" << std::endl;
		cout << "przyklad wywowlania" << std::endl;
		cout << "$ generator" << std::endl;
		cout << "pirwszy argument 	- minimalna dlugosc lancucha" << std::endl;
		cout << "drugi argument 	- maksymalna dlugosc lancucha" << std::endl;
		cout << "trzeci argument 	- minimalna ilosc podslow" << std::endl;
		cout << "czwarty argument 	- maksymalna ilosc podslow" << std::endl;
		cout << "piaty argument 	- zageszczenie podslow" << std::endl;
		cout << "szosty argument  	- nazwa pliku zawierającego lancuch, podlancuchy" << std::endl;
		return false;
	}
	else if(argc == 2) {

		minRandElements = 10;
		maxRandElemenst = minRandElements + 100;

		minRand = 20;
		maxRand = 100;

		*path = "plikt_gen.txt";

		return true;
	}
	else if(argc >=3) {


		if(argc == 3) {

			minRandElements = atoi(argv[1]);
			maxRandElemenst = minRandElements + 100;

			minRand = 50;
			maxRand = 100;

			density = 1000.0;

			*path = "plikt_gen.txt";

			return true;
		}
		else if(argc == 4) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = 50;
			maxRand = 100;

			density = 1000.0;

			*path = "plikt_gen.txt";

			if(minRandElements <= maxRandElemenst)
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}
		else if(argc == 5) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = atoi(argv[3]);
			maxRand = minRand + 50;

			density = 1000.0;

			*path = "plikt_gen.txt";

			if(minRandElements <= maxRandElemenst)
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}
		else if(argc == 6) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			minRand = atoi(argv[3]);
			maxRand = atoi(argv[4]);

			density = 1000.0;

			*path = "plikt_gen.txt";

			if(minRandElements <= maxRandElemenst && minRand <= maxRand )
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}

		else if(argc == 7) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			maxRand = atoi(argv[3]);
			minRand = atoi(argv[4]);

			density = atoi(argv[5]);

			*path = "plikt_gen.txt";

			if(minRandElements <= maxRandElemenst && minRand <= maxRand )
				return true;

			cout << "odwrocone wartosci min max" << std::endl;
			return false;

		}

		else if(argc == 8) {
			minRandElements = atoi(argv[1]);
			maxRandElemenst = atoi(argv[2]);

			maxRand = atoi(argv[3]);
			minRand = atoi(argv[4]);

			density = atoi(argv[5]);

			*path = argv[6];

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

