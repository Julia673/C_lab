/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <malloc.h>
//#include <conio.h>

int get_int()
{
    int n;
    while (1){
    scanf("%d", &n);
    if (n <=5 && n>=0)
    {    
        break;
    }else{
        printf("Некорректніе данні. Спробуйте ще раз:\n");
        
    }
    }
    return n;
}

void function_Addition(int** A_matrix, int** B_matrix,int** C_matrix ,int size){ //  Додавання матриць

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            C_matrix[i][j] = A_matrix[i][j] + B_matrix[i][j];
        }
    }

}
void function_Difference(int** A_matrix, int** B_matrix, int** C_matrix, int size){ // Віднімання Матриць 

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            C_matrix[i][j] = A_matrix[i][j] - B_matrix[i][j];
        }
    }


}
void function_Transpose(int**A_matrix,int** C_matrix, int size){ // Транспонування матрць 

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            C_matrix[i][j] = A_matrix[j][i];
        }
    }

}
void function_Multiplication(int** A_matrix, int** B_matrix, int** C_matrix, int size){

    int sum = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int count = 0; count < size; count++){
                sum += A_matrix[i][count]*B_matrix[count][j];
            }
            C_matrix[i][j] = sum;
            sum = 0;
        }
    }
}
void function_Multiplication_of_number(int** A_matrix,int **C_matrix,int number, int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
                C_matrix[i][j]= A_matrix[i][j]*number;
        }
    }
}

int** initial(int size){

int**    matrix = (int**)malloc(size*sizeof(int*));
    for(int i = 0; i < size; i++){
        matrix[i] = (int *)malloc(size*sizeof(int));
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
                matrix[i][j] = 0;
        }
    }
return matrix;
}
void number_matrix( int **A_matrix,int **B_matrix,int size){  //
    int number;
    printf("\n Заповніть A матрицю даними \n");
    for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                  scanf("%d", &number);
                  A_matrix[i][j]=number;
                }
            }
            printf("\n Заповніть B матрицю даними \n");
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                  scanf("%d",  &number);
                  B_matrix[i][j]=number;
                }
            }

}
void print_matrix( int** matrix,int size){
    
     for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ",matrix[i][j]);
        }
            printf("\n");
    }
    
}

    
int main()
{   int **A_matrix, **B_matrix, **C_matrix;
    int size,choice,number;
    printf(" Виберіть команду : 0-додавання двох матриць;1-віднімання двох матриць;2-множення матриці на коефіцієнт; 3-множення двох матриць;4- транспонування матриці;");
    
    choice = get_int();
    printf("Вкажіть розмір матриці: рядки ||стовбці ");
    scanf("%d",&size);
        switch (choice)
        {
             case 0 :
            {
            printf("\nДодавання\n");
            A_matrix= initial(size);
            B_matrix= initial(size);
            C_matrix= initial(size);
            number_matrix(A_matrix,B_matrix,size);
            print_matrix(A_matrix,size);
            printf("\n");
            print_matrix(B_matrix,size);
             printf("\n");
            function_Addition(A_matrix,B_matrix,C_matrix,size);   
            break;
            }
            case 1 :
            {
            printf("\nВіднімання\n");
            A_matrix= initial(size);
            B_matrix= initial(size);
            C_matrix= initial(size);
            number_matrix(A_matrix,B_matrix,size);
            print_matrix(A_matrix,size);
            printf("\n");
            print_matrix(B_matrix,size);
             printf("\n");
            function_Difference(A_matrix,B_matrix,C_matrix, size);  
            break;
                }
            case 2 :
            {
                int number;
            printf("\nМноження матриці на коефіцієнт\n");
            A_matrix= initial(size);
            C_matrix= initial(size);
            printf("\n Заповніть  матрицю даними \n");
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                  scanf("%d", &number);
                  A_matrix[i][j]=number;
                }
            }
            printf("Ведіть число :");
            scanf("%d",& number);
            print_matrix(A_matrix,size);
            printf("\n");
            function_Multiplication_of_number( A_matrix,C_matrix,number, size); 
            break;
            }
            case 3 :
            {
            printf("\nМноження двох матриць\n");
            A_matrix= initial(size);
            B_matrix= initial(size);
            C_matrix= initial(size);
            number_matrix(A_matrix,B_matrix,size);
            print_matrix(A_matrix,size);
            printf("\n");
            print_matrix(B_matrix,size);
            printf("\n");
           function_Multiplication(A_matrix,B_matrix,C_matrix, size); 
            break;
            }
            case 4 :
            {
            printf("\nТранспонування матриці\n");
            A_matrix= initial(size);
            C_matrix= initial(size);
            printf("\n Заповніть  матрицю даними \n");
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                  scanf("%d", &number);
                  A_matrix[i][j]=number;
                }
            }
            print_matrix(A_matrix,size);
            printf("\n");
            function_Transpose(A_matrix,C_matrix, size); 
            break;
            }
            default :{
            printf("\nПомилка даних.\n");
            break;
            }
        }
    print_matrix(C_matrix,size);
    free(A_matrix);
    free(B_matrix);
    free(C_matrix);
    return 0;
}
