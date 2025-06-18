#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
 */

typedef struct _pixelRGB
{
  unsigned char R;
  unsigned char G;
  unsigned char B;
} pixelRGB;

pixelRGB *get_pixel(unsigned char *data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x,const unsigned int y) ;
void find_max_pixel(unsigned char *data, int width, int height, int channels,
                    int *x, int *y, int *r, int *g, int *b);

void find_min_pixel(unsigned char *data, int width, int height, int channels,
                    int *x, int *y, int *r, int *g, int *b);

int find_max_component(unsigned char *data, int width, int height, int channels,
                       char component, int *x, int *y);

int find_min_component(unsigned char *data, int width, int height, int channels,
                       char component, int *x, int *y);

#endif
