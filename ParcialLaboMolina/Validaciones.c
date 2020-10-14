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
int validacionId(int aux){
    int isError=1;
    if(aux>0){
        isError=0;
    }else{
        printf("ID Invalida!\n");
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
int validacionFecha(fFecha listF){
    int isError=1;
    if(listF.ano>2019 && (listF.dia>0 && listF.dia<32)&& (listF.mes>0 && listF.mes<13)){
        isError=0;
    }else{
        printf("Fecha Incorrecta!\n");
    }
    return isError;
}
