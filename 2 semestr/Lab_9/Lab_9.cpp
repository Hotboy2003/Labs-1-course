#include <iostream>
#include <fstream>
#include "BMP.hpp"

int main()
{
    // Чтение файла
    std::ifstream in("in.bmp", std::ios::binary); // открыть файл для бинарного чтения
    AO::BMPHEADER bmpHeader;
    // Считать 14 байтов побайтово и заполнить структуру BMPHEADER
    in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));
    BMPINFO bmpInfo;
    in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));

    Pixel** pixels = new Pixel * [bmpInfo.Height];
    for (int i = 0; i < bmpInfo.Height; i++)
        pixels[i] = new Pixel[bmpInfo.Width];

    for (int i = 0; i < bmpInfo.Height; i++)
    {
        for (int j = 0; j < bmpInfo.Width; j++)
            in.read(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));

        if ((3 * bmpInfo.Width) % 4 != 0)
            for (int j = 0; j < 4 - (3 * bmpInfo.Width) % 4; j++)
            {
                char c;
                in.read(&c, 1);
            }
    }
}

    // pixels
    for (int i = 0; i < bmpInfo.Height; i++)
        for (int j = 0; j < bmpInfo.Width; j++)
        {
            if (pixels[i][j].b - 50 > 0)
                pixels[i][j].b -= 50;
            if (pixels[i][j].g - 50 > 0)
                pixels[i][j].g -= 50;
            if (pixels[i][j].r - 50 > 0)
                pixels[i][j].r -= 50;
        }



    // Записать файл
    std::ofstream out("out.bmp", std::ios::binary);

    int width = bmpInfo.Width;
    int height = bmpInfo.Height;

    // Формирование заголовка
    BMPHEADER bmpHeader_new;
    bmpHeader_new.Type = 0x4D42; // Тип данных BMP
    bmpHeader_new.Size = 14 + 40 + (3 * width * height);
    if (width % 4 != 0)
        bmpHeader_new.Size += (4 - (3 * width) % 4) * height;
    bmpHeader_new.OffBits = 54;
    bmpHeader_new.Reserved1 = 0;
    bmpHeader_new.Reserved2 = 0;

    out.write(reinterpret_cast<char*>(&bmpHeader_new), sizeof(BMPHEADER));

    // Формирование информации об изображении
    BMPINFO bmpInfo_new;
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

    // Записать пиксели
    for (int i = 0; i < bmpInfo_new.Height; i++)
    {
        for (int j = 0; j < bmpInfo_new.Width; j++)
            out.write(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));

        if ((3 * bmpInfo_new.Width) % 4 != 0)
            for (int j = 0; j < 4 - (3 * bmpInfo_new.Width) % 4; j++)
            {
                char c = 0;
                out.write(&c, 1);
            }
    }

    for (int i = 0; i < bmpInfo.Height; i++)
        delete[] pixels[i];
    delete[] pixels;
}
