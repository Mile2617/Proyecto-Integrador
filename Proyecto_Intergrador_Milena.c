#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int main(){
    float pago=0, cambio=0, cobro=0, cobrodomingo=0, cobrofinal=0;
    int hrentrada=0, hrsalida=0, hrdomingo=0, mintotal=0, dia=0, numdias=0, min=0, hrtotal=0, difentrada=0, difsalida=0, repetir=0;
    clock_t inicio = clock();
    do{
        do{
            printf("Ingrese el numero de dias que utilizo el parqueadero: ");
            scanf("%d", &numdias);
        } while (numdias < 1);
        do{
            printf("El o Alguno de los dias que utilizo el parqueadero fue domingo? 1 para si y 2 para no: ");
            scanf("%d", &dia);
        } while (dia != 1 && dia != 2);
        if (numdias == 1){
            if (dia == 1){
                do {
                    printf("Ingrese las horas que utilizo el estacionamiento el domingo con el siguiente formato hhmm: ");
                    scanf("%d", &hrdomingo);
                    if (hrdomingo >= 10 && hrdomingo <= 2459){
                        hrdomingo = hrdomingo;
                    }
                    else{
                        hrdomingo = hrdomingo * 100;
                    }
                    min = hrdomingo % 100;
                    hrdomingo = hrdomingo;
                } while (min >= 60 || ((hrdomingo < 0) || (hrdomingo > 2459)));
                hrtotal = hrdomingo;
                mintotal = hrdomingo % 100;
                hrtotal = hrdomingo - mintotal;
                hrtotal = hrtotal / 100;
                printf("Las horas que ha utilizado el parqueadero el domingo son: %d horas con: %d minutos\n", hrtotal, mintotal);
                cobrodomingo = (10 + ((hrtotal - 1) * 5)) * 0.9;
            }
            else {
                do{
                    do{
                        printf("Ingrese la hora de entrada al estacionamiento con el siguiente formato hhmm: ");
                        scanf("%d", &hrentrada);
                        min = hrentrada % 100;
                        hrentrada = 2459 - hrentrada;
                    } while (min >= 60 || ((hrentrada < 0) || (hrentrada > 2459)));
                    do {
                        printf("Ingrese la hora de salida del estacionamiento con el siguiente formato hhmm: ");
                        scanf("%d", &hrsalida);
                        min = hrsalida % 100;
                        hrsalida = 2459 - hrsalida;
                    } while (min >= 60 || ((hrsalida < 0) || (hrsalida > 2459)));
                } while (hrsalida > hrentrada);
                hrtotal = hrentrada - hrsalida;
                mintotal = hrtotal % 100;
                hrtotal = hrtotal - mintotal;
                hrtotal = hrtotal / 100;
                printf("Las horas que ha utilizado el parqueadero son: %d horas con: %d minutos\n", hrtotal, mintotal);
                cobro = (10 + ((hrtotal - 1) * 5));
                cobrodomingo = 0;
            }
        }
        else {
            if (dia == 1) {
                do{
                    printf("Ingrese la hora de entrada al estacionamiento con el siguiente formato hhmm: ");
                    scanf("%d", &hrentrada);
                    min = hrentrada % 100;
                        hrentrada = 2459 - hrentrada;
                        difentrada = difentrada - 2459;
                    
                } while (min >= 60 || ((hrentrada < 0) || (hrentrada > 2459)));
                do{
                    printf("Ingrese la hora de salida del estacionamiento con el siguiente formato hhmm: ");
                    scanf("%d", &hrsalida);
                    min = hrsalida % 100;
                        hrsalida = 2459 - hrsalida;
                        difsalida = difsalida - 2459;
                } while (min >= 60 || ((hrsalida < 0) || (hrsalida > 2459)));
                do{
                    printf("Ingrese las horas que utilizo el estacionamiento el domingo con el siguiente formato hhmm: ");
                    scanf("%d", &hrdomingo);
                    if (hrdomingo >= 10 && hrdomingo <= 2459){
                        hrdomingo = hrdomingo;
                    }
                    else {
                        hrdomingo = hrdomingo * 100;
                    }
                    min = hrdomingo % 100;
                        hrdomingo = hrdomingo;
                } while (min >= 60 || ((hrdomingo < 0) || (hrdomingo > 2459)));
                hrtotal = (hrentrada - hrsalida) + ((numdias - 3) * 2400);
                mintotal = hrtotal % 100;
                hrtotal = hrtotal - mintotal;
                hrtotal = hrtotal / 100;
                min = hrdomingo % 100;
                hrdomingo = hrdomingo - min;
                hrdomingo = hrdomingo / 100;
                cobro = (10 + ((hrtotal - 1) * 5));
                cobrodomingo = (10 + ((hrdomingo - 1) * 5)) * 0.9;
                printf("Las horas que ha utilizado el parqueadero sin incluir el domingo son: %d horas con: %d minutos\n", hrtotal, mintotal);
                printf("Las horas que ha utilizado el parqueadero el domingo son: %d horas con: %d minutos\n", hrdomingo, min);
                hrtotal = hrtotal * 100 + hrdomingo * 100 + min + mintotal;
                mintotal = hrtotal % 100;
                hrtotal = hrtotal - mintotal;
                hrtotal = hrtotal / 100;
                printf("Las horas que ha utilizado el parqueadero en total son: %d horas con: %d minutos\n", hrtotal, mintotal);
            }
            else{
                do{
                    printf("Ingrese la hora de entrada al estacionamiento con el siguiente formato hhmm: ");
                    scanf("%d", &hrentrada);
                    min = hrentrada % 100;
                     hrentrada = 2459 - hrentrada;
                    difentrada = difentrada - 2459;
                } while (min >= 60 || ((hrentrada < 0) || (hrentrada > 2459)));
                do {
                    printf("Ingrese la hora de salida del estacionamiento con el siguiente formato hhmm: ");
                    scanf("%d", &hrsalida);
                    min = hrsalida % 100;
                        hrsalida = 2459 - hrsalida;
                        difsalida = difsalida - 2459;
                } while (min >= 60 || ((hrsalida < 0) || (hrsalida > 2459)));
                hrtotal = (hrentrada - hrsalida) + ((numdias - 2) * 2400);
                mintotal = hrtotal % 100;
                hrtotal = hrtotal - mintotal;
                hrtotal = hrtotal / 100;
                printf("Las horas que ha utilizado el parqueadero son: %d horas con: %d minutos\n", hrtotal, mintotal);
                cobro = (10 + ((hrtotal - 1) * 5));
                cobrodomingo = 0;
            }
        }
        mintotal = (hrtotal * 60) + mintotal;
        if (mintotal <= 60) {
            if ((mintotal <= 15) && (mintotal > 10)){
                printf("Su valor a pagar del estacionamiento es $3\n");
                cobro = 3;
            }
            if (mintotal <= 10){
                printf("Ha utilizado el estacionamiento menos de 10 min, no se cobrara su estadia\n");
                cobro = 0;
            }
            if (mintotal > 15) {
                printf("Su valor a pagar del estacionamiento es $10\n");
                cobro = 10;
            }
        }
        else {
            cobro = cobro;
        }
        printf("El valor a pagar por el parqueadero el domingo es de (recibe un descuento): %.2f\n", cobrodomingo);
        printf("El valor a pagar por el parqueadero los dias que no son domingo es de: %.2f\n", cobro);
        cobrofinal = cobro + cobrodomingo;
        printf("El valor a pagar por el parqueadero total es de: %.2f\n", cobrofinal);
        do{
            printf("Ingrese el valor con el que va a pagar: ");
            scanf("%f", &pago);
        } while (pago < cobrofinal);
        cambio = pago - cobrofinal;
        printf("Su cambio a pagar es: %f\n", cambio);
        printf("Desea volver a realizar el proceso? 1= si, 2= no: ");
        scanf("%d", &repetir);
    } while (repetir != 2);
    clock_t fin = clock(); 
    double tiempo_transcurrido = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f segundos\n", tiempo_transcurrido);
    getch();
    return 0;
}
