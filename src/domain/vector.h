//
// Created by Andrei Gavrila on 06.03.2017.
//

#ifndef INTELLIGENTREFRIGERATOR_VECTOR_H
#define INTELLIGENTREFRIGERATOR_VECTOR_H

#include "product.h"

typedef struct {
    int n;
    int max_size;
    Product **elements;
} vector;

void push_back(vector *v, Product *p);

Product *get(vector *v, int i);

void set(vector *v, int i, Product *p);

int size(vector *v);

void delete(vector *v, int i);
#endif //INTELLIGENTREFRIGERATOR_VECTOR_H