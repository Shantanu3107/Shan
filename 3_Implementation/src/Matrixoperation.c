#include "matrix_operations.h"


/**
 * @brief This function frees the dynamically allocated memory in the structure
 * 
 * @parameter m 
 */
void free_matrix_structure(mat *m){
    free(m->matrix_1);
    free(m->matrix_2);
}

/**
 * @brief A function to dynamically allocate the memory for the matrix
 * 
 * @parameter matrix 
 * @parameter n 
 */
void dynamic_mat_allocation(float **matrix,int n){
    matrix = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        matrix[i] = (float *)calloc(n,sizeof(float));
    }
}



/**
 * @brief A function to allocate memory and input the matrix elements
 * 
 * @parameter matrix 
 * @parameter n 
 * @return float** 
 */
float ** alloc_input_matrix(float **matrix,int n){
    int i,j;
    matrix = (float **)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        matrix[i] = (float *)calloc(n,sizeof(float));
    }

    float element;
    printf("Enter the matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%f", &element);
            matrix[i][j]= element;
        }
    }
    return matrix;
}

/**
 * @brief A function to output the matrix
 * 
 * @parameter matrix 
 * @parameter n 
 */

void output_matrix(float **matrix,int n){
    int i,j;
    float x;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            //x = **(matrix + i*n + j);
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}


/**
 * @brief A function to add two matrices
 * 
 * @parameter matrix1 
 * @parameter matrix2 
 * @parameter n 
 * @return error_t 
 */
error_t add_matrices(float **matrix1,float **matrix2, int n){
    int i,j;
    float **result;

    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The sum of the matrices is: \n");
    output_matrix(result,n);
    free(result);
    return SUCCESS;

}

/**
 * @brief A function to subtract 2 matrices
 * 
 * @parameter matrix1 
 * @parameter matrix2 
 * @parameter n 
 * @return error_t 
 */
error_t subtract_matrices(float **matrix1,float **matrix2, int n){
    int i,j;
    float **result;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("The difference of the matrices is: \n");
    output_matrix(result,n);
    free(result);
    return SUCCESS;
}
/**
 * @brief A function to find the transpose of a matrix
 * 
 * @parameter matrix 
 * @parameter n 
 * @return error_t 
 */
error_t transpose(float **matrix,int n){
    float **result;
    int i,j;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for (i = 0;i < n; i++)
    {
     for (j = 0;j < n; j++)
       {
         result[i][j] = matrix[j][i];
        }
    }

    printf("The Transpose of the matrix is: \n");
    output_matrix(result,n);
    free(result);
    return SUCCESS;
    
}

