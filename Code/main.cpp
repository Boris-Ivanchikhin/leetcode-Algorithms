// Пример с черепахой (двумерное ДП):
// Представим себе матрицу, где черепаха находится в левом верхнем углу,
// и ей нужно достичь правого нижнего угла, перемещаясь только вправо или вниз.
// Каждая ячейка содержит стоимость прохода через неё. Наша задача — найти минимальную стоимость пути.

#include <Windows.h>
#include <iostream>
#include <vector>

#include "Timer.h"

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();

    // Создаем двумерный массив для хранения решений подзадач
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Начинаем с левого верхнего угла
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Инициализация значений from_top и from_left
            int from_top = (i > 0) ? dp[i - 1][j] : std::numeric_limits<int>::max();
            int from_left = (j > 0) ? dp[i][j - 1] : std::numeric_limits<int>::max();

            if (i == 0 && j == 0) {
                // Если мы в левом верхнем углу, просто присваиваем значение ячейки grid
                dp[i][j] = grid[i][j];
            } else {
                // Иначе, выбираем минимум из значений from_top и from_left и добавляем текущее значение grid
                dp[i][j] = grid[i][j] + std::min(from_top, from_left);
            }
        }
    }

    // Возвращаем минимальную стоимость пути в правом нижнем углу
    return dp[m - 1][n - 1];
}

/* Driver Function to test other function */
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Timer T("Go!");

    // Пример использования
    std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << "Min path sum: " << minPathSum(grid) << std::endl;

    T.print();

    return 0;
}
