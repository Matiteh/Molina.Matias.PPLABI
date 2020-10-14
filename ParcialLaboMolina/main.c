#include <stdio.h>
#include <stdlib.h>
#include "FuncionMoto.h"
#include "Color.h"
#include "Tipo.h"
#include "Validaciones.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"
#define TAM 1000
#define TAMC 5
#define TAMT 4
#define TAMS 4
#define TAMF 1
int main()
{
    int initID=1000;
    mMotos list[TAM];
    cColor listC[TAMC];
    tTipo listT[TAMT];
    sServicio listS[TAMS];
    tTrabajo listTrabajo[TAM];
    fFecha listF[TAMF];
    char conf='s';
    int opcion;
    int flag=0;
    initMotos(list, TAM);
    hardcodearColor(listC,TAMC);
    hardcodearTipos(listT,TAMT);
    do{
            opcion=menuPrincipal("ABM Service Motos\n1.ALTA MOTO\n2.BAJA MOTO\n3.MODIFICAR MOTO\n4.IMPRIMIR MOTO\n5.LISTAR TIPO\n6.LISTAR COLOR\n7.LISTAR SERVICIO\n8.ALTA TRABAJO\n10.SALIR\n");

            switch(opcion){

                case 1:/*ALTA*/
                    altaMotos(list,listC,listT, TAM,TAMC,TAMT);
                    initID++;
                    flag++;
                    system("pause");
                    break;

                case 2:/*BAJA*/
                    flag=bajaMoto(list,listC,listT, TAM,TAMC,TAMT, flag);
                    system("pause");
                    break;



                case 3:/*MODIFICAR*/
                    modificarMotos(list,listC,listT, TAM,TAMC,TAMT, flag);
                    break;



                case 4:/*INFORMAR*/
                    imprimirMotos(list,listC,listT, TAM,TAMC,TAMT, initID);
                    system("pause");
                    break;

                case 5:/*LISTAR TIPO*/
                    printTipo(listT,TAMT);
                    system("pause");
                    break;

                case 6:/*LISTAR COLOR*/
                    printColor(listC,TAMC);
                    system("pause");
                    break;

                case 7:/*LISTAR SERVICIO*/
                    printServicio(listS,TAMS);
                    system("pause");
                    break;

                case 8:/*ALTA TRABAJO*/
                    altaTrabajo(listTrabajo,list,listS,TAM,TAMS);
                    system("pause");
                    break;

                case 9:/*LISTAR TRABAJO*/

                    break;

                case 10:/*SALIR*/
                    conf='n';
                    break;

                default:

                    break;
                }
                system("cls");
        }while (conf!='n');

}
