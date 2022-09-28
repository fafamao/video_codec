#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "encoder.h"

#define WIDTH 640
#define HEIGHT 480
#define FPS 25

int main()
{
    unsigned int frame_size;
    std::ifstream inFile;
    std::ofstream outFile;
    unsigned char *rgbBuf_p;

    inFile.open("../media/rick_roll.bin", std::ios::binary | std::ios::in);
    outFile.open("out.mp4", std::ios::binary | std::ios::out);

    // Resolution per frame times number of bytes per pixel
    frame_size = WIDTH * HEIGHT * 3;

    rgbBuf_p = new uint8_t[frame_size];

    if (!inFile.is_open())
    {
        printf("Unable to load video\n");
        exit(1);
    }
    if (!outFile.is_open())
    {
        printf("Unable to write video\n");
        exit(1);
    }
    inFile.seekg(0, inFile.end);
    int length = inFile.tellg();
    inFile.seekg(0, inFile.beg);
    if (length < frame_size)
    {
        printf("Size of raw file is %d. Less than frame size %d.\n",
               length, frame_size);
    }

    while (!inFile.eof())
    {
        inFile.read((char *)rgbBuf_p, frame_size);
        std::cout << "Current position of raw is " << inFile.tellg() << "\n";
        printf("Read %d-byte from raw video to %p..\n", frame_size, rgbBuf_p);

        Encoder code;
    }

    delete[] rgbBuf_p;

    inFile.close();
    outFile.close();
    return 0;
}