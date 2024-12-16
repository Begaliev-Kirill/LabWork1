/* Kirill Begaliev st129977@student.spbu.ru
Does the main task
*/

#include <iostream>
#include "BMP_reader.hpp"


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
    writeBMP("Writed.bmp", fileInfoHeader, fileDIBHeader, pixelMap);
}
