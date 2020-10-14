#pragma once

#include <string>
#include <vector>

#include "Pixel.h"
#include "Serial.h"

class ArduinoSerial
{
public:
	ArduinoSerial(const std::string & communicationPort);

	void send(const std::vector<Pixel> & data) const;

private:
	const Serial serial;

};
