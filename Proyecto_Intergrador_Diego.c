#include <stdio.h>
#include <time.h>
 
float calcularPago(int minutos, int horas) {
    float costoTotal = 0;
 
    if (minutos <= 10) {
        costoTotal = 0;
    } else if (minutos <= 25) {
        costoTotal = 3;
    } else {
        costoTotal = 10 + (horas - 1) * 5;
    }
 
    if (horas >= 2 && minutos > 10) {
        costoTotal += 5 * (horas - 1);
    }
 
    return costoTotal;
}
 
int main() {
    clock_t inicio = clock();
 
    while (1) {
        int minutos, horas;
        float totalAPagar, montoRecibido=0, cambio;
 
        printf("Ingrese la cantidad de minutos estacionados: ");
        scanf("%d", &minutos);
 
        printf("Ingrese la cantidad de horas estacionadas: ");
        scanf("%d", &horas);
 
        totalAPagar = calcularPago(minutos, horas);
 
        char esDomingo;
        printf("¿Es domingo? (Sí/No): ");
        scanf(" %c", &esDomingo);
 
        if (esDomingo == 'S' || esDomingo == 's') {
            float descuento = totalAPagar * 0.1;
            totalAPagar -= descuento;
            printf("Se aplicó un descuento del 10%%: $%.2f\n", descuento);
        }
 
        printf("El total a pagar es: $%.2f\n", totalAPagar);
 
    
        do {
            printf("Ingrese el monto recibido: ");
            scanf("%f", &montoRecibido);
 
            if (montoRecibido < totalAPagar) {
                printf("El monto recibido es insuficiente. Intente nuevamente.\n");
            }
        } while (montoRecibido < totalAPagar);
 
        cambio = montoRecibido - totalAPagar;
 
        printf("El cambio a entregar es: $ %.2f\n", cambio);
 
        char otraTransaccion;
        printf("¿Desea realizar otra transacción? (Sí/No): ");
        scanf(" %c", &otraTransaccion);
 
        if (otraTransaccion != 'S' && otraTransaccion != 's') {
            break;
        }
    }
 
    clock_t fin = clock();
    double tiempo_transcurrido = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f segundos\n", tiempo_transcurrido);
 
    getchar(); 
 
    return 0;
}
