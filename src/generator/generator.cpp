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
	int liczbaPodlancuchow = rand() % maxRand + minRand;

	tableOfElements = new int[numberOfElements];
	myfile.open(*path);

	for(int i = 0; i < numberOfElements; i++) {
		_rand = rand() % 4;
		tableOfElements[i] = _rand;

		myfile << getElement(_rand);
	}



	  myfile << std::endl;



	for(int i = 0, _randCentralElement; i < liczbaPodlancuchow; i++) {
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
	std::list<int> podlancuch;
	podlancuch.push_front((*tableOfElements)[_randCentralElement]);

	bool flag = true;
	int goLeftOrRight;
	int x = 1;

	do {

		_rand = (double) rand() / RAND_MAX;

		if( cointinueCutLancuch(x, _rand) ) {

			if(firstElement > 0 && lastElement < (numberOfElements - 1) ) {

				goLeftOrRight = rand() % 2;

				if(!goLeftOrRight) //idziemy w lewo
					podlancuch.push_front((*tableOfElements)[--firstElement]);

				else
					podlancuch.push_back((*tableOfElements)[++lastElement]);
			}
			else {
				if(firstElement > 0) // idzemy w lew
					podlancuch.push_front((*tableOfElements)[--firstElement]);

				else if(lastElement < (numberOfElements - 1) )
					podlancuch.push_back((*tableOfElements)[++lastElement]);

				else
					flag = false;

			}


		}
		else {
			flag = false;
		}


		x++;
	} while(flag);



	  for (std::list<int>::iterator it = podlancuch.begin(); it != podlancuch.end(); it++)
		  (*myfile) << getElement(*it);


	  (*myfile) << std::endl;


}

bool cointinueCutLancuch(int x, double _rand) {
	double a = 100.0;
	double f = -x/a + 1/a + 1.0;

	if(f >= _rand)
		return true;

	return false;

}
