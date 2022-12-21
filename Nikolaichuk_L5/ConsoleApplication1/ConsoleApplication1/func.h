#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H

void mem(int*** a, int row, int col);
int input_check_row();
void fill_rand(int row, int col, int** a);
void fill_manual(int row, int col, int** a);
void print(int row, int col, int** a);
void fill(int row, int col, int** a);
void del(int** a, int row, int* col);

#endif //INC_5_1_FUNCTIONS_H