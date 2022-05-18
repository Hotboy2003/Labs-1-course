#pragma once
#include <iostream>
#include <fstream>

#pragma pack(1)
struct BMPHEADER 
{
    unsigned short    Type;
    unsigned int      Size;
    unsigned short    Reserved1;
    unsigned short    Reserved2;
    unsigned int      OffBits;
};
#pragma pack()

#pragma pack(1)
struct BMPINFO 
{
    unsigned int    Size;
    int             Width;
    int             Height;
    unsigned short  Planes;
    unsigned short  BitCount;
    unsigned int    Compression;
    unsigned int    SizeImage;
    int             XPelsPerMeter;
    int             YPelsPerMeter;
    unsigned int    ClrUsed;
    unsigned int    ClrImportant;
};
#pragma pack()

#pragma pack(1)
struct Pixel 
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
};
#pragma pack()

class BMP 
{
public:
    BMP();
    ~BMP();

    void readBMP(std::string name);
    void writeBMP(std::string name);

    void shifr(std::string word);
    void ashifr();

private:
    BMPHEADER m_bmpHeader;
    BMPINFO m_bmpInfo;
    BMPHEADER m_bmpHeader_new;
    BMPINFO m_bmpInfo_new;
    Pixel** m_pixels;
};