#ifndef INFORMES_H
#define INFORMES_H

int menuInformes(char mensaje[]);

int printTipoMotos(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC);

int informesMenu(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],int tam,int tamT,int tamC,int tamS);

int printColorMotos(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC);

int motoMayorCilindrada(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC);

int printPorTiposMotos(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC);

int printColoryTipoMoto(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC);

int colorMayor(mMotos list[],cColor listC[],int tam,int tamC);

int printTrabajosMotos(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],int tam,int tamT,int tamC,int tamS);

int printSumaServicios(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],int tam,int tamT,int tamC,int tamS);

int printMotosServicios(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],int tam,int tamT,int tamC,int tamS);

int devolverIdMotoInforme(mMotos list[],int tam,int idMoto);

#endif // INFORMES_H
