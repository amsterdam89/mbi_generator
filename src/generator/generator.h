/*
 * generator.h
 *
 *  Created on: Jan 17, 2014
 *      Author: amsterdam
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <iostream>

#include <iostream>
#include <fstream>

#include <cstdlib>
#include <list>

using namespace std;

extern int maxRand, minRand, maxRandElemenst, minRandElements;
extern double density;




void generate(char **path);

char getElement(int rand);

bool cointinueCut(int x, double _rand);
void _randCalyPodlancuch(int _randCentralElement, int numberOfElements, int **tableOfElements, ofstream *myfile);

bool cointinueCutLinear(int x, double _rand);

bool cointinueCut_x2(int x, double _rand);

#endif /* GENERATOR_H_ */
