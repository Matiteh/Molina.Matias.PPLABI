#ifndef COLOR_H
#define COLOR_H
typedef struct
{
    int id;
    char nombreColor[21];
}cColor;

int printColor(cColor listC[], int tamC);

void hardcodearColor(cColor listC[], int tamC);

int printColorImprimir(mMotos list[], cColor listC[], int tamC, int aux);

int devolverIdColorInforme(cColor listC[],int tamC,int color);

#endif // COLOR_H
