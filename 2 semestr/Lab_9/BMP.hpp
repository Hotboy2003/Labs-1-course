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
    BMP() 
    {

    }
    void READ() 
    {
        std::ifstream in("IMAGE1.bmp", std::ios::binary);
        if (!in.is_open())
            std::cout << "not work" << std::endl;
        in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));
        std::cout << bmpHeader.Size << std::endl;

        in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));
        std::cout << bmpInfo.Height << std::endl;

        pix = new Pixel * [bmpInfo.Height];
        for (int i = 0; i < bmpInfo.Height; i++)
            pix[i] = new Pixel[bmpInfo.Width];

        for (int i = 0; i < bmpInfo.Height; i++)
        {
            for (int j = 0; j < bmpInfo.Width; j++)
                in.read(reinterpret_cast<char*>(&pix[i][j]), sizeof(Pixel));

            if ((3 * bmpInfo.Width) % 4 != 0)
                for (int j = 0; j < 4 - (3 * bmpInfo.Width) % 4; j++)
                {
                    char c;
                    in.read(&c, 1);
                }
        }
        pix_new = new Pixel * [bmpInfo.Height];
        for (int i = 0; i < bmpInfo.Height; i++)
            pix_new[i] = new Pixel[bmpInfo.Width];
        for (int i = 0; i < bmpInfo.Height; i++)
        {
            for (int j = 0; j < bmpInfo.Width; j++)
            {
                pix_new[i][j] = pix[i][j];
            }
        }
    }

    void WRITE() 
    {
        std::ofstream out("IMAGE_out.bmp", std::ios::binary);

        int width = bmpInfo.Width;
        int height = bmpInfo.Height;
        bmpHeader_new.Type = 0x4D42;
        bmpHeader_new.Size = 14 + 40 + (3 * width * height);
        if (width % 4 != 0)
            bmpHeader_new.Size += (4 - (3 * width) % 4) * height;
        bmpHeader_new.OffBits = 54;
        bmpHeader_new.Reserved1 = 0;
        bmpHeader_new.Reserved2 = 0;

        out.write(reinterpret_cast<char*>(&bmpHeader_new), sizeof(BMPHEADER));

        bmpInfo_new.BitCount = 24;
        bmpInfo_new.ClrImportant = 0;
        bmpInfo_new.ClrUsed = 0;
        bmpInfo_new.Compression = 0;
        bmpInfo_new.Height = height;
        bmpInfo_new.Planes = 1;
        bmpInfo_new.Size = 40;
        bmpInfo_new.SizeImage = bmpHeader_new.Size - 54;
        bmpInfo_new.Width = width;
        bmpInfo_new.XPelsPerMeter = 0;
        bmpInfo_new.YPelsPerMeter = 0;

        out.write(reinterpret_cast<char*>(&bmpInfo_new), sizeof(BMPINFO));

        for (int i = 0; i < bmpInfo_new.Height; i++)
        {
            for (int j = 0; j < bmpInfo_new.Width; j++)
                out.write(reinterpret_cast<char*>(&pix_new[i][j]), sizeof(Pixel));

            if ((3 * bmpInfo_new.Width) % 4 != 0)
                for (int j = 0; j < 4 - (3 * bmpInfo_new.Width) % 4; j++)
                {
                    char c = 0;
                    out.write(&c, 1);
                }
        }
    }
    void FILTER()
    {
        for (int i = 0; i < bmpInfo.Height; i++)
            for (int j = 0; j < bmpInfo.Width; j++)
            {
                pix_new[i][j].b = 256- pix_new[i][j].b;
                pix_new[i][j].r = 256- pix_new[i][j].r;
                pix_new[i][j].g = 256- pix_new[i][j].g;
            }
    }

    ~BMP() 
    {
        if (pix != nullptr)
        {
            for (int i = 0; i < bmpInfo.Height; i++)
                delete[] pix[i];
            delete[] pix;
        }

        if (pix_new != nullptr)
        {
            for (int i = 0; i < bmpInfo_new.Height; i++)
                delete[] pix_new[i];
            delete[] pix_new;
        }
    }
private:
    BMPHEADER bmpHeader;
    BMPINFO bmpInfo;
    Pixel** pix = nullptr;
    Pixel** pix_new = nullptr;
    BMPHEADER bmpHeader_new;
    BMPINFO bmpInfo_new;
};