/* Kirill Begaliev st129977@student.spbu.ru
Turn clockwise and counterclockwise functions
*/

#include <iostream>
#include "Turn.hpp"


Pixel **rotateCounterClockwise(Pixel **pixelMap, unsigned int width, unsigned int height) {
    Pixel **rotatedImage = new Pixel*[width];
    
    for (unsigned int i = 0; i < width; ++i) {
        rotatedImage[i] = new Pixel[height];
    }
    
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            rotatedImage[x][height - y - 1] = pixelMap[y][x];
        }
    }
    
    return rotatedImage;
}

Pixel **rotateClockwise(Pixel **pixelMap, unsigned int width, unsigned int height) {
    Pixel **rotatedImage = new Pixel*[width];
    
    for (unsigned int i = 0; i < width; ++i) {
        rotatedImage[i] = new Pixel[height];
    }
    
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            rotatedImage[width - x - 1][y] = pixelMap[y][x];
        }
    }
    
    return rotatedImage;
}
