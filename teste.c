//Utilizado para testes do escalonador por loteria

#include "types.h"      //necessaria para as variaveis
#include "user.h"       //função para print e chamada do sistema

#define STDOUT 1
#define FILHOS 6
#define TIMER 123456

int main(){
    int pid, i, x = 0, fim[FILHOS];

    for (i = 0; i < FILHOS; i++){
        if(i < FILHOS/3)
            pid = fork(1);
        else if((i >= FILHOS/3) &&  i < (2*(FILHOS/3)))
            pid = fork(10);
        else
            pid = fork(50);

        if(pid == 0){
            for(i = TIMER; i > 0; i--){ // FOR PARA GASTAR TEMPO
                if(i % 100 == 0) printf(STDOUT,"A");
            }
            exit();
        }
    }

    while(1){
        pid = wait();
        if(pid < 0)break;
        fim[x] = pid;
        x++;
    }

    for(i = 0; i < FILHOS; i++){
        printf(STDOUT,"\nFilho %d Acabou", fim[i] );
    }

    exit();
}
