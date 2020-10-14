#ifndef SERVICIO_H
#define SERVICIO_H
typedef struct
{
    int id;
    char descripcion[21];
    int precio;
}sServicio;

int printServicio(sServicio listS[], int tamS);

void hardcodearServicios(sServicio listS[], int tamS);
#endif // SERVICIO_H
