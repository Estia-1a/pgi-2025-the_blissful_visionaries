#include "utils.h"
#include <stddef.h> // Pour NULL

pixelRGB *get_pixel(unsigned char *data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y)
{
    if (x >= width || y >= height || n < 3)
    {
        return NULL;
    }

    static pixelRGB pixel;
    int index = (y * width + x) * n;
    pixel.R = data[index];
    pixel.G = data[index + 1];
    pixel.B = data[index + 2];

    return &pixel;
}
