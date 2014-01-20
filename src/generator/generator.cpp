/*
 * generator.cpp
 *
 *  Created on: Jan 17, 2014
 *      Author: amsterdam
 */

#include "generator.h"


void generate(char **path) {


	int *tableOfElements;
	int _rand;
	ofstream myfile;


	int numberOfElements = rand() % maxRandElemenst + minRandElements;
	int numberOfSubelements = rand() % maxRand + minRand;

	tableOfElements = new int[numberOfElements];
	myfile.open(*path);

	for(int i = 0; i < numberOfElements; i++) {
		_rand = rand() % 4;
		tableOfElements[i] = _rand;

		myfile << getElement(_rand);
	}



	myfile << std::endl;



	for(int i = 0, _randCentralElement; i < numberOfSubelements; i++) {
		_randCentralElement = rand() % numberOfElements;
		_randCalyPodlancuch(_randCentralElement, numberOfElements, &tableOfElements, &myfile);

	}

	myfile.close();

	delete tableOfElements;

}


char getElement(int rand) {


	if(rand == 0)
		return 'A';

	else if(rand == 1)
		return 'C';

	else if(rand == 2)
		return 'G';

	else
		return 'T';

}

void _randCalyPodlancuch(int _randCentralElement, int numberOfElements, int **tableOfElements, ofstream *myfile) {

	int firstElement = _randCentralElement, lastElement = _randCentralElement;
	double _rand;
	std::list<int> subElement;
	subElement.push_front((*tableOfElements)[_randCentralElement]);

	bool flag = true;
	int goLeftOrRight;
	int x = 1;

	bool ( *cointinue ) ( int a, double b) = cointinueCutLinear; //cointinueCut_x2 ;


	do {

		_rand = (double) rand() / RAND_MAX;

		if( cointinue(x, _rand) ) {

			if(firstElement > 0 && lastElement < (numberOfElements - 1) ) {

				goLeftOrRight = rand() % 2;

				if(!goLeftOrRight) //idziemy w lewo
					subElement.push_front((*tableOfElements)[--firstElement]);

				else
					subElement.push_back((*tableOfElements)[++lastElement]);
			}
			else {
				if(firstElement > 0) // idzemy w lew
					subElement.push_front((*tableOfElements)[--firstElement]);

				else if(lastElement < (numberOfElements - 1) )
					subElement.push_back((*tableOfElements)[++lastElement]);

				else
					flag = false;

			}


		}
		else {
			flag = false;
		}


		x++;
	} while(flag);



	  for (std::list<int>::iterator it = subElement.begin(); it != subElement.end(); it++)
		  (*myfile) << getElement(*it);


	  (*myfile) << std::endl;



}

bool cointinueCutLinear(int x, double _rand) {

	// f liniowa decydujaca o wycinaniu lancucha

	double a = density;
	double f = -x/a + 1/a + 1.0;

	if(f >= _rand)
		return true;

	return false;

}

bool cointinueCut_x2(int x, double _rand) {

	// f kwadratowa decydujaca o wycinaniu lancucha

	double minus = -1.0;
	double a = density;
	a = (1.0 / a) * minus;
	double b = - 2 * a;
	double c = (b * b) / (4 * a) + 1;

	double f = a*x*x + b*x + c;

	if(f >= _rand)
		return true;

	return false;

}

