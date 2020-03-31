/*
 * FractalCreator.h
 *
 *  Created on: Mar 3, 2020
 *      Author: muskhan
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"

using namespace std;

namespace caveofprogramming {

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(string name);
};

} /* namespace caveofprogramming */

#endif /* FRACTALCREATOR_H_ */
