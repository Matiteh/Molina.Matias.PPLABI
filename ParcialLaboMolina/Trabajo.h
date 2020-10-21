#ifndef TRABAJO_H
#define TRABAJO_H
#include "Fecha.h"
typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    fFecha Fecha;
    int isEmpty;
}tTrabajo;

#include "Servicio.h"

int initTrabajos(tTrabajo listTrabajo[], int tam);

int altaTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], cColor listC[],tTipo listT[], int tam, int tamS, int tamC, int tamT, int flag,int* id);

int addTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], cColor listC[],tTipo listT[], int tam, int tamS, int tamC, int tamT,int** id);

int buscarTrabajoLibre(tTrabajo listTrabajo[], int tam);

int printTrabajos(tTrabajo listTrabajo[], sServicio listS[], int tam, int tamS, int flag, int flagTrabajo);

int flagAltaTrabajo(int flag);


#endif // TRABAJO_H
