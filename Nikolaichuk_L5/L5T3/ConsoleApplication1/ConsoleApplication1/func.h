#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H
void row_count(int* rows);
int** mem(int rows, int cols);
int cols_count(int** a, int row);
void print(int** a, int rows);
void fill(int** a, int rows, int* cols);
void copy(int*** a, int rows);

#endif //INC_5_1_FUNCTIONS_H
