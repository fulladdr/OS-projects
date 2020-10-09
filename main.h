#ifndef _MY_DEBUG
  #define _MY_DEBUG 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "limits.h"
#include "round.h"
#include "bitmap.h"
#include "hash.h"
#include "list.h"
#include "limits.h"
#include "debug.h"
#include "hex_dump.h"

#define MAX 101
#define Num 41
#define tokenNum 41

//data structures
//make list as a list of list
struct list list[Num];
struct hash hash[Num];
struct bitmap* bitmap[Num];

struct list_item{
    struct list_elem element;
    int data;
};

struct hash_item{
  struct hash_elem element;
  int data;
};

bool list_less_made(const struct list_elem *a,const struct list_elem *b,void *aux);
void list_swap_made(struct list_elem *a, struct list_elem *b);
void list_shuffle_made(struct list *a);

unsigned hash_hash_made(const struct hash_elem* h, void* aux);
bool hash_less_made(const struct hash_elem* h1, const struct hash_elem* h2, void* aux);
void hash_triple_made(struct hash_elem* h, void* aux);
void hash_square_made(struct hash_elem* h, void* aux);
void hash_delete_memory(struct hash_elem* h, void* aux);

struct bitmap* bitmap_expand_made(struct bitmap* b, int num);