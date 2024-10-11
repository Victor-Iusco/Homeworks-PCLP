#include <stdio.h>
#include <stdlib.h>
#include "imageprocessing.h"
#define MAXIMUM_RGB 255
#define MINUMUM_RGB 0

// Task 1
int ***flip_horizontal(int ***image, int N, int M) {
    int ***flipped_orizontal = malloc(N * sizeof(int **));
    for (int i = 0; i < N; i++) {
        flipped_orizontal[i] = malloc(M * sizeof(int *));
        for (int j = 0; j < M; j++) {
            flipped_orizontal[i][j] = malloc(3 * sizeof(int));
            for (int k = 0; k < 3; k++) {
                flipped_orizontal[i][j][k] = image[i][M - 1 - j][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return flipped_orizontal;
}

// Task 2
int ***rotate_left(int ***image, int N, int M) {
    int ***flipped_stanga = malloc(M * sizeof(int **));
    for (int i = 0; i < M; i++) {
        flipped_stanga[i] = malloc(N * sizeof(int *));
        for (int j = 0; j < N; j++) {
            flipped_stanga[i][j] = malloc(3 * sizeof(int));
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 3; k++) {
                flipped_stanga[M - 1 - j][i][k] = image[i][j][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return flipped_stanga;
}

// Task 3
int ***crop(int ***image, int N, int M, int x, int y, int h, int w) {
    int ***cropped_image = malloc(h * sizeof(int **));

    for (int i = 0; i < h; i++) {
        cropped_image[i] = malloc(w * sizeof(int *));
        for (int j = 0; j < w; j++) {
            cropped_image[i][j] = malloc(3 * sizeof(int));
            for (int k = 0; k < 3; k++) {
                cropped_image[i][j][k] = image[i + y][j + x][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return cropped_image;
}

// Task 4
int ***extend(int ***image, int N, int M, int rows, int cols, int new_R, int new_G, int new_B) {
    int ***extended_image = malloc ((2 * rows + N) * sizeof(int **));
    for (int i = 0; i < 2 * rows + N; i++) {
        extended_image[i] = malloc ((2 * cols + M) * sizeof(int *));
        for (int j = 0; j < 2*cols + M; j++) {
            extended_image[i][j] = malloc (3 * sizeof(int));
        }
    }
    for (int i = 0; i < 2 * rows + N; i ++) {
        for (int j = 0; j < 2 * cols + M; j ++) {
            for (int k = 0; k < 3; k ++) {
                if (i < rows || i >= rows+N || j < cols || j >= cols+M) {
                    extended_image[i][j][0] = new_R;
                    extended_image[i][j][1] = new_G;
                    extended_image[i][j][2] = new_B;
                } else {
                    extended_image[i][j][k] = image[i-rows][j-cols][k];
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return extended_image;
}

// Task 5
int ***paste(int ***image_dst, int N_dst, int M_dst, int *** image_src, int N_src, int M_src, int x, int y) {
      for (int i = 0; i < N_src; i++) {
        for (int j = 0; j < M_src; j++) {
            for (int k = 0; k < 3; k++) {
                if (j < M_dst - x && i < N_dst - y) {
                    image_dst[y + i][x + j][k] = image_src[i][j][k];
                }
            }
        }
    }
    return image_dst;
    for (int i = 0; i < N_src; i++) {
        for (int j = 0; j < M_src; j++) {
            free(image_src[i][j]);
        }
        free(image_src[i]);
    }
    free(image_src);
}

// Task 6
int ***apply_filter(int ***image, int N, int M, float **filter, int filter_size) {
    int ***filter_applied = (int ***)malloc(N * sizeof(int **));
    if (filter_applied == NULL) {
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        filter_applied[i] = (int **)malloc(M * sizeof(int *));
        if (filter_applied[i] == NULL) {
            for (int x = 0; x < i; x++)
                free(filter_applied[x]);
            free(filter_applied);
            return NULL;
        }

        for (int j = 0; j < M; j++) {
            filter_applied[i][j] = (int *)malloc(3 * sizeof(int));
            if (filter_applied[i][j] == NULL) {
                for (int x = 0; x < i; x++) {
                    for (int y = 0; y < M; y++) {
                        free(filter_applied[x][y]);
                    }
                    free(filter_applied[x]);
                }
                free(filter_applied);
                return NULL;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 3; k++) {
                float aux = 0;
                for (int a = i - filter_size / 2; a < i + 1 + filter_size / 2; a++) {
                    for (int b = j - filter_size / 2; b < j + 1 + filter_size / 2; b++) {
                        if (a >= 0 && b >= 0 && a < N && b < M) {
                            aux += (float)image[a][b][k] * filter[a - i + filter_size / 2][b - j + filter_size / 2];
                        }
                    }
                }
                filter_applied[i][j][k] = (int)aux;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 3; k++) {
                filter_applied[i][j][k] = (filter_applied[i][j][k] > MAXIMUM_RGB) ? MAXIMUM_RGB :
                (filter_applied[i][j][k] < MINUMUM_RGB) ? MINUMUM_RGB : filter_applied[i][j][k];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
    return filter_applied;
}
