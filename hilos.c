#include <pthread.h>
#include <stdio.h>
int saldo;

void * holaHilo(){
    for(int i = 0; i<100; i++){
        printf("hola desde un hilo\n");
    }
    pthread_exit(NULL);
}

void * agregaSaldo(){
    printf("El saldo actual es: %d\n",saldo);
    saldo += 100;
    printf("El nuevo saldo es: %d\n", saldo);
}

int main(){
    pthread_t t;
    saldo= 0;
    for(int i=0;i < 100; i++){
        pthread_create(&t,NULL,agregaSaldo,NULL);
    }
    pthread_exit(NULL);
}