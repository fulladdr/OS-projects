#include "main.h"

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
        list_swap_made(elem_a, elem_b);
    }
    return;
}

//little_less than compare data of two different list_elem
bool list_less_made(const struct list_elem *a,const struct list_elem *b,void *aux){
    struct list_item *item_a; 
    struct list_item *item_b;
    item_a = list_entry(a, struct list_item, element);
    item_b = list_entry(b, struct list_item, element);
    if (item_a->data<item_b->data) return true;
    else return false;
}

unsigned hash_hash_made(const struct hash_elem* h, void* aux){
		return hash_int(hash_entry(h,struct hash_item, element)->data);
}

bool hash_less_made(const struct hash_elem* h1, const struct hash_elem* h2, void* aux){
    int data1 = hash_entry(h1, struct hash_item, element)->data;
    int data2 = hash_entry(h2, struct hash_item, element)->data; 
    if (data1<data2) return true;
    else return false;
}

void hash_triple_made(struct hash_elem* h, void* aux){
    int x = hash_entry(h, struct hash_item, element)->data;
    hash_entry(h, struct hash_item, element)->data = x*x*x;
}

void hash_square_made(struct hash_elem* h, void* aux){
    int x = hash_entry(h, struct hash_item, element)->data;
    hash_entry(h, struct hash_item, element)->data = x*x;
}

void hash_delete_memory(struct hash_elem* h, void* aux){
    free(hash_entry(h, struct hash_item, element));
}

struct bitmap* bitmap_expand_made(struct bitmap* b, int num){
    size_t size = bitmap_size(b);
    int new_size = size + num;
    size_t i;
    struct bitmap* new_bitmap = bitmap_create(size);
    for (i=0;i<size;++i){
        if (bitmap_test(b, i)==true){
            bitmap_mark(new_bitmap, i);
        }
    }
}

int check_command(char* input, char** token){
    if (strncmp("quit", input, 4)==0) return 0;
    // list functions
    else if (strncmp("create", input, 5)==0 && (token[1][0]=='l')) return 1;
    else if ((strncmp("dumpdata", input, 8)==0)&&(token[1][0]=='l')) return 2; // if its is a list and dumpdata   
    else if (strncmp("list_push_back", input, 14)==0) return 3;
    else if (strncmp("list_push_front", input, 14)==0) return 4;
    else if (strncmp("delete", input, 6)==0) return 5;
    else if (strncmp("list_pop_back", input, 13)==0) return 6;
    else if (strncmp("list_pop_front", input, 14)==0) return 7;
    else if (strncmp("list_remove", input, 11)==0) return 8;
    else if (strncmp("list_reverse", input, 12)==0) return 9;
    else if ((strncmp("delete", input, 6)==0)&&(token[1][0]=='l')) return 10;
    else if (strncmp("list_empty", input, 10)==0) return 11;
    else if (strncmp("list_size", input, 9)==0) return 12;
    else if (strncmp("list_max", input, 8)==0) return 13;
    else if (strncmp("list_min", input, 8)==0) return 14;
    else if (strncmp("list_insert_ordered", input, 19)==0) return 15;
    else if (strncmp("list_back", input, 9)==0) return 16;
    else if (strncmp("list_unique", input, 11)==0) return 17;
    else if (strncmp("list_swap", input, 9)==0) return 18;
    else if (strncmp("list_splice", input,11)==0) return 19;
    else if (strncmp("list_shuffle", input, 12)==0) return 20;
    else if (strncmp("list_sort", input, 9)==0) return 21;
    else if (strncmp("list_front", input, 10)==0) return 22;
    else if (strncmp("list_insert", input, 11)==0) return 23;
    // hash functions
    else if (strncmp("create", input, 5)==0 && (token[1][0]=='h')) return 24;
    else if ((strncmp("dumpdata", input, 8)==0)&&(token[1][0]=='h')) return 25;
    else if (strncmp("hash_insert", input, 11)==0) return 26;
    else if (strncmp("hash_apply", input, 10)==0) return 27;
    else if (strncmp("hash_delete", input, 11)==0) return 28;
    else if ((strncmp("delete", input, 6)==0)&&(token[1][0]=='h')) return 29;
    else if (strncmp("hash_empty", input, 10)==0) return 30;
    else if (strncmp("hash_size", input, 9)==0) return 31;
    else if (strncmp("hash_clear", input, 10)==0) return 32;
    else if (strncmp("hash_find", input, 9)==0) return 33;
    else if (strncmp("hash_replace", input, 12)==0) return 34;
    //bitmap functions
    else if (strncmp("create", input, 5)==0 && (token[1][0]=='b')) return 35;
    else if ((strncmp("dumpdata", input, 8)==0)&&(token[1][0]=='b')) return 36;
    else if (strncmp("bitmap_mark", input, 11)==0) return 37;
    else if (strncmp("bitmap_scan_and_flip", input, 20)==0) return 38;
    else if ((strncmp("delete", input, 6)==0)&&(token[1][0]=='b')) return 39;
    else if (strncmp("bitmap_scan", input, 11)==0) return 40;
    else if (strncmp("bitmap_reset", input, 12)==0) return 41;
    else if (strncmp("bitmap_none", input, 11)==0) return 42;
    else if (strncmp("bitmap_flip", input, 11)==0) return 43;
    else if (strncmp("bitmap_expand", input, 13)==0) return 44;
    else if (strncmp("bitmap_set_all", input, 14)==0) return 45;
    else if (strncmp("bitmap_dump", input, 11)==0) return 46;
    else if (strncmp("bitmap_count", input, 12)==0) return 47;
    else if (strncmp("bitmap_contains", input, 15)==0) return 48;
    else if (strncmp("bitmap_any", input, 10)==0) return 49;
    else if (strncmp("bitmap_all", input, 10)==0) return 50;
    else if (strncmp("bitmap_test", input, 11)==0) return 51;
    else if (strncmp("bitmap_size", input, 11)==0) return 52;
    else if (strncmp("bitmap_set_multiple", input, 19)==0) return 53;
    else if (strncmp("bitmap_set", input, 10)==0) return 54;
}


int main(void){
    size_t st, cnt, size_bit;
    int i, change_x, change_y, x, y, z, location, TOKEN_NUM=0, num;
    char input[MAX]; char input_line[MAX];
    char* ptr;
    char** token = (char**)calloc(sizeof(char*)*tokenNum, 1);
    struct list_elem* list1; struct list_elem* list2; struct list_elem* list3; struct list_elem* delete_elem;
    struct list_item* list_tmp; struct list_item* new_item;
    struct list_elem* before;struct list_item* new;
    struct hash_elem* hash1;
    struct hash_item* hash_new_item; 
    struct hash_iterator* hi;
    while(1){
        //process command line 
        fgets(input, sizeof(char)*100, stdin);
        //tokenize command line
        strcpy(input_line, input);
        ptr = strtok(input_line, " ");
        token[0]= (char*)calloc(sizeof(char)*tokenNum, 1);
        strcpy(token[0], ptr);
        i = 1;
        //every command line is processed inside char** token according to spaces
        while(1){
            ptr = strtok(NULL, " ");
            if (ptr==NULL) break;
            token[i]=(char*)calloc(sizeof(char)*tokenNum, 1);
            strcpy(token[i], ptr);
            i++;
        }
        TOKEN_NUM = i;
        int admin = check_command(token[0], token);
        switch(admin){
            case 0:
                return 0;
                break;
            case 1: // create list list0
                list_init(&list[token[2][4]-'0']);
                break;
            case 2: // dumpdata list0
                list1 = list[token[1][4]-'0'].head.next;
                list2 = list_end(&list[token[1][4]-'0']);
                while(list1!=list2){
                    if (list1==list_end(&list[token[1][4]-'0'])) break;
                    list_tmp = list_entry(list1, struct list_item, element);
                    printf("%d ", list_tmp->data);
                    list1 = list1->next;
                    if (list1==list_end(&list[token[1][4]-'0'])) break;
                }
                 if(list[token[1][4]-'0'].head.next != &(list[token[1][4]-'0'].tail))
						 printf("\n");
                break;
            case 3: // list_push_back list0 1
                list_tmp =(struct list_item*)calloc(sizeof(struct list_item), 1);
                list_tmp->data = atoi(token[2]);
                list_push_back(&list[token[1][4]-'0'], &(list_tmp->element));
                break;
            case 4: // list push front
                list_tmp =(struct list_item*)calloc(sizeof(struct list_item), 1);
                list_tmp->data = atoi(token[2]);
                list_push_front(&list[token[1][4]-'0'], &(list_tmp->element));
                break;
            case 5: // delete
                for (list1 = list_begin(&list[token[1][4]-'0']);list1!=list_end(&list[token[1][4]-'0']); list1 = list_next(list1)){
                    struct list_item *item_temp = list_entry(list1, struct list_item, element);
                    free(item_temp);
                    item_temp=NULL;
                }
                free(&list[token[1][4]-'0']);
                break;
            case 6: // list_pop_back list0
                list_pop_back(&list[token[1][4]-'0']);
                break;
            case 7: // list pop front
                list_pop_front(&list[token[1][4]-'0']);
                break;
            case 8: // list_remove list0 1
                delete_elem = list_begin(&list[token[1][4]-'0']);
                location = atoi(token[2]);
                for (i=1;i<=location;i++){
                    delete_elem = list_next(delete_elem);
                }
                list_remove(delete_elem);
                break; 
            case 9: // list reverse
                list_reverse(&list[token[1][4]-'0']);
                break;
            case 10: // delete
                break;
            case 11: // list_empty
                if (list_empty(&list[token[1][4]-'0'])==true) printf("true\n");
                else printf("false\n");
                break;
            case 12: // list_size
                printf("%zu\n", list_size(&list[token[1][4]-'0']));
                break;
            case 13: // list_max
                printf("%d\n", list_entry(list_max(&list[token[1][4]-'0'], list_less_made, NULL), struct list_item, element)->data);
                break;
            case 14: // list_min
                printf("%d\n", list_entry(list_min(&list[token[1][4]-'0'], list_less_made, NULL), struct list_item, element)->data);
                break;
            case 15: // list_insert_ordered list0 3
                new_item = (struct list_item*)calloc(sizeof(struct list_item), 1);
                new_item->data = atoi(token[2]);
                list_insert_ordered(&list[token[1][4]-'0'], &(new_item->element), list_less_made, NULL);
                break;
            case 16: // list_back
                printf("%d\n",list_entry(list_back(&list[token[1][4]-'0']),struct list_item, element)->data);
                break;
            case 17: // list_unique list0 list1
                if (TOKEN_NUM == 2){
                    list_unique(&list[token[1][4]-'0'], NULL, list_less_made, NULL);
                }
                else{
                    list_unique(&list[token[1][4]-'0'], &list[token[2][4]-'0'], list_less_made, NULL);
                }
                break;
            case 18: // list_swap list0 1 3
                list1 = list_begin(&list[token[1][4]-'0']); // liust to be swapped
                list2 = list_begin(&list[token[1][4]-'0']);
                change_x = atoi(token[2]);
                change_y = atoi(token[3]);
                for (i = 1; i<=change_x; i++){
                    list1 = list_next(list1);
                }
                for (i=1;i<=change_y;i++){
                    list2 = list_next(list2);
                }
                list_swap_made(list1, list2);
                break;
            case 19: // list_splice list0 2 list1 1 4
                list1 = list_begin(&list[token[1][4]-'0']);
                list2 = list_begin(&list[token[3][4]-'0']);
                list3 = list_begin(&list[token[3][4]-'0']);
                x = atoi(token[2]);
                y = atoi(token[4]);
                z = atoi(token[5]);
                for (i=1;i<=x;i++) {list1 = list_next(list1);} //move the list
                for (i=1;i<=y;i++) {list2 = list_next(list2);}
                for (i=1;i<=z;i++) {list3 = list_next(list3);}
                list_splice(list1, list2, list3);
                break;
            case 20: // list_shuffle list1
                list_shuffle_made(&list[token[1][4]-'0']);
                break;
            case 21: // list_sort
                list_sort(&list[token[1][4]-'0'], list_less_made, NULL);
                break;
            case 22: // list_front list0
                list1 =list_front(&list[token[1][4]-'0']);
                struct list_item *list_tmp = list_entry(list1, struct list_item, element);
                printf("%d\n", list_tmp->data);
                break;
            case 23: //list_insert list0 1 2
                location = atoi(token[2]);
                num = atoi(token[3]);

                before = list_begin(&list[token[1][4]-'0']);
                for (i=0;i<location;i++){
                    before = list_next(before);
                }
                new = (struct list_item*)malloc(sizeof(struct list_item));
                new->data = num;
                list_insert(before, &new->element);
            //hash functions
            case 24: // create hashtable hash0
                hash_init(&hash[token[2][4]-'0'], hash_hash_made, hash_less_made, NULL);
                break;
            case 25: // dumpdata hash0
                hi = (struct hash_iterator*)malloc(sizeof(struct hash_iterator));
                hash_first(hi, &hash[token[1][4]-'0']);
                while(1){
                    if (!hash_next(hi)) break;
                    struct hash_item* hit = hash_entry(hash_cur(hi), struct hash_item, element);
                    printf("%d ", hit->data);
                }
                printf("\n");
                break;
            case 26: //hash_insert hash0 1
                hash_new_item = (struct hash_item*)malloc(sizeof(struct hash_item));
                hash_new_item->data = atoi(token[2]);
                hash_insert(&hash[token[1][4]-'0'], &hash_new_item->element);
                break;
            case 27: // hash_apply hash0 triple
                if (strncmp(token[2], "triple", 6)==0){
                    hash_apply(&hash[token[1][4]-'0'], hash_triple_made);
                }
                else if (strncmp(token[2], "square", 6)==0){
                    hash_apply(&hash[token[1][4]-'0'], hash_square_made);
                }
                break;
            case 28: // hash_delete hash0 10
                hash_new_item = (struct hash_item*)malloc(sizeof(struct hash_item));
                hash_new_item->data = atoi(token[2]);
                hash_delete(&hash[token[1][4]-'0'], &(hash_new_item->element));
                break;
            case 29: // delete hash0
                break;
            case 30: // hash_empty hash0
                if(hash_empty(&hash[token[1][4]-'0'])) printf("true\n");
                else printf("false\n");
                break;
            case 31: //hash_size hash0
                printf("%zu\n", hash_size(&hash[token[1][4]-'0']));
                break;
            case 32: //hash_clear hash0
                hash_clear(&hash[token[1][4]-'0'], NULL);
                break;
            case 33: // hash_find hash0 10
                hash_new_item =  (struct hash_item*)calloc(sizeof(struct hash_item),1);
                hash_new_item->data = atoi(token[2]);
                if (hash_find(&hash[token[1][4]-'0'], &hash_new_item->element)!=NULL){
                    printf("%d\n", hash_new_item->data);
                }
                break;
            case 34: // hash_replace hash0 10
                hash_new_item =  (struct hash_item*)malloc(sizeof(struct hash_item));
                hash_new_item->data = atoi(token[2]);
                hash_replace(&hash[token[1][4]-'0'], &hash_new_item->element);

            //bitmap functions

            case 35: // create bitmap bm0 16
                sscanf(token[3], "%zu", &st);
                bitmap[token[2][2]-'0'] = bitmap_create(st);
                break;
            case 36: // dumpdata bm0
                st = bitmap_size(bitmap[token[1][2]-'0']);
                for (cnt=0;cnt<st;cnt++){
                    printf("%d", bitmap_test(bitmap[token[1][2]-'0'], cnt));
                }
                printf("\n");
                break;
            case 37: // bitmap_mark bm0 0 
                sscanf(token[2], "%zu", &st);
                bitmap_mark(bitmap[token[1][2]-'0'], st);
                break;
            case 38: // bitmap_scan_and_flip bm0 0 1 true/l
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (strncmp(token[4], "true", 4)==0){
                    size_bit = bitmap_scan_and_flip(bitmap[token[1][2]-'0'], st, cnt, true);
                }
                else{
                    size_bit = bitmap_scan_and_flip(bitmap[token[1][2]-'0'], st, cnt, false);
                }
                printf("%zu\n", size_bit);
                break;
            case 39: // delete bm0
                break;
            case 40: // bitmap_scan bm0 0 1 true
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (strncmp(token[4], "true", 4)==0){
                    printf("%zu\n", bitmap_scan(bitmap[token[1][2]-'0'], st, cnt, true));
                }
                else{
                    printf("%zu\n", bitmap_scan(bitmap[token[1][2]-'0'], st, cnt, false));
                }
                break;
            case 41: // bitmap_reset bm0 0 
                sscanf(token[2], "%zu", &st);
                bitmap_reset(bitmap[token[1][2]-'0'], st);
                break;
            case 42: // bitmap_none bm0 0 1
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (bitmap_none(bitmap[token[1][2]-'0'], st, cnt)==true ){
                    printf("true\n");
                }
                else{
                    printf("false\n");
                }
                break;
            case 43: // bitmap_flip bm0 4
                sscanf(token[2], "%zu", &st);
                bitmap_flip(bitmap[token[1][2]-'0'], st);
                break;
            case 44: // bitmap_expand bm0 2
                bitmap[token[1][2]-'0'] = bitmap_expand_made(bitmap[token[1][2]-'0'], atoi(token[2]));
                break;
            case 45: // bitmap_set_all bm0 false
                if (strncmp(token[2], "true", 4)==0){
                    bitmap_set_all(bitmap[token[1][2]-'0'], true);
                }
                else{
                    bitmap_set_all(bitmap[token[1][2]-'0'], false);
                }                                                               
                break;
            case 46: // bitmap_dump bm0
                bitmap_dump(bitmap[token[1][2]-'0']);
                break;
            case 47: // bitmap_count bm0 0 8 true
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (strncmp(token[4], "true", 4)==0){
                    printf("%zu\n", bitmap_count(bitmap[token[1][2]-'0'], st, cnt, true));
                }
                else{
                    printf("%zu\n", bitmap_count(bitmap[token[1][2]-'0'], st, cnt, false));
                }
                break;
            case 48 : // bitmap_contains bm0 6 3 true
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (strncmp(token[4], "true", 4)==0){
                    if (bitmap_contains(bitmap[token[1][2]-'0'], st, cnt, true)){
                        printf("true\n");
                    }
                    else{
                        printf("false\n");
                    }
                }
                else if (strncmp(token[4], "false", 5)==0){
                     if (bitmap_contains(bitmap[token[1][2]-'0'], st, cnt, false)){
                        printf("true\n");
                    }
                    else{
                        printf("false\n");
                    }
                }
                break;
            case 49 : // bitmap_any bm0 1 1
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (bitmap_any(bitmap[token[1][2]-'0'], st, cnt)==true){
                    printf("true\n");
                }
                else printf("false\n");
                break;
            case 50 : // bitmap_all bm0 0 1
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (bitmap_all(bitmap[token[1][2]-'0'], st, cnt)){
                    printf("true\n");
                }
                else printf("false\n");
                break;
            case 51 : // bitmap_test bm0 4
                sscanf(token[2], "%zu", &st);
                if (bitmap_test(bitmap[token[1][2]-'0'], st)){
                    printf("true\n");
                }
                else{
                    printf("false\n");
                }
                break;
            case 52 : // bitmap_size bm0
                printf("%zu\n", bitmap_size(bitmap[token[1][2]-'0']));
                break;
            case 53 : // bitmap_set_multiple bm0 0 4 true
                sscanf(token[2], "%zu", &st);
                sscanf(token[3], "%zu", &cnt);
                if (strncmp(token[4], "true", 4)==0){
                    bitmap_set_multiple(bitmap[token[1][2]-'0'], st, cnt, true);
                }
                else{
                    bitmap_set_multiple(bitmap[token[1][2]-'0'], st, cnt, false);
                }
                break;
            case 54 : // bitmap_set bm0 5 true
                sscanf(token[2], "%zu", &st);
                if (strncmp(token[3], "true", 4)==0){
                    bitmap_set(bitmap[token[1][2]-'0'], st, true);
                }
                else{
                    bitmap_set(bitmap[token[1][2]-'0'], st, false);
                }
                break;
        }
    }
}