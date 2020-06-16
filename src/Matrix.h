#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#define ROW_MAJOR 0
#define COL_MAJOR 1


using namespace std;

/**
 * Structure to represent the elements of a Vector.
 * Since the Vector class does not store zero elements
 * we use index to know the position of the element.
 */
struct Element{
  int index;
  int value;

  Element* next;
};


/**
 * Vector class that stores only non zero elements.
 */
class Vector{

private:
  /**
   * Head element of the linked list. Elements are sorted by index.
   */
  Element *head;

public:
  //Element *head;
  /**
   * Constructor. Assigns NULL to head.
   */
  Vector();

  /**
   * Destructor. Deletes the elements of the linked list.
   */
  ~Vector();

  /**
   * Inserts or updates an element of the list.
   * Insertion mentains the list sorted by index.
   */
  void set(int index, int value);

  /**
   * Retrieves the element of the list with the specified index.
   * Returns 0 if index not found since only non zero elements are stored.
   */
  int get(int index);

  /**
   * Return the results of the vector dot product.
   */
  int dot(Vector v);
};


class Matrix {

private:
  int format;  // ROW_MAJOR or COL_MAJOR
  Vector *data;

public:
  /**
   * Matrix dimensions. Useful for printing.
   */
  int m, n;

  /**
   * Constructor. Allocates a Vector array of size
   * m or n depending of the storage format.
   * https://en.wikipedia.org/wiki/Row-_and_column-major_order
   */
  Matrix(int m, int n, int format);


  void putData(Vector *newData){
    data = newData;
  }

  /**
   * Destructor. Deletes the Vector array.
   */
  ~Matrix();

  /**
   * Inserts or updates an element of the Matrix.
   */
  void set(int row, int column, int value);

  /**
   * Retrieves the element of the Matrix.
   */
  int get(int row, int column);

  /**
   * Return the results of the Matrix multiplication.
   */
  Matrix multiply(Matrix mtx);
};

#endif /* MY_MATRIX_H */
