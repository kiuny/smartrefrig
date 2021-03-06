//
// Created by Andrei Gavrila on 06.03.2017.
//

#ifndef INTELLIGENTREFRIGERATOR_VECTOR_H
#define INTELLIGENTREFRIGERATOR_VECTOR_H

#include "../domain/product.h"

/// @brief Struct that represents the vector
typedef struct {
    unsigned n;
    unsigned capacity;
    void **elements;
    void (*destructor)(void*);
    void* (*cloner)(void*);

} vector;

/// @brief Initializes a new empty vector
/// @return Pointer to the initialized vector
vector *vectorNew(void (*destructor)(void*), void *(*cloner)(void*));

/// @brief Destroys the memory allocated for a vector
/// @param v The vector
void vectorDestroy(vector *v);

/// @brief Changes the size of a vector to the new size
/// @param v The vector
/// @param newsize The new size
/// @return 1 if successful, 0 otherwise
int vectorResize(vector *v, unsigned newsize);

/// @brief Clones a vector together with its content
/// @param v The origin vector
/// @return The cloned vector
vector *vectorClone(vector *v);

/// @brief Pushes a new element to the end of the vector and increases the size
/// @param v The vector to be altered
/// @param p Pointer to the new element
/// @return 1 if successful, 0 if failed
int vectorPushBack(vector *v, void *p);

/// @brief Gets the ith element of the vector
/// @param v The vector
/// @param i The index to be accessed
/// @return The pointer from the ith position of the vector
void *vectorGet(vector *v, int i);

/// @brief Sets the ith element of a vector to the given pointer
/// @param v The vector
/// @param i The index to be set
/// @param p The pointer to be set
/// @return 1 if successful, 0 otherwise
int vectorSet(vector *v, int i, void *p);

/// @brief Returns the size of a vector
/// @param v The vector
/// @return The size of the vector
int vectorSize(vector *v);

/// @brief Deletes the ith index of the vector
/// @param v
/// @param i
/// @return
int vectorDelete(vector *v, int i);

/// @brief Vector functioning as a stack, pops the top
/// @param v The stack vector
/// @return The popped element which has been removed from the vector
void* vectorPop(vector *v);

/// @brief Filters a vector based on a comparator
/// @param v The vector to be filtered
/// @param comparator the filter function
/// @param filters The filters
/// @return A new filtered vector
vector *vectorFilter(vector *v, int (*comparator)(void *, void **), void **filters);

/// @brief Sorts a vector in place
/// @param v The vector
/// @param comparator The sorting function
void vectorSort(vector *v, int (*comparator)(const void *, const void *));

/// @brief Deletes every element from the vector. Its capacity does not change
/// @param v The vector
void vectorClear(vector *v);

#endif //INTELLIGENTREFRIGERATOR_VECTOR_H
