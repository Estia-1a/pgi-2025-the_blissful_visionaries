#include "utils.h"
#include <stddef.h>

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 *
 */
pixelRGB *get_pixel(unsigned char *data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
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

void find_max_pixel(unsigned char *data, int width, int height, int channels,
                    int *x, int *y, int *r, int *g, int *b)
{
    int max_sum = -1;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int idx = (j * width + i) * channels;
            int R = data[idx], G = data[idx + 1], B = data[idx + 2];
            int sum = R + G + B;
            if (sum > max_sum)
            {
                max_sum = sum;
                *x = i;
                *y = j;
                *r = R;
                *g = G;
                *b = B;
            }
        }
    }
}
void find_min_pixel(unsigned char *data, int width, int height, int channels,
                    int *x, int *y, int *r, int *g, int *b)
{
    int min_sum = 256 * 3;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int idx = (j * width + i) * channels;
            int R = data[idx], G = data[idx + 1], B = data[idx + 2];
            int sum = R + G + B;
            if (sum < min_sum)
            {
                min_sum = sum;
                *x = i;
                *y = j;
                *r = R;
                *g = G;
                *b = B;
            }
        }
    }
}
int find_max_component(unsigned char *data, int width, int height, int channels,
                       char component, int *x, int *y)
{
    int comp_index = (component == 'R') ? 0 : (component == 'G') ? 1
                                                                 : 2;
    int max_val = -1;

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int idx = (j * width + i) * channels;
            int val = data[idx + comp_index];
            if (val > max_val)
            {
                max_val = val;
                *x = i;
                *y = j;
            }
        }
    }

    return max_val;
}
int find_min_component(unsigned char *data, int width, int height, int channels,
                       char component, int *x, int *y)
{
    int comp_index = (component == 'R') ? 0 : (component == 'G') ? 1
                                                                 : 2;
    int min_val = 256;

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            int idx = (j * width + i) * channels;
            int val = data[idx + comp_index];
            if (val < min_val)
            {
                min_val = val;
                *x = i;
                *y = j;
            }
        }
    }

    return min_val;
}