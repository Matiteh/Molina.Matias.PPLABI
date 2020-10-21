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
int initTrabajos(tTrabajo listTrabajo[], int tam){
    if(listTrabajo!= NULL && tam>0){
        for(int i=0; i<tam; i++)
        {
            listTrabajo[i].isEmpty=TRUE;

        }
    }
    return 0;
}
int altaTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], cColor listC[],tTipo listT[], int tam, int tamS, int tamC, int tamT, int flag,int* id){
    int flagTrabajo=0;
    if(flag!=0){
        if(addTrabajo(listTrabajo,list, listS,listC,listT,tam, tamS,tamC,tamT,&id)==1){
            printf("No hay espacio para agregar un nuevo trabajo\n");
        }else{
            printf("\nSe a ingresado el trabajo con exito!\n");
        }
    }else{
        flagAlta(flag);
    }

    return flagTrabajo;
}

int addTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], cColor listC[],tTipo listT[], int tam, int tamS, int tamC, int tamT,int** id){
    int isError=1;
    int indice;
    int aux=1;
    int auxA=1;
    tTrabajo auxTrabajo;
    if(listTrabajo!= NULL && tam>0){
        indice = buscarTrabajoLibre(listTrabajo, tam);
        if(indice!= -1){
            (**id)++;
            auxTrabajo.id=**id;
            auxTrabajo.isEmpty = FALSE;
            do{
                printMoto(list,listC,listT,tam,tamC,tamT);
                printf("Ingrese ID Moto: ");
                scanf("%d", &aux);
                system("cls");
                auxA=findMotoById(list, tam, aux);
                if(auxA==-1){
                    printf("No se encontro la moto\n");
                }else{
                    auxTrabajo.idMoto=aux;
                }
            }while(auxA==-1);
            do{
                printServicio(listS,tamS);
                printf("Ingrese ID Servicio: ");
                scanf("%d", &aux);
                system("cls");
                auxTrabajo.idServicio=aux;
            }while(validacionServicio(aux)!=0);
            do{
                printf("Ingrese Dia: ");
                scanf("%d", &aux);
                system("cls");
                auxTrabajo.Fecha.dia=aux;
            }while(validacionDia(aux)!=0);
            do{
                printf("Ingrese Mes: ");
                scanf("%d", &aux);
                system("cls");
                auxTrabajo.Fecha.mes=aux;
            }while(validacionMes(aux)!=0);
            do{
                printf("Ingrese ano: ");
                scanf("%d", &aux);
                system("cls");
                auxTrabajo.Fecha.ano=aux;
            }while(validacionAno(aux)!=0);

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
int printTrabajos(tTrabajo listTrabajo[], sServicio listS[], int tam, int tamS, int flag, int flagTrabajo){
    int opcion=0;
    if(flag!=0 && flagTrabajo!=0){
        do{
                printf("ID Trabajo |ID Moto |Servicio       |Fecha\n");
                for(int i=0;i<tam;i++){
                    if(listTrabajo[i].isEmpty==FALSE){
                        printf("%10d |%7d |%s%d |%d/%d/%d\n",listTrabajo[i].id, listTrabajo[i].idMoto, listS[devolverDescripcion(listTrabajo,listS,tamS,i)].descripcion,listS[devolverDescripcion(listTrabajo,listS,tamS,i)].precio, listTrabajo[i].Fecha.dia, listTrabajo[i].Fecha.mes, listTrabajo[i].Fecha.ano);
                    }
                }
                opcion=3;
        }while(opcion != 3);
    }else{
        flagAltaTrabajo(flagTrabajo);
    }
    return 0;
}
int flagAltaTrabajo(int flag){
    if(flag==0){
        printf("No se puede usar esta opcion hasta que se realize la primera ALTA de Trabajos\n");
    }
    return 0;
}

