#include <iostream>
#include <iomanip>
#include <cmath>

void stable_insertion_sort_cols_desc_by_min_abs(double** matrix, int n, int m)
{

    int* counter = new int[m];


    for (int j = 0; j < m; j++)
    {
        counter[j] = j;
    }


    for (int j = 1; j < m; j++)
    {
        int c = counter[j];
        double abs_col = std::abs(matrix[0][c]);
        int k = j;


        while (k > 0 && std::abs(matrix[0][counter[k - 1]]) < abs_col)
        {
            counter[k] = counter[k - 1];
            k--;
        }

        counter[k] = c;
    }


    double** sorted = new double* [n];
    for (int i = 0; i < n; i++) {
        sorted[i] = new double[m];
    }


    for (int j = 0; j < m; j++)
    {
        int index_col = counter[j];
        for (int i = 0; i < n; i++)
        {
            sorted[i][j] = matrix[i][index_col];
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = sorted[i][j];
        }
    }


    for (int i = 0; i < n; i++)
    {
        delete[] sorted[i];
    }
    delete[] sorted;
    delete[] counter;

}






int main()
{
    std::cout << "Task A" << std::endl;
    std::cout << " " << std::endl;
    int i, j, n, m;
    std::cout << "Input n: ";
    std::cin >> n;
    std::cout << "Input m: ";
    std::cin >> m;
    std::cout << " " << std::endl;

    double** matrix = new double* [n];

    for (i = 0; i < n; i++)
    {
        matrix[i] = new double[m];
        for (j = 0; j < m; j++)
        {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << std::endl;

    std::cout << "Initial matrix: " << std::endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            std::cout << std::setw(3) << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    stable_insertion_sort_cols_desc_by_min_abs(matrix, n, m);

    std::cout << "Sorted matrix:" << std::endl;


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            std::cout << std::setw(3) << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;


    return 0;
}



//test1A
//input:
//n = 3, m = 3
//Initial matrix:
//3       5       7
//9       5       1
//2       5       8
//
//output:
//Sorted matrix :
//7       5       3
//1       5       9
//8       5       2

//test2A
//input:
//n = 3, m = 3
//Initial matrix :
//1     - 9       6
//3       5       9
//6       2       4
//output:
//Sorted matrix :
//-9      6       1
//5       9       3
//2       4       6

//test3A
//input:
//n = 2, m = 4
//Initial matrix :
//0  - 1 - 2  3
//- 3  0   1  2
//output:
//Sorted matrix :
//3 - 2 - 1   0
//2   1   0 - 3

//test4A
//input:
//n = 3, m = 1
//Initial matrix :
//1
//- 2
//3
//output:
//Sorted matrix :
//1
//- 2
//3

//test5A
//input:
//n = 1, m = 3
//Initial matrix :
//9       0      - 8
//output:
//Sorted matrix :
//9      -8       0

//test6A
//input:
//n = 4, m = 4
//Initial matrix :
// 3       8       4       9
//-2       5       9       7
//- 5      6       8      9
//- 1      4       5      9
//output:
//Sorted matrix :
//9       8       4       3
//7       5       9      - 2
//9       6       8      - 5
//9       4       5      - 1

//test7A
//input:
//n = 2, m = 4
//Initial matrix :
//0  - 1  - 2   3
//- 3  0    1   2
//output:
//Sorted matrix :
//3 - 2  - 1   0
//2   1    0 - 3

