/* Kirill Begaliev st129977@student.spbu.ru
Does the main task
*/

#include <iostream>
#include <string>
#include "BMP_reader.hpp"
#include "Turn.hpp"
#include "Gaus_filter.hpp"


int main(int argc, char *argv[]){
    if (argc > 4) {
        std::cout << "Wrong input, try \"./bmp input_file_name.bmp radiusOfGausMatrix(ushort) sigma(float)\"" << std::endl;
    }
    
    const char* fileName = "test_goat.bmp";
    unsigned short radiusOfGausMatrix = 7;
    float sigma = 4.1478;
    
    if (argv[1]) {
        fileName = argv[1];
    }
    
    if(argc >= 3 ) {
        std::string radiusStr = argv[2];
        radiusOfGausMatrix = static_cast<unsigned short>(std::stoi(radiusStr));
        
        if(argc == 4) {
            std::string sigmaStr = argv[3];
            sigma = std::stof(sigmaStr);
        }
    }
    
    BMPInfoHeader fileInfoHeader;
    BMPDIBHeader fileDIBHeader;
    Pixel **pixelMap = nullptr;
    
    readBMP(fileName, fileInfoHeader, fileDIBHeader, pixelMap);
    
    Pixel **rotatedClockwise = rotateClockwise(pixelMap, fileDIBHeader.width, fileDIBHeader.height);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
    writeBMP("RotatedClockwise.bmp", fileInfoHeader, fileDIBHeader, rotatedClockwise);
    pixelMapRemover(rotatedClockwise, fileDIBHeader.height);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
    
    Pixel **rotatedCounterClockwise = rotateCounterClockwise(pixelMap, fileDIBHeader.width, fileDIBHeader.height);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
    writeBMP("RotatedCounterClockwise.bmp", fileInfoHeader, fileDIBHeader, rotatedCounterClockwise);
    
    applyGausFilter(rotatedCounterClockwise, fileDIBHeader.width, fileDIBHeader.height, radiusOfGausMatrix, filterMatrix(radiusOfGausMatrix, sigma));
    writeBMP("GausFilter.bmp", fileInfoHeader, fileDIBHeader, rotatedCounterClockwise);
    pixelMapRemover(rotatedCounterClockwise, fileDIBHeader.height);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);

    pixelMapRemover(pixelMap, fileDIBHeader.height);
}
