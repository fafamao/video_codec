#include <math.h>
#include <iostream>

const int dct_quant[8][8] = {
    {16, 11, 10, 16, 24, 40, 51, 61},
    {12, 12, 14, 19, 26, 58, 60, 55},
    {14, 13, 16, 24, 40, 57, 69, 56},
    {14, 17, 22, 29, 51, 87, 80, 62},
    {18, 22, 37, 56, 68, 109, 103, 77},
    {24, 35, 55, 64, 81, 104, 113, 92},
    {49, 64, 78, 87, 103, 121, 120, 101},
    {72, 92, 95, 98, 112, 100, 103, 99}};

typedef struct
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB_24;

class Encoder
{
public:
    Encoder();
    ~Encoder();
    void dct();
    void rgb24_to_yuv(const uint8_t *rgbBuf_p, const int frame_size);
    void run();

private:
    float *dct_in;
    float *dct_out;
};