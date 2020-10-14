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
void hardcodearTipos(tTipo listT[], int tamT){
    tTipo auxlistT[] =
    {
        {1000, "Enduro"},
        {1001, "Chopera"},
        {1002, "Scooter"},
        {1003, "Ciclomotor"},
    };

    for(int i=0; i<tamT; i++)
    {
        listT[i] = auxlistT[i];
    }
}

int printTipo(tTipo listT[], int tamT){
    printf("TIPOS\n");
    for(int i=0;i<tamT;i++){
        printf("%d |%2s\n", listT[i].id, listT[i].descripcion);
    }

    return 0;
}

