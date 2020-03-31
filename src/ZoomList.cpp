/*
 * ZoomList.cpp
 *
 *  Created on: Mar 2, 2020
 *      Author: muskhan
 */

#include "ZoomList.h"
#include <utility>

using namespace std;

namespace caveofprogramming {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {
	// TODO Auto-generated constructor stub

}

void ZoomList::add(const Zoom& zoom){
	zooms.push_back(zoom);

	m_xCenter +=(zoom.x - m_width/2)* m_scale;
	m_yCenter +=(zoom.y - m_height/2)* m_scale;

	m_scale *= zoom.scale;



}

pair<double,double> ZoomList::doZoom(int x, int y){

	double xFractal = (x - m_width/2)*m_scale + m_xCenter;
	double yFractal = (x - m_height/2)*m_scale + m_yCenter;


	return pair<double,double>(xFractal,yFractal);



}



} /* namespace caveofprogramming */
