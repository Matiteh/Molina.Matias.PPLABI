#ifndef FuncionMoto_h
#define FuncionMoto_h




typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
}mMotos;
#include "Color.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Informes.h"
int initMotos(mMotos list[], int tam);

int altaMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT);

int addMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT);

int buscarMotoLibre(mMotos list[], int tam);

int menuPrincipal(char mensaje[]);

int imprimirMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag);

int printMoto(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT);

int flagAlta(int flag);

int bajaMoto(mMotos list[], cColor listC[], tTipo listT[],tTrabajo listTrabajo[], int tam, int tamC, int tamT, int flag);

int removeMoto(mMotos list[],tTrabajo listTrabajo[], int tam, int id);

int findMotoById(mMotos list[], int tam, int id);

int modifyMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT,int id);

int modificarMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT,int flag);

int ordenamientoFecha(tTrabajo listTrabajo[], int tam);

int sumaFecha(tTrabajo listTrabajo[], int i);


#endif // FuncionMoto_h
