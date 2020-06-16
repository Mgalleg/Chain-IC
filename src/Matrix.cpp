#include "Matrix.h"

#include <stdlib.h>

using namespace std;

/**
 * Constructor. Assigns NULL to head.
 */
Vector::Vector(){

}

/**
 * Destructor. Deletes the elements of the linked list.
 */
Vector::~Vector(){

}

/**
  * Inserts or updates an element of the list.
  * Insertion mentains the list sorted by index.
  */
void Vector::set(int index, int value){

}

/**
 * Retrieves the element of the list with the specified index.
 * Returns 0 if index not found since only non zero elements are stored.
 */
int Vector::get(int index){

  return 0;
}

/**
 * Return the results of the vector dot product.
 */
int Vector::dot(Vector v){

  return 0;
}


/**
 * Constructor. Allocates a Vector array of size
 * m or n depending of the storage format.
 * https://en.wikipedia.org/wiki/Row-_and_column-major_order
 */
Matrix::Matrix(int m, int n, int format){

}

/**
 * Destructor. Deletes the Vector array.
 */
Matrix::~Matrix(){

}

/**
 * Inserts or updates an element of the Matrix.
 */
void Matrix::set(int row, int column, int value){

}

/**
 * Retrieves the element of the Matrix.
 */
int Matrix::get(int row, int column){
  
  return 0;
}

/**
 * Return the results of the Matrix multiplication.
 */
Matrix Matrix::multiply(Matrix mtx){

  return mtx;
}
