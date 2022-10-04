#include "encoder.h"

Encoder::Encoder(const int frame_size)
{
    n_bytes_per_frame = frame_size;
    y_p = (uint8_t *)malloc(frame_size);
    u_p = (uint8_t *)malloc(frame_size);
    v_p = (uint8_t *)malloc(frame_size);
}

Encoder::~Encoder()
{
    free(y_p);
    free(u_p);
    free(v_p);
}

void Encoder::dct(){

};

void Encoder::rgb24_to_yuv(RGB_24 *rgb_24)
{
    int n_rgb_block = n_bytes_per_frame / YUV_DIM;

    for (int idx = 0; idx < n_rgb_block; idx++)
    {
        *(y_p + idx) = (uint8_t)(((uint32_t)rgb_24->red * 66 + (uint32_t)rgb_24->green * 129 + (uint32_t)rgb_24->blue * 25 + 128) >> 8) + 16;
        *(u_p + idx) = (uint8_t)(((uint32_t)rgb_24->red * (-38) - (uint32_t)rgb_24->green * 74 + (uint32_t)rgb_24->blue * 112 + 128) >> 8) + 128;
        *(v_p + idx) = (uint8_t)(((uint32_t)rgb_24->red * 112 - (uint32_t)rgb_24->green * 94 - (uint32_t)rgb_24->blue * 18 + 128) >> 8) + 128;
    }
};

void Encoder::run(const uint8_t *rgbBuf_p)
{
    printf("Encoder is running.\n");

    RGB_24 *rgb_24 = (RGB_24 *)rgbBuf_p;
    int n_rgb_block = n_bytes_per_frame / YUV_DIM;

    rgb24_to_yuv(rgb_24);
}