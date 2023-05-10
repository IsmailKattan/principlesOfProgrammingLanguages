#include "dynamicArray.h"

void initialize(DynamicArray* array, int initialCapacity) {
    array->data = (Colony*) malloc(initialCapacity * sizeof(Colony));
    array->size = 0;
    array->capacity = initialCapacity;
}

void append(DynamicArray* array, Colony element) {
    if (array->size == array->capacity) {
        resize(array, array->capacity + 1);
    }
    array->data[array->size] = element;
    array->size++;
}

Colony get(DynamicArray* array, int index) {
    if (index >= array->size || index < 0) {
        printf("Index %d out of bounds for array of size %d\n", index, array->size);
        exit(1);
    }
    return *(array->data + index);
}

void set(DynamicArray* array, int index, Colony value) {
    if (index >= array->size || index < 0) {
        printf("Index %d out of bounds for array of size %d\n", index, array->size);
        exit(1);
    }
    *(array->data + index) = value;
}


void resize(DynamicArray* array, int newCapacity) {
    Colony* newData = (Colony*) malloc(newCapacity * sizeof(Colony));
    for (int i = 0; i < array->size; i++) {
        *(newData + i) = *(array->data + i);
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void freeArray(DynamicArray* array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}
void printArray(DynamicArray* array)
{
    printf("| coloni | poplasyon | yemek stogu | kazanma | kaybetme |\n");
    printf("+--------+-----------+-------------+---------+----------+\n");
    for (size_t i = 0; i < array->size; i++)
    {
        printf("|%8s|%11d|%13d|%9d|%10d|\n",get(array,i)->getflag(get(array,i)) ,get(array,i)->getProduction(get(array,i)),get(array,i)->getStock(get(array,i)),get(array,i)->getWins(get(array,i)),get(array,i)->getDefeats(get(array,i)));
    }
    
}
