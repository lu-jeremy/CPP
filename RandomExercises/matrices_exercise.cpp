#include <iostream>
#include <stdlib.h>



using namespace std;

class multiplyingMatrices {
    public:
        int ROW_ONE, COLUMN_ONE, ROW_TWO, COLUMN_TWO;
        int element;
        int matrix_one[10][10];
        int matrix_two[10][10];
        int sum = 0;
    void userInput(void) {
        cout << "This program multiplies two matrices that are inputed together." << endl;
        cout << "Input the row(s) of the first matrix." << endl;
        cin >> ROW_ONE;
        cout << "Input the column(s) of the first matrix." << endl;
        cin >> COLUMN_ONE;
        cout << "Input the rows of the second matrix." << endl;
        cin >> ROW_TWO;
        cout << "Input the columns of the second matrix." << endl;
        cin >> COLUMN_TWO;
    }
    
    void receiveElements(void) {
        if (COLUMN_ONE != ROW_TWO) {
            cout << "You cannot multiply two matrices with different columns and rows." << endl;
            cout << "Ended program unsuccesfully." << endl;
        }
        
        for (int row = 0; row < ROW_ONE; ++ row) {
            for (int column = 0; column < COLUMN_ONE; ++ column) {
                cout << "Give me an element for the first matrix." << endl;
                cin >> element;
                matrix_one[row][column] = element;
            }
        }
        
        for (int row = 0; row < ROW_TWO; ++ row) {
            for (int column = 0; column < COLUMN_TWO; ++ column) {
                cout << "Give me an element for the second matrix." << endl;
                cin >> element;
                matrix_two[row][column] = element;
            }
        }
    }
    
    void multiplyElements(void) {
        for (int row_column = 0; row_column < COLUMN_ONE; ++ row_column) {
            for (int column = 0; column < COLUMN_TWO; ++ column) {
                for (int row = 0; row < ROW_ONE; ++ row) {
                    sum = sum + matrix_two[row][row_column] * matrix_one[row_column][column];
                    cout << "This is the " << row_column << "element" << endl; //needs work
                }
            }
        }
        cout << sum << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    multiplyingMatrices matrix;
    
    matrix.userInput();
    matrix.receiveElements();
    matrix.multiplyElements();
    
    return 0;
}