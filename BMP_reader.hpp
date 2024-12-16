/* Kirill Begaliev st129977@student.spbu.ru
Read and write BMP file declaration 
*/

#ifndef BMP_READER_HPP
#define BMP_READER_HPP

#include "BMP_header.hpp"
#include "Pixel.hpp"

void readBMP(const char *fileName, BMPInfoHeader &fileInfoHeader, BMPDIBHeader &fileDIBHeader, Pixel **&pixelMap);
void writeBMP(const char *fileName, const BMPInfoHeader &fileInfoHeader, const BMPDIBHeader &fileDIBHeader, Pixel **pixelMap);

#endif //BMP_READER_HPP
