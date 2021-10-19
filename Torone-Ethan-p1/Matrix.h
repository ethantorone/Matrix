#ifndef matrix
#define matrix

typedef unsigned int uint;
class Matrix {
public:
    double** mat;
    uint rows;
    uint columns;

    /**
     * Constructor. Creates a Matrix with {@code rows} rows and {@code cols} columns.
     *
     * @param rows number of rows
     * @param cols number of columns
     */
    Matrix(uint rows, uint cols); // constructor (all elements initialized to 0)


    /**
     * Copy constructor. Creates a deep copy of the passed Matrix.
     *
     * @param m the Matrix that will be copied
     */
    Matrix(const Matrix & m); // copy constructor


    /**
     * Destructor. Deallocates the 2d array.
     */
    ~Matrix(); // destructor

    /**
     * Adds a scalar to all elements within the Matrix and returns
     * a new Matrix.
     *
     * @param s a scalar
     * @return the Matrix sum
     */
    Matrix add(double s) const; // add scalar to this Matrix

    /**
     * Adds each corresponding element from {@code m} to called Matrix
     * and returns a new Matrix.
     *
     * @param m the Matrix that will be added
     * @return the Matrix sum
     */
    Matrix add(const Matrix & m) const; // add this Matrix and another Matrix

    /**
     * Subtracts a scalar from all elements within the Matrix and returns
     * a new Matrix.
     *
     * @param s a scalar
     * @return the Matrix difference
     */
    Matrix subtract(double s) const; // subtract scalar from this Matrix

    /**
     * Substracts each corresponding element from {@code m} from the called Matrix
     * and returns a new Matrix.
     *
     * @param m the matrix that will be used to subtract
     * @return the Matrix difference
     */
    Matrix subtract(const Matrix & m) const; // subtract another Matrix from this Matrix

    /**
     * Multiplies each element by a scalar and returns a new Matrix.
     *
     * @param s a scalar
     * @return the Matrix product
     */
    Matrix multiply(double s) const; // multiply this Matrix by a scaler

    /**
     * Multiplies the called Matrix by the Matrix {@code m} with Matrix
     * multiplication and returns the new Matrix.
     *
     * @param m the matrix that will be used as a factor
     * @return the Matrix product
     */
    Matrix multiply(const Matrix & m) const; // multiply this Matrix by another Matrix


    /**
     * Divides all elements within the Matrix by a scalar and returns a new Matrix.
     *
     * @param s a scalar
     * @return the Matrix quotient
     */
    Matrix divide(double s) const; // divide this Matrix by a scalar

    /**
     * Returns a transposed Matrix of the called Matrix. Transposition
     * turns the rows into columns andthe  columns into rows.
     *
     * @return the transposed Matrix
     */
    Matrix t() const; // transpose of this Matrix

    /**
     * Returns the number of rows.
     *
     * @return the number of rows
     */
    const uint numRows() const; // returns the number of rows

    /**
     * Returns the number of columns.
     *
     * @return the number of columns
     */
    const uint numCols() const; // returns the number of cols

    /**
     * Returns the address of the element at the indicated {@code row} and {@code col}.
     *
     * @param row row index
     * @param col columns index
     * @return the address of the element
     */
    double & at(uint row, uint col); // get/set element at row,col

    /**
     * Returns a read-only copy of the element at the indicated
     * {@code row} and {@code col}.
     *
     * @param row row index
     * @param col columns index
     * @return a read-only version of the desired element
     */
    const double & at (uint row, uint col) const;
    // get element at row,col (when using a const object)

    /**
     * Prints the called Matrix.
     */
    void printMatrix();
}; // Matrix

#endif
