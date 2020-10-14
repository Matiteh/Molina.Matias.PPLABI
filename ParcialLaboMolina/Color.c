#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionMoto.h"
#include "Color.h"
#include "Tipo.h"
#include "Validaciones.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"
#define TRUE 1
#define FALSE 0
void hardcodearColor(cColor listC[], int tamC){
    cColor auxlistC[] =
    {
        {10000, "Gris"},
        {10001, "Negro"},
        {10002, "Blanco"},
        {10003, "Azul"},
        {10004, "Rojo"},
    };
    for(int i=0; i<tamC; i++)
    {
        listC[i] = auxlistC[i];
    }
}

int printColor(cColor listC[], int tamC){
    printf("COLORES\n");
    for(int i=0;i<tamC;i++){
        printf("%d |%2s\n", listC[i].id, listC[i].nombreColor);
    }

    return 0;
}
