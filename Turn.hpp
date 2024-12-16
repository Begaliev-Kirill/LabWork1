/* Kirill Begaliev st129977@student.spbu.ru
Turn clockwise and counterclockwise declaration
*/

#ifndef TURN_HPP
#define TURN_HPP

#include "Pixel.hpp"


Pixel **rotateCounterClockwise(Pixel **pixelMap, unsigned int width, unsigned int height);
Pixel **rotateClockwise(Pixel **pixelMap, unsigned int width, unsigned int height);

#endif //TURN_HPP
