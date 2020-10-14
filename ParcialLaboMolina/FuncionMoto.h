#include "Color.h"
#include "Tipo.h"
#include "Validaciones.h"
typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
}mMotos;

int initMotos(mMotos list[], int tam);

int altaMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT);

int addMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT);

int buscarMotoLibre(mMotos list[], int tam);

int menuPrincipal(char mensaje[]);

int imprimirMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag);

int printMoto(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag);

int flagAlta(int flag);

int bajaMoto(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag);

int removeMoto(mMotos list[], int tam, int id);

int findMotoById(mMotos list[], int tam, int id);

int modifyMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT,int id);

int modificarMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT,int flag);

int ordenamientoEmpleados(mMotos list[], int tam, int orden);

