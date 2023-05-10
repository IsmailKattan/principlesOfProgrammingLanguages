#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "colony.h"

typedef struct {
    Colony* data;
    int size;
    int capacity;
} DynamicArray;

void initialize(DynamicArray* array, int initialCapacity);
void append(DynamicArray* array, Colony element);
Colony get(DynamicArray* array, int index);
void set(DynamicArray* array, int index, Colony value);
void resize(DynamicArray* array, int newCapacity);
void freeArray(DynamicArray* array);
void printArray(DynamicArray* array);

#endif
