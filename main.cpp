/* Kirill Begaliev st129977@student.spbu.ru
Does the main task
*/

#include <iostream>
#include "BMP_reader.hpp"
#include "Turn.hpp"


int main(int argc, char *argv[]){
    if (argc > 2) {
        std::cout << "Wrong input, try \"./bmp input_file_name.bmp\" or only \"./bmp\"" << std::endl;
    }
    
    const char* fileName = "test_goat.bmp";
    if (argv[1]) {
        fileName = argv[1];
    }
    
    BMPInfoHeader fileInfoHeader;
    BMPDIBHeader fileDIBHeader;
    Pixel **pixelMap = nullptr;
    
    readBMP(fileName, fileInfoHeader, fileDIBHeader, pixelMap);
    
    Pixel **rotatedClockwise = rotateClockwise(pixelMap, fileDIBHeader.width, fileDIBHeader.height);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
    writeBMP("RotatedClockwise.bmp", fileInfoHeader, fileDIBHeader, rotatedClockwise);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
    
    Pixel **rotatedCounterClockwise = rotateCounterClockwise(pixelMap, fileDIBHeader.width, fileDIBHeader.height);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
    writeBMP("RotatedCounterClockwise.bmp", fileInfoHeader, fileDIBHeader, rotatedCounterClockwise);
    std::swap(fileDIBHeader.width, fileDIBHeader.height);
}
