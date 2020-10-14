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

int altaTrabajo(tTrabajo listTrabajo[],mMotos list[],sServicio listS[], int tam, int tamS){
    if(addTrabajo(listTrabajo,list, listS,tam, tamS)==1){
        printf("No hay espacio para agregar un nuevo trabajo\n");
    }else{
        printf("\nSe a ingresado el trabajo con exito!\n");
    }
    return 0;
}

int addTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], int tam, int tamS){
    int isError=1;
    int indice;
    int aux=1;
    tTrabajo auxTrabajo;
    if(listTrabajo!= NULL && tam>0)
    {
        indice = buscarTrabajoLibre(listTrabajo, tam);
        if(indice!= -1){
            auxTrabajo.id=tam++;

            auxTrabajo.isEmpty = FALSE;
                printf("Ingrese ID Moto: ");
                scanf("%d", &aux);
                auxTrabajo.idMoto=aux;
                printf("Ingrese ID Servicio: ");
                scanf("%d", &aux);
                auxTrabajo.idServicio=aux;

            listTrabajo[indice]= auxTrabajo;

            isError=0;
        }
    }
    return isError;
}
int buscarTrabajoLibre(tTrabajo listTrabajo[], int tam){
    int aux=-1;

    for(int i=0; i<tam; i++){
        if(listTrabajo[i].isEmpty == TRUE){
            aux = i;
            break;
        }
    }
    return aux;
}
