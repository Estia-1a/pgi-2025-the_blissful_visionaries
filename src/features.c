#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
=======

>>>>>>> 61ded394ad0dd25c831cad73be8ef2e80014d23d
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

 void keep_red_component(const char *input_filename) {
    int width, height, channels;
    unsigned char* data;

    if (read_image_data(input_filename, &data, &width, &height, &channels) == 0)
    {
        printf("Erreur avec le fichier : %s\n", input_filename);
        return;
    }

    int size = width * height * channels;

    // Modifier les composantes vertes et bleues à 0 pour ne garder que le rouge
    for (int i = 0; i < size; i += channels) {
        // Garde le rouge
        // Met le vert et bleu à zéro (si l'image a au moins 3 canaux)
        if (channels >= 3) {
            data[i + 1] = 0; // Vert
            data[i + 2] = 0; // Bleu
        }
    }

    // Écrire l'image modifiée
    if (!write_image_data("image_out.bmp", data, width, height)) {
        printf("Erreur lors de l'écriture de l'image.\n");
    }

    // Libérer la mémoire
    free(data);
void stat_report(char *source_path)
{
    unsigned char *data;
    int width, height, channels;

    if (!read_image_data(source_path, &data, &width, &height, &channels))
    {
        printf("Erreur avec le fichier : %s\n", source_path);
        return;
    }

    FILE *file = fopen("stat_report.txt", "w");
    if (file == NULL)
    {
        printf("Erreur lors de la création du fichier de rapport.\n");
        free_image_data(data);
        return;
    }

#define WRITE_COMPONENT_EXTREME(fn, label, c)                                   \
    do                                                                          \
    {                                                                           \
        int x = 0, y = 0, val = (fn)(data, width, height, channels, c, &x, &y); \
        fprintf(file, "%s %c (%d, %d): %d\n\n", label, c, x, y, val);           \
    } while (0)

#define WRITE_PIXEL_SUM(fn, label)                                          \
    do                                                                      \
    {                                                                       \
        int x = 0, y = 0, r = 0, g = 0, b = 0;                              \
        (fn)(data, width, height, channels, &x, &y, &r, &g, &b);            \
        fprintf(file, "%s (%d, %d): %d, %d, %d\n\n", label, x, y, r, g, b); \
    } while (0)

    WRITE_PIXEL_SUM(find_max_pixel, "max_pixel");
    WRITE_PIXEL_SUM(find_min_pixel, "min_pixel");

    WRITE_COMPONENT_EXTREME(find_max_component, "max_component", 'R');
    WRITE_COMPONENT_EXTREME(find_max_component, "max_component", 'G');
    WRITE_COMPONENT_EXTREME(find_max_component, "max_component", 'B');

    WRITE_COMPONENT_EXTREME(find_min_component, "min_component", 'R');
    WRITE_COMPONENT_EXTREME(find_min_component, "min_component", 'G');
    WRITE_COMPONENT_EXTREME(find_min_component, "min_component", 'B');

#undef WRITE_COMPONENT_EXTREME
#undef WRITE_PIXEL_SUM

    fclose(file);
    free_image_data(data);

    printf("stat_report.txt généré avec succès.\n");
}
