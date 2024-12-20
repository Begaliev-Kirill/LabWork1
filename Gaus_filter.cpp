/* Kirill Begaliev st129977@student.spbu.ru
Gaus filter to the BMP file
*/

#include <iostream>
#include <cmath>
#include <string>
#include "Gaus_filter.hpp"

std::vector<std::vector<float>> filterMatrix(unsigned short radius, float sigma) {
    float sumOfElements = 0.0;
    int lengthOfMatrix = radius*2 + 1;
    std::vector<std::vector<float>> matrix(lengthOfMatrix);
    
    for (int i = 0; i < lengthOfMatrix; ++i) {
        matrix[i].resize(lengthOfMatrix);
    }
    
    for (int x = -radius; x <= radius; ++x) {
        for (int y = -radius; y <= radius; ++y) {
            matrix[x + radius][y + radius] = (1 / (2 * 3.14 * sigma)) * exp(-1*(x*x + y*y) / (2 * sigma*sigma));
            sumOfElements += matrix[x + radius][y + radius];
        }
    }
    
    for (int x = 0; x < lengthOfMatrix; ++x) {
        for (int y = 0; y < lengthOfMatrix; ++y) {
            matrix[x][y] = matrix[x][y] / sumOfElements;
        }
    }
    
    return matrix;
}

Pixel getPixel(Pixel **pixelMap, unsigned int width, unsigned int height, int x, int y) {
    if (x < 0) x = -x;
    if (x >= static_cast<int>(width)) x = width - 1 - (x - width + 1); 
    if (y < 0) y = -y; 
    if (y >= static_cast<int>(height)) y = height - 1 - (y - height + 1); 

    return pixelMap[y][x]; 
}

void applyGausFilter(Pixel **pixelMap, unsigned int width, unsigned int height, unsigned short radius, const std::vector<std::vector<float>> &matrix) {
    Pixel **filteredPixelMap = new Pixel*[height];
    for (unsigned int i = 0; i < height; ++i) {
        filteredPixelMap[i] = new Pixel[width];
    }
    
    for(unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            float red = 0, green = 0, blue = 0;
            
            for (int ky = -radius; ky < static_cast<int>(radius); ++ky) {
                for (int kx = -radius; kx < static_cast<int>(radius); ++kx) {
                    Pixel p = getPixel(pixelMap, width, height, x + kx, y + ky);

                    red += p.red * matrix[ky + radius][kx + radius];
                    green += p.green * matrix[ky + radius][kx + radius];
                    blue += p.blue * matrix[ky + radius][kx + radius];
                }
            }
            
            filteredPixelMap[y][x].red = static_cast<unsigned char>(std::min(std::max(static_cast<int>(red), 0), 255));
            filteredPixelMap[y][x].green = static_cast<unsigned char>(std::min(std::max(static_cast<int>(green), 0), 255));
            filteredPixelMap[y][x].blue = static_cast<unsigned char>(std::min(std::max(static_cast<int>(blue), 0), 255));
        }
    }
    
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < height; ++x) {
            pixelMap[y][x] = filteredPixelMap[y][x];
        }
        delete[] filteredPixelMap[y];
    }
    
    delete[] filteredPixelMap;
}
