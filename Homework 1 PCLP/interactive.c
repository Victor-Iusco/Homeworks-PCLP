#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"
#include "imageprocessing.h"

#define MAXIMUM_COMANDA 3
#define MAXIMUMFILTRU 10
#define MAXIMAGINI 15
#define MAXLUNGIMEDEST 100
#define MAXLUNGIME 50

void dealocare_imagine(int ***image, int N, int M);
void dealocare_filtru(float **filter, int size);

int main() {
  int ****images = (int ****)malloc(MAXIMAGINI * sizeof(int ***));
  float ***filters = (float ***)malloc(MAXIMAGINI * sizeof(float **));
  int imageCount = 0, filterCount = 0;
  int N[MAXIMAGINI], M[MAXIMAGINI], F_Dim[MAXIMAGINI];

  while (1) {
    char command[MAXLUNGIMEDEST];
    scanf("%s", command);

    if (strcmp(command, "e") == 0) {
      break;
    }

    if (strcmp(command, "l") == 0) {
      char n[MAXLUNGIME], m[MAXLUNGIME], path[MAXLUNGIMEDEST];
      scanf("%s %s %s", n, m, path);
      N[imageCount] = atoi(n);
      M[imageCount] = atoi(m);

      int ***img = (int ***)malloc(N[imageCount] * sizeof(int **));
      for (int i = 0; i < N[imageCount]; i++) {
        img[i] = (int **)malloc(M[imageCount] * sizeof(int *));
        for (int j = 0; j < M[imageCount]; j++) {
          img[i][j] = (int *)malloc(MAXIMUM_COMANDA * sizeof(int));
        }
      }

      read_from_bmp(img, N[imageCount], M[imageCount], path);
      images[imageCount] = img;
      imageCount++;
    }

    if (strcmp(command, "s") == 0) {
      char s[MAXLUNGIME], path[MAXLUNGIMEDEST];
      scanf("%s%s", s, path);
      int index = atoi(s);
      write_to_bmp(images[index], N[index], M[index], path);
    }

    if (strcmp(command, "ah") == 0) {
      char s[MAXLUNGIME];
      scanf("%s", s);
      int index = atoi(s);
      images[index] = flip_horizontal(images[index], N[index], M[index]);
    }

    if (strcmp(command, "ar") == 0) {
      char s[MAXLUNGIME];
      scanf("%s", s);
      int index = atoi(s);
      images[index] = rotate_left(images[index], N[index], M[index]);
      int temp = N[index];
      N[index] = M[index];
      M[index] = temp;
    }

    if (strcmp(command, "ac") == 0) {
      char a1[MAXLUNGIME], a2[MAXLUNGIME], a3[MAXLUNGIME],
          a4[MAXLUNGIME], a5[MAXLUNGIME];
      scanf("%s%s%s%s%s", a1, a2, a3, a4, a5);
      int index = atoi(a1);
      int x = atoi(a2);
      int y = atoi(a3);
      int w = atoi(a4);
      int h = atoi(a5);
      images[index] = crop(images[index], N[index], M[index], x, y, h, w);
      N[index] = h;
      M[index] = w;
    }

    if (strcmp(command, "ae") == 0) {
      char a1[MAXLUNGIME], a2[MAXLUNGIME], a3[MAXLUNGIME],
          a4[MAXLUNGIME], a5[MAXLUNGIME], a6[MAXLUNGIME];
      scanf("%s%s%s%s%s%s", a1, a2, a3, a4, a5, a6);
      int index = atoi(a1);
      int rows = atoi(a2);
      int cols = atoi(a3);
      int R = atoi(a4);
      int G = atoi(a5);
      int B = atoi(a6);
      images[index] = extend(images[index], N[index], M[index], rows, cols, R, G, B);
      N[index] = N[index] + 2 * rows;
      M[index] = M[index] + 2 * cols;
    }

    if (strcmp(command, "ap") == 0) {
      char a1[MAXLUNGIME], a2[MAXLUNGIME], a3[MAXLUNGIME],
          a4[MAXLUNGIME];
      scanf("%s%s%s%s", a1, a2, a3, a4);
      int indexDst = atoi(a1);
      int indexSrc = atoi(a2);
      int x = atoi(a3);
      int y = atoi(a4);
      images[indexDst] = paste(images[indexDst], N[indexDst], M[indexDst],
                                images[indexSrc], N[indexSrc], M[indexSrc], x, y);
    }

    if (strcmp(command, "cf") == 0) {
      char s[MAXLUNGIME];
      scanf("%s", s);
      int size = atoi(s);

      float **fil = (float **)malloc(size * sizeof(float *));
      for (int i = 0; i < size; i++) {
        fil[i] = (float *)malloc(size * sizeof(float));
        for (int j = 0; j < size; j++) {
          char nr[MAXLUNGIME];
          scanf("%s", nr);
          fil[i][j] = (float)atof(nr);
        }
      }

      filters[filterCount] = fil;
      F_Dim[filterCount] = size;
      filterCount++;
    }

    if (strcmp(command, "af") == 0) {
      char a1[MAXLUNGIME], a2[MAXLUNGIME];
      scanf("%s%s", a1, a2);
      int imagineindex = atoi(a1);
      int indexFilter = atoi(a2);
      images[imagineindex] = apply_filter(images[imagineindex], N[imagineindex], M[imagineindex],
                                       filters[indexFilter], F_Dim[indexFilter]);
    }

    if (strcmp(command, "df") == 0) {
      char s[MAXLUNGIME];
      scanf("%s", s);
      int indexFilter = atoi(s);

      dealocare_filtru(filters[indexFilter], F_Dim[indexFilter]);

      for (int i = indexFilter; i < filterCount - 1; i++) {
        filters[i] = filters[i + 1];
        F_Dim[i] = F_Dim[i + 1];
      }

      filterCount--;
    }

    if (strcmp(command, "di") == 0) {
      char s[MAXLUNGIME];
      scanf("%s", s);
      int imagineindex = atoi(s);

      dealocare_imagine(images[imagineindex], N[imagineindex], M[imagineindex]);

      for (int i = imagineindex; i < imageCount - 1; i++) {
        images[i] = images[i + 1];
        N[i] = N[i + 1];
        M[i] = M[i + 1];
      }

      imageCount--;
    }
  }

  for (int img = 0; img < imageCount; img++) {
    dealocare_imagine(images[img], N[img], M[img]);
  }
  free(images);

  for (int fil = 0; fil < filterCount; fil++) {
    dealocare_filtru(filters[fil], F_Dim[fil]);
  }
  free(filters);

  return 0;
}

void dealocare_imagine(int ***image, int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      free(image[i][j]);
    }
    free(image[i]);
  }
  free(image);
}
void dealocare_filtru(float **filter, int size) {
  for (int i = 0; i < size; i++) {
    free(filter[i]);
  }
  free(filter);
}
