#include <Windows.h>
#include <iostream>
#include <vector>

#include "Timer.h"

using namespace std;

int maxSumJump(std::vector<int>& jumps) {
    int n = jumps.size();
    if (n == 0) return 0;

    // Создаем массив для хранения решений подзадач
    std::vector<int> dp(n + 1, 0);

    // Начинаем с первого элемента
    for (int i = 1; i <= n; ++i) {
        // Для каждого элемента выбираем максимум из двух вариантов:
        // 1. Продолжить суммирование из предыдущего элемента
        // 2. Начать новую последовательность, добавив к текущему элементу результат с предыдущего,
        //    но пропустив предыдущий элемент
        dp[i] = std::max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0) + jumps[i - 1]);
    }

    // Вернуть максимальную сумму
    return dp[n];
}


/* Driver Function to test other function */
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Timer T("Bunny");
    // Пример использования
    std::vector<int> jumps = {1, 2, 3, 4, 5};
    std::cout << "Max sum of non-adjacent jumps: " << maxSumJump(jumps) << std::endl;
    T.print();

    return 0;
}
