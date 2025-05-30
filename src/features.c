#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

void helloWorld() {
    printf("Hello World !");
}
void dimension(char* filename) {
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
    } else {
        printf("dimension: %d, %d\n", width, height);
        free_image_data(data);
    }
}
void tenth_pixel(char *source_path) {
    unsigned char *data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
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