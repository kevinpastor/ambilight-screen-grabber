#pragma once

#include <windows.h>
#include <Wincodec.h>
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#include <vector>
#include <iostream>

#include "Coordinates.h"
#include "Pixel.h"

class ScreenCapture
{
public:
	ScreenCapture();
	~ScreenCapture();

	void capture();
	const Pixel getPixel(const Coordinates & coordinates);
	const unsigned getScreenHeight();
	const unsigned getScreenWidth();
	const bool isValidXPosition(const unsigned & x);
	const bool isValidYPosition(const unsigned & y);

private:
	const bool isValidPosition(const Coordinates & coordinates);
	void setScreenSize();
	const HDC getHDC();
	const BITMAPINFOHEADER getBmpInfoHeader();

	unsigned char * screenCaptureData;
	unsigned screenHeight;
	unsigned screenWidth;

};