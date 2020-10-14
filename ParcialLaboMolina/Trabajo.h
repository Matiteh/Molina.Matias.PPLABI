#ifndef TRABAJO_H
#define TRABAJO_H
typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    int Fecha;
    int isEmpty;
}tTrabajo;

int addTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], int tam, int tamS);

int altaTrabajo(tTrabajo listTrabajo[],mMotos list[],sServicio listS[], int tam, int tamS);

int buscarTrabajoLibre(tTrabajo listTrabajo[], int tam);
#endif // TRABAJO_H
