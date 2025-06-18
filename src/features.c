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

    int min_sum = 256 * 3 + 1;
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

void max_component(char *source_path, char component)
{
    unsigned char *data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
        return;
    }

    int max_val = -1;
    int max_x = 0, max_y = 0;
    int comp_index = 0;

    if (component == 'R')
        comp_index = 0;
    else if (component == 'G')
        comp_index = 1;
    else if (component == 'B')
        comp_index = 2;
    else
    {
        printf("Composante invalide: %c (utiliser R, G ou B)\n", component);
        free_image_data(data);
        return;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * channel_count;
            int value = data[index + comp_index];

            if (value > max_val)
            {
                max_val = value;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_val);
    free_image_data(data);
}

void min_component(char *source_path, char component)
{
    unsigned char *data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0)
    {
        printf("Erreur avec le fichier : %s\n", source_path);
        return;
    }

    int min_val = 256;
    int min_x = 0, min_y = 0;
    int comp_index = 0;

    if (component == 'R')
        comp_index = 0;
    else if (component == 'G')
        comp_index = 1;
    else if (component == 'B')
        comp_index = 2;
    else
    {
        printf("Composante invalide: %c (utilisez R, G ou B)\n", component);
        free_image_data(data);
        return;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * channel_count;
            int value = data[index + comp_index];

            if (value < min_val)
            {
                min_val = value;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_val);
    free_image_data(data);
}

void color_red(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char red = pixel->R;
            new_data[(y * width + x) * channel_count] = red;
            new_data[(y * width + x) * channel_count + 1] = 0;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void stat_report(char *source_path)
{
    unsigned char *data;
    int width, height, channels;

    if (!read_image_data(source_path, &data, &width, &height, &channels))
    {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    FILE *file = fopen("stat_report.txt", "w");
    if (file == NULL)
    {
        printf("Erreur : impossible de créer le fichier stat_report.txt\n");
        free_image_data(data);
        return;
    }

    int x, y, r, g, b, val;

    find_max_pixel(data, width, height, channels, &x, &y, &r, &g, &b);
    fprintf(file, "max_pixel (%d, %d): %d, %d, %d\n\n", x, y, r, g, b);

    find_min_pixel(data, width, height, channels, &x, &y, &r, &g, &b);
    fprintf(file, "min_pixel (%d, %d): %d, %d, %d\n\n", x, y, r, g, b);

    val = find_max_component(data, width, height, channels, 'R', &x, &y);
    fprintf(file, "max_component R (%d, %d): %d\n\n", x, y, val);

    val = find_max_component(data, width, height, channels, 'G', &x, &y);
    fprintf(file, "max_component G (%d, %d): %d\n\n", x, y, val);

    val = find_max_component(data, width, height, channels, 'B', &x, &y);
    fprintf(file, "max_component B (%d, %d): %d\n\n", x, y, val);

    val = find_min_component(data, width, height, channels, 'R', &x, &y);
    fprintf(file, "min_component R (%d, %d): %d\n\n", x, y, val);

    val = find_min_component(data, width, height, channels, 'G', &x, &y);
    fprintf(file, "min_component G (%d, %d): %d\n\n", x, y, val);

    val = find_min_component(data, width, height, channels, 'B', &x, &y);
    fprintf(file, "min_component B (%d, %d): %d\n\n", x, y, val);

    fclose(file);
    free_image_data(data);

    printf("Le fichier stat_report.txt a été généré avec succès.\n");
    printf("stat_report.txt généré avec succès.\n");
}
void color_green(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char green = pixel->G;
            new_data[(y * width + x) * channel_count] = 0;
            new_data[(y * width + x) * channel_count + 1] = green;
            new_data[(y * width + x) * channel_count + 2] = 0;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_blue(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char blue = pixel->B;
            new_data[(y * width + x) * channel_count] = 0;
            new_data[(y * width + x) * channel_count + 1] = 0;
            new_data[(y * width + x) * channel_count + 2] = blue;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_gray(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char gray = (pixel->R + pixel->G + pixel->B) / 3;
            new_data[(y * width + x) * channel_count] = gray;
            new_data[(y * width + x) * channel_count + 1] = gray;
            new_data[(y * width + x) * channel_count + 2] = gray;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_invert(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            new_data[(y * width + x) * channel_count] = 255 - pixel->R;
            new_data[(y * width + x) * channel_count + 1] = 255 - pixel->G;
            new_data[(y * width + x) * channel_count + 2] = 255 - pixel->B;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}

void color_gray_luminance(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);
            unsigned char value = 0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B;
            new_data[(y * width + x) * channel_count] = value;
            new_data[(y * width + x) * channel_count + 1] = value;
            new_data[(y * width + x) * channel_count + 2] = value;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
}
void rotate_cw(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int new_x = height - 1 - y;
            int new_y = x;

            for (int c = 0; c < channel_count; c++)
            {
                new_data[(new_y * height + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, height, width);
    free(new_data);
    free_image_data(data);
}

void rotate_acw(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int new_x = y;
            int new_y = width - 1 - x;

            for (int c = 0; c < channel_count; c++)
            {
                new_data[(new_y * height + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, height, width);
    free(new_data);
    free_image_data(data);
}

void mirror_horizontal(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int new_x = width - 1 - x;
            int new_y = y;

            for (int c = 0; c < channel_count; c++)
            {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}

void mirror_vertical(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int new_x = x;
            int new_y = height - 1 - y;

            for (int c = 0; c < channel_count; c++)
            {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}

void mirror_total(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int new_x = width - 1 - x;
            int new_y = height - 1 - y;

            for (int c = 0; c < channel_count; c++)
            {
                new_data[(new_y * width + new_x) * channel_count + c] = data[(y * width + x) * channel_count + c];
            }
        }
    }

    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}
void scale_crop(char *source_path, int center_x, int center_y, int width, int height)
{
    int original_width, original_height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &original_width, &original_height, &channel_count);

    int x_start = center_x - width / 2;
    int y_start = center_y - height / 2;

    if (x_start < 0)
    {
        x_start = 0;
    }
    else if (x_start + width > original_width)
    {
        x_start = original_width - width;
    }

    if (y_start < 0)
    {
        y_start = 0;
    }
    else if (y_start + height > original_height)
    {
        y_start = original_height - height;
    }

    unsigned char *new_data = (unsigned char *)malloc(width * height * channel_count * sizeof(unsigned char));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int new_x = x_start + x;
            int new_y = y_start + y;

            pixelRGB *pixel = get_pixel(data, original_width, original_height, channel_count, new_x, new_y);
            unsigned char R = pixel->R;
            unsigned char G = pixel->G;
            unsigned char B = pixel->B;

            new_data[(y * width + x) * channel_count] = R;
            new_data[(y * width + x) * channel_count + 1] = G;
            new_data[(y * width + x) * channel_count + 2] = B;
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
    free_image_data(data);
}