#include "func_made.h"

//swaps data sector of two list_element
void list_swap_made(struct list_elem *a, struct list_elem *b){
    int num_a, num_b;
    struct list_item *item_a = list_entry(a, struct list_item, element);
    struct list_item *item_b = list_entry(b, struct list_item, element);
    num_a = item_a->data;
    num_b = item_b->data;
    item_a->data = num_b;
    item_b->data = num_a;
    return;
}

void list_shuffle_made(struct list *a){
    int i, j, size, times;
    srand((unsigned int)time(NULL));
    size = list_size(a);
    struct list_elem *elem_a;
    struct list_elem *elem_b;
    for (i=0;i<size;i++){
        times = rand()%size;
        elem_a = list_begin(a);
        for (j=0;j<times;j++){elem_a = list_next(elem_a);}
        times = rand()%size;
        elem_b = list_begin(a);
        for (j=0;j<times;j++){elem_b = list_next(elem_b);}
        list_swap(elem_a, elem_b);
    }
    return;
}