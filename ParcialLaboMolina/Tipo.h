#ifndef TIPO_H
#define TIPO_H

typedef struct
{
    int id;
    char descripcion[21];
}tTipo;

int printTipo(tTipo listT[], int tamT);

void hardcodearTipos(tTipo listT[], int tamT);

int devolverIdTipo(mMotos list[],tTipo listT[],int tamT,int i);

int devolverIdTipoInforme(tTipo listT[],int tamT,int tipo);

#endif // TIPO_H
