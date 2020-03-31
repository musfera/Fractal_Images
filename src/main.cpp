//============================================================================
// Name        : BitmapHeaderValues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
#include <memory>
#include <cmath>

#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"


using namespace std;
using namespace caveofprogramming;

int main() {
	RGB rgb1(4, 5, 6);
	RBG rgb2(1, 2, 3);

	RGB rgb3 = rgb1 - rgb2;

	cout << rgb.r << ", " << rgb.g << " ," << rgb.b <<  endl;

	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH,HEIGHT);

	//bitmap.setPixel(WIDTH/2, 100, 255, 255, 255);

	double min = 999999;
	double max = -999999;

	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 1.0/WIDTH));

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{0});


	for (int y =0; y <HEIGHT; y++){
		for (int x =0; x <WIDTH; x++){
			pair <double, double> coords = zoomList.doZoom(x,y);

			//double xFractal = (x - WIDTH/2 - 200) * 2.0/WIDTH;
			//double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			fractal[y*WIDTH+x] = iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS){
			histogram[iterations]++;
			}


		}
	}

	int total =0;
	for(int i=0; i< Mandelbrot::MAX_ITERATIONS;i++){
		total += histogram[i];

	}

	for (int y =0; y <HEIGHT; y++){
		for (int x =0; x <WIDTH; x++){

			uint8_t red =0;
			uint8_t green =0;
			uint8_t blue =0;

				int iterations = fractal[y*WIDTH+x];

				//uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

				if(iterations != Mandelbrot::MAX_ITERATIONS){

					double hue = 0.0;

					for(int i=0; i <= iterations; i++){
						hue += ((double)histogram[i])/total;
					}


					green =hue * 255;
				}



				bitmap.setPixel(x, y, red, green, blue);



			}
	}



	/*
	cout << endl;

	int count =0;

	for(int i =0; i < Mandelbrot::MAX_ITERATIONS; i++){
		cout << histogram[i] << " " << flush;
		count += histogram[i];
	}
	cout << count << "; " << WIDTH*HEIGHT << endl;

	cout << endl;

	cout << min << ", " << max << endl;
	*/

	bitmap.write("test.bmp");


	cout << "finished" << endl; // prints !!!Hello World!!!
	return 0;
}
