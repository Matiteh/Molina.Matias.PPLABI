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
int validacionTipo(int aux){
    int isError=1;
    if(aux>999 && aux<1004){
        isError=0;
    }else{
        printf("Tipo Incorrecto!\n");
    }
    return isError;
}
int validacionId(mMotos list[],int tam, int aux){
    int isError=1;
    for (int i=0;i<tam;i++){
        if(aux>0 && (aux != list[i].id)){
            isError=0;
        }else{
            printf("ID Invalida!\n");
            isError=1;
            break;
        }
    }

    return isError;
}

int validacionColor(int aux){
    int isError=1;
    if(aux>9999 && aux<10005){
        isError=0;
    }else{
        printf("Color Incorrecto!\n");
    }
    return isError;
}

char* validacionMarcaMoto(char marcaMoto[]){

    strlwr(marcaMoto);
    marcaMoto[0]=toupper(marcaMoto[0]);

    for(int i=0;i<strlen(marcaMoto);i++){
        if(marcaMoto[i]==' '){
            marcaMoto[i+1]=toupper(marcaMoto[i+1]);
           }
    }
    return marcaMoto;
}
int validacionAno(int aux){
    int isError=1;
    if(aux>2019){
        isError=0;
    }else{
        printf("Ano Incorrecto!\n");
    }
    return isError;
}
int validacionDia(int aux){
    int isError=1;
    if(aux>0 && aux<32){
        isError=0;
    }else{
        printf("Dia Incorrecto!\n");
    }
    return isError;
}
int validacionMes(int aux){
    int isError=1;
    if(aux>0 && aux<13){
        isError=0;
    }else{
        printf("Mes Incorrecto!\n");
    }
    return isError;
}
int validacionCilindrada(int aux){
    int isError=1;
    if(aux!= 50 && aux!= 125 && aux!= 500 && aux!= 600 && aux!= 750){
        printf("Cilindrada Incorrecta!\n");
    }else{
        isError=0;
    }
    return isError;
}
int validacionServicio(int aux){
    int isError=1;
    if(aux>19999 && aux<20004){
        isError=0;
    }else{
        printf("Servicio Incorrecto!\n");
    }
    return isError;
}
