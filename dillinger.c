#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct caja{
   int id;
   int number;
   int status;
   int suma;
};

int n, sumax = 200, idmax;

int main(){
    printf("Numero de cajas: ");
    scanf("%d", &n);
    int i;
    struct caja record[n];
//asignacion de randoms
for (i = 0; i < n; i++)
{
    record[i].id = i;
    int random_number = rand() % 100 + 1;
    record[i].number = random_number;
    record[i].status = 0;
}
//impresion de cajas
for(i=0; i<n; i++){
    printf(" Cage id is: %d \n", record[i].id);
    printf(" Number is: \t%d \n", record[i].number);
    printf(" Status is: \t\t%d\n\n",record[i].status);
    }
//iteracion de sumas
for (int k = 0; k < n; k++)
{
    int pivote = 0;
    for(i = 0; i < n; i++)
    {
        if(record[i].status==0){
            if(i==0){
                if(record[i+1].status==0){
                    record[i].suma = (record[i+1].number);
                }
                else{
                    record[i].status = 2;
                }
            }
            else if(i==n-1){
                if(record[i-1].status==0){
                    record[i].suma = (record[i-1].number);
                }
                else{
                    record[i].status = 2;
                }
            }
            else{
                if(record[i-1].status==0 && record[i+1].status==0){
                    record[i].suma = (record[i-1].number + record[i+1].number);
                }
                else if(record[i-1].status!=0 && record[i+1].status==0){
                    record[i].suma = record[i+1].number;
                }
                else if(record[i-1].status==0 && record[i+1].status!=0){
                    record[i].suma = record[i-1].number;
                }
                else{ //record[i-1].status!=0 && record[i+1].status!=0
                    record[i].status = 2;
                }
            }
            if(record[i].suma>=pivote && record[i].suma<=sumax){
                idmax = record[i].id;
                pivote = record[i].suma;
            }
            else if(record[i].suma==sumax){
                if(record[idmax-1].suma+record[idmax+1].suma<record[i-1].suma+record[i+1].suma){
                    idmax = record[i].id;
                    sumax = record[i].suma;
                }
            }
            printf("Suma de los costados de la caja %d: %d\n", i, record[i].suma);
        }
        else{
            record[i].suma = 0;
        }
    }
    sumax = pivote;
    printf("\n----------------------------------------\n\t\t\t\t Maximo: %d\n Id maximo: %d\n----------------------------------------\n", sumax,idmax);
    //reacomodo de status
    if(record[idmax].status == 0){
        record[idmax].status = 1;
    }
    if(idmax>=2){
        if(record[idmax-2].status==0){
            record[idmax-2].status = 1;
        }
    }
    if(idmax<=n-2){
        if(record[idmax+2].status==0){
            record[idmax+2].status = 1;
        }
    }
    if(idmax<=n-1){
        if(record[idmax+1].status==0){
            record[idmax+1].status = 2;
        }
    }
    if(idmax>=1){
        if(record[idmax-1].status==0){
        record[idmax-1].status = 2;
        }
    }
    for(i=0; i<n; i++){
        printf(" Cage id is: %d \n", record[i].id);
        printf(" Number is: %d \n", record[i].number);
        printf(" Sum is: %d \n", record[i].suma);
        printf(" Status is: \t%d\n\n",record[i].status);
    }
}

//Suma maxima de cajas seleccionadas
int maxcash = 0;
    for (int i = 0; i < n; i++)
    {
        if(record[i].status==2){
            maxcash = maxcash + record[i].number;
        }
    }
    printf("Suma maxima de cajas seleccionadas: %d", maxcash);
return 0;
}