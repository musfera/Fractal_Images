/*
 * BitmapFIleHeader.h
 *
 *  Created on: Feb 25, 2020
 *      Author: muskhan
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)
//2 byte boundaries

namespace caveofprogramming{

struct BitmapFileHeader{
	char header[2]{'B', 'M'};
	int32_t fileSize;
	int32_t reserved{0};
	int32_t dataOffset;
};


}


#endif /* BITMAPFILEHEADER_H_ */
