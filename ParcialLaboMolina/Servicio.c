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
void hardcodearServicios(sServicio listS[], int tamS){
    sServicio auxlistS[] =
    {
        {20000, "Limpieza: $",250},
        {20001, "Ajuste: $",300},
        {20002, "Balanceo: $",17},
        {20003, "Cadena: $",190},
    };

    for(int i=0; i<tamS; i++)
    {
        listS[i] = auxlistS[i];
    }
}
int printServicio(sServicio listS[], int tamS){
    printf("SERVICIOS\n");
    for(int i=0;i<tamS;i++){
        printf("%d |%2s %d\n", listS[i].id, listS[i].descripcion,listS[i].precio);
    }

    return 0;
}
