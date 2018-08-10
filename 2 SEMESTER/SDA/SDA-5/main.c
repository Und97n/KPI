#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long* make_array(int size){
    long *arr = malloc(sizeof(long)*size);
    return arr;
}

void print_array(long* arr, int size){
    for(int i =0;i<size;i++){
        printf("%4ld ",arr[i]);
    }
    printf("\n");
}

void fill_array(long* arr, int size){
    for(int i =0;i<size;i++){
        arr[i] = rand()%100+1;
    }
}

void k_process(long* arr,int size, int k, int* sum, int *prod){
    *sum = 0;
    *prod = 1;
    for(int i =0;i<k;i++){
        *sum+=arr[i];
    }
    for(int i = k;i<size;i++){
        *prod *= arr[i];
    }

}

int get_k(int size){
    int k = -1;
    while(k<1 || k>=size){
    printf("Please enter K: ");
    scanf("%d",&k);
    printf("\n");
    }

}

int main()
{
    srand(time(0));

    int sum,prod;
    int size = 11;
    int k = get_k(size);
    long *A = make_array(size);
    fill_array(A,size);
    print_array(A,size);
    k_process(A,size,k,&sum,&prod);
    printf("Sum = %d Prod = %d\n",sum,prod);
    free(A);

    size = 10;
    k = get_k(size);
    long *B = make_array(size);
    fill_array(B,size);
    print_array(B,size);
    k_process(B,size,k,&sum,&prod);
    printf("Sum = %d Prod = %d\n",sum,prod);
    free(B);

    size = 14;
    k = get_k(size);
    long *C = make_array(size);
    fill_array(C,size);
    print_array(C,size);
    k_process(C,size,k,&sum,&prod);
    printf("Sum = %d Prod = %d\n",sum,prod);
    free(C);
    return 0;
}
