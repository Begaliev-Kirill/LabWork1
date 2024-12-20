/* Kirill Begaliev st129977@student.spbu.ru
Read and write BMP file functions
*/

#include <iostream>
#include <fstream>
#include "BMP_reader.hpp"


void readBMP(const char *fileName, BMPInfoHeader &fileInfoHeader, BMPDIBHeader &fileDIBHeader, Pixel **&pixelMap) {
    std::ifstream BMPfile(fileName, std::ios::binary);
    
    BMPfile.read((char*)&fileInfoHeader, sizeof(fileInfoHeader));
    BMPfile.read((char*)&fileDIBHeader, sizeof(fileDIBHeader));
    
    int width = fileDIBHeader.width;
    int height = fileDIBHeader.height;
    int padding = (4 - (width * 3) % 4) % 4;
    
    pixelMap = new Pixel*[height];
    for (int i = 0; i < height; ++i) {
        pixelMap[i] = new Pixel[width];
    }
    
    BMPfile.seekg(fileInfoHeader.pixelsOffset, std::ios::beg);
    
    for (int j = 0; j < height; ++j) {
        for (int k = 0; k < width; ++k) {
            BMPfile.read((char*)&pixelMap[j][k], 3);
        }
        BMPfile.ignore(padding);
    }
}

void writeBMP(const char *fileName, const BMPInfoHeader &fileInfoHeader, const BMPDIBHeader &fileDIBHeader, Pixel **pixelMap) {
    std::ofstream BMPfile(fileName, std::ios::binary);
    
    BMPfile.write((const char*)&fileInfoHeader, sizeof(fileInfoHeader));
    BMPfile.write((const char*)&fileDIBHeader, sizeof(fileDIBHeader));
    
    int width = fileDIBHeader.width;
    int height = fileDIBHeader.height;
    int padding = (4 - (width * 3) % 4) % 4;
    
    BMPfile.seekp(fileInfoHeader.pixelsOffset, std::ios::beg);
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            BMPfile.write((const char*)&pixelMap[i][j], 3);
        }
        BMPfile.write("\0\0\0", padding); //add padding that was ignored when file was readed
    }
}

void pixelMapRemover(Pixel **&pixelMap,  unsigned int height) {
    for (unsigned int i = 0; i < height; ++i) {
        delete[] pixelMap[i];
    }
    delete[] pixelMap;
    pixelMap = nullptr;
}
