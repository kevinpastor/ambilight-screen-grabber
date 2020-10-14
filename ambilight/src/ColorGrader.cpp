#include "ColorGrader.h"

ColorGrader::ColorGrader(const unsigned & monitorBrightness)
	: LUTIndex(monitorBrightness > ColorGrader::DIMMED_BRIGHTNESS_LIMIT ? 0 : 1)
{
}

Pixel ColorGrader::correct(const Pixel & pixel) const
{
	return Pixel({
		ColorGrader::LUTs[this->LUTIndex][pixel.red].red,
		ColorGrader::LUTs[this->LUTIndex][pixel.green].green,
		ColorGrader::LUTs[this->LUTIndex][pixel.blue].blue
		});
}

std::vector<Pixel> ColorGrader::correct(const std::vector<Pixel> & pixels) const
{
	std::vector<Pixel> corrected;
	for (const Pixel & pixel : pixels)
	{
		corrected.push_back(this->correct(pixel));
	}

	return corrected;
}

const Pixel ColorGrader::LUTs[2][256] = {
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 1, 0},
		{1, 1, 1},
		{1, 2, 1},
		{1, 2, 1},
		{1, 3, 1},
		{1, 3, 2},
		{2, 4, 2},
		{2, 4, 2},
		{2, 5, 3},
		{2, 5, 3},
		{3, 6, 3},
		{3, 7, 3},
		{3, 7, 4},
		{4, 8, 4},
		{4, 8, 4},
		{4, 9, 5},
		{5, 9, 5},
		{5, 10, 5},
		{5, 11, 6},
		{6, 11, 6},
		{6, 12, 6},
		{7, 12, 7},
		{7, 13, 7},
		{8, 14, 8},
		{8, 14, 8},
		{8, 15, 8},
		{9, 16, 9},
		{9, 16, 9},
		{10, 17, 10},
		{10, 18, 10},
		{11, 18, 10},
		{11, 19, 11},
		{12, 20, 11},
		{13, 21, 12},
		{13, 21, 12},
		{14, 22, 13},
		{14, 23, 13},
		{15, 24, 13},
		{15, 24, 14},
		{16, 25, 14},
		{17, 26, 15},
		{17, 27, 15},
		{18, 27, 16},
		{18, 28, 16},
		{19, 29, 17},
		{20, 30, 17},
		{20, 30, 18},
		{21, 31, 18},
		{22, 32, 19},
		{22, 33, 19},
		{23, 34, 20},
		{24, 35, 20},
		{25, 35, 21},
		{25, 36, 21},
		{26, 37, 22},
		{27, 38, 22},
		{27, 39, 23},
		{28, 40, 23},
		{29, 40, 24},
		{30, 41, 24},
		{31, 42, 25},
		{31, 43, 26},
		{32, 44, 26},
		{33, 45, 27},
		{34, 46, 27},
		{34, 47, 28},
		{35, 48, 28},
		{36, 49, 29},
		{37, 49, 29},
		{38, 50, 30},
		{39, 51, 31},
		{39, 52, 31},
		{40, 53, 32},
		{41, 54, 32},
		{42, 55, 33},
		{43, 56, 34},
		{44, 57, 34},
		{45, 58, 35},
		{46, 59, 35},
		{46, 60, 36},
		{47, 61, 37},
		{48, 62, 37},
		{49, 63, 38},
		{50, 64, 39},
		{51, 65, 39},
		{52, 66, 40},
		{53, 67, 40},
		{54, 68, 41},
		{55, 69, 42},
		{56, 70, 42},
		{57, 71, 43},
		{58, 72, 44},
		{59, 73, 44},
		{59, 74, 45},
		{60, 75, 45},
		{61, 76, 46},
		{62, 77, 47},
		{63, 78, 47},
		{64, 79, 48},
		{65, 80, 49},
		{66, 81, 49},
		{67, 82, 50},
		{68, 83, 51},
		{69, 85, 51},
		{70, 86, 52},
		{71, 87, 53},
		{72, 88, 53},
		{73, 89, 54},
		{74, 90, 55},
		{75, 91, 55},
		{76, 92, 56},
		{77, 93, 57},
		{78, 94, 57},
		{79, 95, 58},
		{80, 96, 59},
		{81, 98, 59},
		{83, 99, 60},
		{84, 100, 61},
		{85, 101, 62},
		{86, 102, 62},
		{87, 103, 63},
		{88, 104, 64},
		{89, 105, 64},
		{90, 107, 65},
		{91, 108, 66},
		{92, 109, 66},
		{93, 110, 67},
		{94, 111, 68},
		{95, 112, 68},
		{96, 113, 69},
		{97, 114, 70},
		{98, 116, 70},
		{99, 117, 71},
		{100, 118, 72},
		{101, 119, 73},
		{102, 120, 73},
		{104, 121, 74},
		{105, 122, 75},
		{106, 124, 75},
		{107, 125, 76},
		{108, 126, 77},
		{109, 127, 77},
		{110, 128, 78},
		{111, 129, 79},
		{112, 131, 79},
		{113, 132, 80},
		{114, 133, 81},
		{115, 134, 81},
		{116, 135, 82},
		{117, 136, 83},
		{118, 138, 84},
		{119, 139, 84},
		{120, 140, 85},
		{121, 141, 86},
		{122, 142, 86},
		{124, 144, 87},
		{125, 145, 88},
		{126, 146, 88},
		{127, 147, 89},
		{128, 148, 90},
		{129, 149, 90},
		{130, 151, 91},
		{131, 152, 92},
		{132, 153, 92},
		{133, 154, 93},
		{134, 155, 94},
		{135, 156, 94},
		{136, 158, 95},
		{137, 159, 96},
		{138, 160, 96},
		{139, 161, 97},
		{140, 162, 98},
		{141, 164, 98},
		{142, 165, 99},
		{143, 166, 100},
		{144, 167, 100},
		{145, 168, 101},
		{146, 170, 102},
		{147, 171, 102},
		{148, 172, 103},
		{149, 173, 104},
		{150, 174, 104},
		{151, 175, 105},
		{152, 177, 105},
		{153, 178, 106},
		{154, 179, 107},
		{155, 180, 107},
		{156, 181, 108},
		{157, 182, 109},
		{158, 184, 109},
		{158, 185, 110},
		{159, 186, 110},
		{160, 187, 111},
		{161, 188, 112},
		{162, 190, 112},
		{163, 191, 113},
		{164, 192, 114},
		{165, 193, 114},
		{166, 194, 115},
		{167, 195, 115},
		{168, 197, 116},
		{168, 198, 117},
		{169, 199, 117},
		{170, 200, 118},
		{171, 201, 118},
		{172, 202, 119},
		{173, 203, 119},
		{174, 205, 120},
		{174, 206, 121},
		{175, 207, 121},
		{176, 208, 122},
		{177, 209, 122},
		{178, 210, 123},
		{179, 212, 123},
		{179, 213, 124},
		{180, 214, 124},
		{181, 215, 125},
		{182, 216, 125},
		{182, 217, 126},
		{183, 218, 126},
		{184, 219, 127},
		{185, 221, 128},
		{185, 222, 128},
		{186, 223, 129},
		{187, 224, 129},
		{188, 225, 130},
		{188, 226, 130},
		{189, 227, 131},
		{190, 228, 131},
		{190, 229, 131},
		{191, 231, 132},
		{192, 232, 132},
		{192, 233, 133},
		{193, 234, 133},
		{194, 235, 134},
		{194, 236, 134},
		{195, 237, 135},
		{196, 238, 135},
		{196, 239, 136},
		{197, 240, 136},
		{197, 241, 136},
		{198, 242, 137},
		{198, 244, 137},
		{199, 245, 138},
		{200, 246, 138},
		{200, 247, 139},
		{201, 248, 139},
		{201, 249, 139},
		{202, 250, 140},
		{202, 251, 140},
		{203, 252, 140},
		{203, 253, 141},
		{204, 254, 141},
		{204, 255, 142}
	},
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 1, 0},
		{0, 1, 0},
		{1, 1, 0},
		{1, 1, 0},
		{1, 1, 0},
		{1, 1, 0},
		{1, 1, 0},
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1},
		{1, 2, 1},
		{1, 2, 1},
		{1, 2, 1},
		{2, 2, 1},
		{2, 2, 1},
		{2, 2, 1},
		{2, 2, 1},
		{2, 3, 1},
		{2, 3, 1},
		{2, 3, 1},
		{2, 3, 1},
		{3, 3, 1},
		{3, 3, 1},
		{3, 4, 2},
		{3, 4, 2},
		{3, 4, 2},
		{3, 4, 2},
		{4, 5, 2},
		{4, 5, 2},
		{4, 5, 2},
		{4, 5, 2},
		{4, 5, 2},
		{4, 6, 2},
		{5, 6, 3},
		{5, 6, 3},
		{5, 6, 3},
		{5, 7, 3},
		{5, 7, 3},
		{6, 7, 3},
		{6, 8, 3},
		{6, 8, 3},
		{6, 8, 3},
		{6, 8, 4},
		{7, 9, 4},
		{7, 9, 4},
		{7, 9, 4},
		{7, 10, 4},
		{8, 10, 4},
		{8, 10, 4},
		{8, 11, 4},
		{8, 11, 5},
		{8, 11, 5},
		{9, 12, 5},
		{9, 12, 5},
		{9, 12, 5},
		{9, 13, 5},
		{10, 13, 5},
		{10, 14, 6},
		{10, 14, 6},
		{11, 14, 6},
		{11, 15, 6},
		{11, 15, 6},
		{11, 16, 6},
		{12, 16, 6},
		{12, 16, 7},
		{12, 17, 7},
		{13, 17, 7},
		{13, 18, 7},
		{13, 18, 7},
		{13, 19, 7},
		{14, 19, 8},
		{14, 20, 8},
		{14, 20, 8},
		{15, 20, 8},
		{15, 21, 8},
		{15, 21, 8},
		{16, 22, 9},
		{16, 22, 9},
		{16, 23, 9},
		{17, 23, 9},
		{17, 24, 9},
		{17, 24, 10},
		{18, 25, 10},
		{18, 25, 10},
		{18, 26, 10},
		{19, 27, 10},
		{19, 27, 10},
		{19, 28, 11},
		{20, 28, 11},
		{20, 29, 11},
		{20, 29, 11},
		{21, 30, 11},
		{21, 30, 12},
		{21, 31, 12},
		{22, 32, 12},
		{22, 32, 12},
		{22, 33, 12},
		{23, 33, 13},
		{23, 34, 13},
		{24, 35, 13},
		{24, 35, 13},
		{24, 36, 14},
		{25, 36, 14},
		{25, 37, 14},
		{25, 38, 14},
		{26, 38, 14},
		{26, 39, 15},
		{27, 40, 15},
		{27, 40, 15},
		{27, 41, 15},
		{28, 42, 15},
		{28, 42, 16},
		{29, 43, 16},
		{29, 44, 16},
		{29, 44, 16},
		{30, 45, 17},
		{30, 46, 17},
		{31, 47, 17},
		{31, 47, 17},
		{31, 48, 18},
		{32, 49, 18},
		{32, 50, 18},
		{33, 50, 18},
		{33, 51, 18},
		{34, 52, 19},
		{34, 53, 19},
		{34, 53, 19},
		{35, 54, 19},
		{35, 55, 20},
		{36, 56, 20},
		{36, 56, 20},
		{37, 57, 20},
		{37, 58, 21},
		{37, 59, 21},
		{38, 60, 21},
		{38, 60, 21},
		{39, 61, 22},
		{39, 62, 22},
		{40, 63, 22},
		{40, 64, 22},
		{41, 65, 23},
		{41, 65, 23},
		{41, 66, 23},
		{42, 67, 23},
		{42, 68, 24},
		{43, 69, 24},
		{43, 70, 24},
		{44, 71, 24},
		{44, 72, 25},
		{45, 72, 25},
		{45, 73, 25},
		{46, 74, 25},
		{46, 75, 26},
		{46, 76, 26},
		{47, 77, 26},
		{47, 78, 27},
		{48, 79, 27},
		{48, 80, 27},
		{49, 81, 27},
		{49, 82, 28},
		{50, 83, 28},
		{50, 84, 28},
		{51, 85, 28},
		{51, 86, 29},
		{52, 87, 29},
		{52, 88, 29},
		{53, 89, 30},
		{53, 89, 30},
		{54, 91, 30},
		{54, 92, 30},
		{54, 93, 31},
		{55, 94, 31},
		{55, 95, 31},
		{56, 96, 31},
		{56, 97, 32},
		{57, 98, 32},
		{57, 99, 32},
		{58, 100, 33},
		{58, 101, 33},
		{59, 102, 33},
		{59, 103, 33},
		{60, 104, 34},
		{60, 105, 34},
		{61, 106, 34},
		{61, 107, 35},
		{62, 108, 35},
		{62, 110, 35},
		{63, 111, 35},
		{63, 112, 36},
		{64, 113, 36},
		{64, 114, 36},
		{65, 115, 37},
		{65, 116, 37},
		{66, 117, 37},
		{66, 119, 37},
		{67, 120, 38},
		{67, 121, 38},
		{68, 122, 38},
		{68, 123, 39},
		{69, 124, 39},
		{69, 126, 39},
		{70, 127, 39},
		{70, 128, 40},
		{71, 129, 40},
		{71, 130, 40},
		{72, 132, 41},
		{72, 133, 41},
		{73, 134, 41},
		{73, 135, 41},
		{74, 137, 42},
		{74, 138, 42},
		{75, 139, 42},
		{75, 140, 43},
		{76, 142, 43},
		{76, 143, 43},
		{77, 144, 43},
		{77, 145, 44},
		{78, 147, 44},
		{78, 148, 44},
		{79, 149, 45},
		{79, 151, 45},
		{79, 152, 45},
		{80, 153, 45},
		{80, 155, 46},
		{81, 156, 46},
		{81, 157, 46},
		{82, 159, 47},
		{82, 160, 47},
		{83, 161, 47},
		{83, 163, 48},
		{84, 164, 48},
		{84, 165, 48},
		{85, 167, 48},
		{85, 168, 49},
		{86, 169, 49},
		{86, 171, 49},
		{87, 172, 50},
		{87, 174, 50},
		{88, 175, 50},
		{88, 176, 50},
		{89, 178, 51},
		{89, 179, 51}
	}
};
