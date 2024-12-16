/* Kirill Begaliev st129977@student.spbu.ru
Structures for saving BMP headers
*/
#ifndef BMP_HEADERS
#define BMP_HEADERS

#pragma pack(push,1)
struct BMPInfoHeader {
    unsigned short ID;
    unsigned int fileSize;
    unsigned short unused1;
    unsigned short unused2;
    unsigned int pixelsOffset;
};

struct BMPDIBHeader {
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short colorPlanes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int dataSize;
    unsigned int pwidth;
    unsigned int pheight;
    unsigned colorsCount;
    unsigned int importantColorsCount;
};
#pragma pack(pop)

#endif //BMP_HEADERS
