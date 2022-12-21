#ifndef INC_5_1_FUNCTIONS_H
#define INC_5_1_FUNCTIONS_H

int amount_elements();
void fill_rand(int* a, int amount);
void fill_manual(int* a, int amount);
void fill(int* a, int amount);
void print(int* a, int amount);
int find_pos(int* a, int amount);
void shell_sort(int* a, int pos);
void shell_sort_reverse(int* a, int amount);
void mod_a(int* a, int amount);
void bubble_sort(int* a, int amount);
void shell_time(int* a, int pos);
void bubble_time(int* a, int pos);
void shell_time_rev(int* a, int pos);

#endif //INC_5_1_FUNCTIONS_H