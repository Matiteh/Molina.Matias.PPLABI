#ifndef COLOR_H
#define COLOR_H
typedef struct
{
    int id;
    char nombreColor[21];
}cColor;

int printColor(cColor listC[], int tamC);

void hardcodearColor(cColor listC[], int tamC);
#endif // COLOR_H
