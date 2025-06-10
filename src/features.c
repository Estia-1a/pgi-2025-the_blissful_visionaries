#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

void helloWorld()
{
    printf("Hello World !");
}
void dimension(char *filename)
{
    unsigned char *data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", filename);
    }
    else
    {
        printf("dimension: %d, %d\n", width, height);
        free_image_data(data);
    }
}
void tenth_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    int x = 9;
    int y = 0;
    int pixel_index = (y * width + x) * channel_count;

    int R = data[pixel_index];
    int G = data[pixel_index + 1];
    int B = data[pixel_index + 2];

    printf("tenth_pixel: %d, %d, %d\n", R, G, B);
    free_image_data(data);
}

void first_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    int x = 0;
    int y = 0;
    int pixel_index = (y * width + x) * channel_count;

    int R = data[pixel_index];
    int G = data[pixel_index + 1];
    int B = data[pixel_index + 2];

    printf("first_pixel: %d, %d, %d\n", R, G, B);
    free_image_data(data);
}

void second_line(char *source_path)
{
    unsigned char *data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    int x = 1;
    int y = 0;
    int pixel_index = (y * width + x) * channel_count;

    int R = data[pixel_index];
    int G = data[pixel_index + 1];
    int B = data[pixel_index + 2];

    printf("second_line: %d, %d, %d\n", R, G, B);
    free_image_data(data);
}

void max_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
        return;
    }

    int max_sum = -1;
    int max_x = 0;
    int max_y = 0;
    int max_R = 0, max_G = 0, max_B = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * channel_count;

            int R = data[index];
            int G = data[index + 1];
            int B = data[index + 2];
            int sum = R + G + B;

            if (sum > max_sum)
            {
                max_sum = sum;
                max_x = x;
                max_y = y;
                max_R = R;
                max_G = G;
                max_B = B;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_R, max_G, max_B);
    free_image_data(data);
}

void min_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
        return;
    }

    int min_sum = 256 * 3 + 1; // plus grand que la somme max possible (255*3)
    int min_x = 0;
    int min_y = 0;
    int min_R = 0, min_G = 0, min_B = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * channel_count;

            int R = data[index];
            int G = data[index + 1];
            int B = data[index + 2];
            int sum = R + G + B;

            if (sum < min_sum)
            {
                min_sum = sum;
                min_x = x;
                min_y = y;
                min_R = R;
                min_G = G;
                min_B = B;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_R, min_G, min_B);
    free_image_data(data);
}
