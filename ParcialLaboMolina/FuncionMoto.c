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

int menuPrincipal(char mensaje[]){
    int opcion;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}

int initMotos(mMotos list[], int tam){
    if(list!= NULL && tam>0){
        for(int i=0; i<tam; i++)
        {
            list[i].isEmpty=TRUE;

        }
    }
    return 0;
}
int altaMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT){
    if(addMotos(list,listC,listT,tam,tamC,tamT)==1){
        printf("No hay espacio para agregar una nueva moto\n");
    }else{
        printf("\nSe a ingresado la moto con exito!\n");
    }
    return 0;
}

int addMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT){
    int isError=1;
    int indice;
    int aux=1;
    mMotos nuevaMoto;
    if(list!= NULL && tam>0)
    {
        indice = buscarMotoLibre(list, tam);
        if(indice!= -1){

            nuevaMoto.isEmpty = FALSE;
            do{
                printf("Ingrese ID: ");
                scanf("%d", &aux);
                nuevaMoto.id=aux;
            }while(validacionId(aux)!=0);

            do{
                printTipo(listT,tamT);
                printf("Ingrese Tipo: ");
                scanf("%d", &aux);
                nuevaMoto.idTipo=aux;
            }while(validacionTipo(aux)!=0);
            printf("Ingrese Marca de moto: ");
            fflush(stdin);
            gets(nuevaMoto.marca);
            strcpy(validacionMarcaMoto(nuevaMoto.marca), nuevaMoto.marca);
            do{
                printColor(listC,tamC);
                printf("Ingrese Color: ");
                scanf("%d", &aux);
                nuevaMoto.idColor=aux;
            }while(validacionColor(aux)!=0);
            printf("Ingrese Cilindrada 50/125/500/600/750: ");
            scanf("%d", &aux);
            nuevaMoto.cilindrada=aux;

            list[indice]= nuevaMoto;

            isError=0;
        }
    }
    return isError;
}

int buscarMotoLibre(mMotos list[], int tam){
    int aux=-1;

    for(int i=0; i<tam; i++){
        if(list[i].isEmpty == TRUE){
            aux = i;
            break;
        }
    }
    return aux;
}

int imprimirMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag){
    int opcion=0;
    if(flag!=0){
        do{
                printf("ID |Tipo  |Marca  |Cilindrada |Color\n");
                for(int i=0;i<tam;i++){
                    if(list[i].isEmpty==FALSE){
                        printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[i].descripcion, list[i].marca, list[i].cilindrada, listC[i].nombreColor);
                    }
                }

                /*opcion=menuPrincipal("\n1.ASCENDENTE\n2.DESCENDENTE\n3.MENU PRINCIPAL\n");

                switch(opcion){

                    case 1:
                        opcion=ordenamientoEmpleados(list, tam, opcion);
                        break;

                    case 2:
                        opcion=ordenamientoEmpleados(list, tam, opcion);
                        break;

                    case 3:
                        opcion=3;
                        break;
                }*/
                system("pause");
                system("cls");
                opcion=3;
        }while(opcion != 3);
    }else{
        flagAlta(flag);
    }
    return 0;
}


int flagAlta(int flag){
    if(flag==0){
        printf("No se puede usar esta opcion hasta que se realize la primera ALTA\n");
    }
    return 0;
}

int bajaMoto(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag){
    int aux;
    if(flag!=0){
        printMoto(list,listC,listT, tam,tamC,tamT, flag);
        printf("\nIngrese el ID de la moto a dar de baja: ");
        scanf("%d", &aux);
        aux=removeMoto(list,tam, aux);
        if(aux==0){
            printf("No se a encontrado la moto\n");
        }else if(aux==1){
            printf("Se cancelo la baja de la moto\n");
        }else{
            printf("La baja se realizo con exito!\n");
            flag--;
        }
    }else{
        flagAlta(flag);
    }
    return flag;
}
int removeMoto(mMotos list[], int tam, int id){
    char resp;
    int encontrado=0;
    int aux;
    aux=findMotoById(list, tam, id);
    if(aux!=-1){
        encontrado=-1;
        printf("\nEsta seguro que desea dar de baja la moto %d %s?(s|n) ",list[aux].id ,list[aux].marca);
        fflush(stdin);
        scanf("%c", &resp);
        if(resp=='n'){

            encontrado=1;

        }else{

            list[aux].isEmpty=TRUE;
        }
    }
    return encontrado;
}

int findMotoById(mMotos list[], int tam, int id){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if(list[i].id==id && list[i].isEmpty==FALSE){
            indice=i;
            break;
        }
    }
    return indice;
}

int printMoto(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT, int flag){
    if(flag!=0){
        printf("ID |Tipo  |Marca  |Cilindrada |Color\n");
        for(int i=0;i<tam;i++){
            if(list[i].isEmpty==FALSE){
                printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[i].descripcion, list[i].marca, list[i].cilindrada, listC[i].nombreColor);
            }
        }
    }else{
        flagAlta(flag);
    }

    return 0;
}

int modificarMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT,int flag){
    int aux;
    if(flag!=0){
        printMoto(list,listC,listT, tam,tamC,tamT, flag);
        printf("\nIngrese el ID de la moto a modificar: ");
        fflush(stdin);
        scanf("%d", &aux);
        system("cls");
        aux=modifyMotos(list,listC,listT, tam,tamC,tamT, aux);
        if(aux==0){
            printf("No se a encontrado la moto\n");
            system("pause");
        }else if(aux==1){
        }else{
            printf("La modificacion se realizo con exito!\n");
            system("pause");
        }
    }else{
        flagAlta(flag);
        system("pause");
    }
    return 0;
}

int modifyMotos(mMotos list[], cColor listC[], tTipo listT[], int tam, int tamC, int tamT,int id){
    int aux;
    int encontrado=0;
    int menu;
    char conf='s';
    aux=findMotoById(list, tam, id);
    if(aux!=-1){
        encontrado=-1;
        do{

            printf("MENU MODIFICAR MOTO\n1.COLOR\n2.CILINDRADA\n3.MENU PRINCIPAL\n");

            fflush(stdin);

            scanf("%d", &menu);

            switch(menu){

                case 1:
                    printColor(listC,tamC);
                    printf("Ingrese nuevo color: ");
                    scanf("%d", &list[aux].idColor);
                    break;

                case 2:
                    printf("Ingrese nueva cilindrada 50/125/500/600/750: ");
                    scanf("%d", &list[aux].cilindrada);
                    break;

                case 3:
                    conf='n';
                    encontrado=1;
                    break;
            }
            if(menu!=5){
                printf("Desea realizar otro cambio a la moto?(s|n) \n");
                fflush(stdin);
                scanf("%c",&conf);
                system("cls");
            }

        }while (menu!=3 && conf!='n');
    }else{
        list[aux].isEmpty=TRUE;
    }
    return encontrado;
}

/*int ordenamientoEmpleados(eEmployee list[], int tam, int orden){
    int comp;
    eEmployee auxEmpleado;

    switch(orden){
        case 1:
            for(int i=0;i<tam-1;i++){
                if(list[i].isEmpty == FALSE){
                    for(int j=i+1;j<tam;j++){
                        if(list[j].isEmpty == FALSE){
                            comp=stricmp(list[i].apellido,list[j].apellido);
                            if(comp>=0 && list[i].sector==list[j].sector){
                                auxEmpleado=list[i];
                                list[i]=list[j];
                                list[j]=auxEmpleado;
                            }
                        }
                    }
                }

            }
            break;

        case 2:
            for(int i=0;i<tam-1;i++){
                if(list[i].isEmpty == FALSE){
                    for(int j=i+1;j<tam;j++){
                        if(list[j].isEmpty == FALSE){
                            comp=stricmp(list[i].apellido,list[j].apellido);
                            if(comp<=0 && list[i].sector==list[j].sector){
                                auxEmpleado=list[i];
                                list[i]=list[j];
                                list[j]=auxEmpleado;
                            }
                        }
                    }
                }

            }
            break;
    }

    return orden;
}*/

