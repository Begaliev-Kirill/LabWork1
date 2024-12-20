/* Kirill Begaliev st129977@student.spbu.ru
Gaus filter to the BMP file
*/

#ifndef GAUS_FILTER_HPP
#define GAUS_FILTER_HPP

#include <vector>
#include "BMP_header.hpp"
#include "Pixel.hpp"

std::vector<std::vector<float>> filterMatrix(unsigned short radius, float sigma);
Pixel getPixel(Pixel **pixelMap, unsigned int width, unsigned int height, int x, int y);
void applyGausFilter(Pixel **pixelMap, unsigned int width, unsigned int height, unsigned short radius, const std::vector<std::vector<float>> &matrix);

#endif //GAUS_FILTER_HPP
