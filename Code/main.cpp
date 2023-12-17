//    Задача:
//    Два друга A и B постоянно играют в коллекционную карточную игру (ККИ),
//    поэтому у каждого игрока скопилась довольно большая коллекция карт.
//    Каждая карта в данной игре задаётся целым числом (одинаковые карты — одинаковыми числами,
//    разные карты — разными). Таким образом коллекцию можно представить как неупорядоченный набор целых чисел (с возможными повторениями).
//
//    Формат ввода
//    1) В первой строке через пробел заданы числа 1 <= N, M, Q <= 100'000,
//          где N - количество карт в коллекции игрока A,
//          M - количество карт в коллекции игрока B,
//          Q - количество ходов в игре. Например: "2 5 10";
//    2) Во второй строке содержится коллекция карт игрока A. Например: "1 2";
//    3) В третьей строке содержится коллекция карт игрока B. Например: "1 2 3 4 5".
//    4) Начиная с 4-й строки через пробел заданы "type player card",
//          где type равен 1 (в коллекцию игрока player добавляется карта card)
//          или -1 (из коллекции игрока player удаляется карта card),
//          player равен A или B,
//          card - значение карты.
//
//    Формат вывода:
//    На каждой итерации необходимо выводить через пробел целые числа:
//          количество отличающихся карт в коллекциях игроков A и B.
//
//    *** Пример 1
//
//    Ввод
//    2 5 10
//    1 2
//    1 2 3 4 5
//    1 A 3
//    1 A 4
//    1 A 5
//    1 A 6
//    1 A 7
//    -1 A 1
//    1 B 7
//    -1 A 6
//    -1 B 1
//    1 A 7
//
//    Вывод
//    2 1 0 1 2 3 2 1 0 1

//    *** Пример 2
//    3 3 5
//    1000 2000 1001
//    1001 2001 1000
//    1 A 100000
//    -1 B 2001
//    1 B 2000
//    1 B 100001
//    1 A 1
//
//    вывод
//    3 2 1 2 3


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    const int MAX_CARD = 2'00'000;
    vector<long long int> collectionA (MAX_CARD, 0);
    //collectionA.reserve(MAX_CARD);
    vector<long long int> collectionB (MAX_CARD, 0);
    //collectionB.reserve(MAX_CARD);
    unordered_map<long long int, long long int> countA, countB;
    vector<int> diffCounts;

    //int diffCount = 0;

    for (int i = 0; i < N; ++i) {
        int card;
        cin >> card;
        collectionA[card]++;
        countA[card]++;
    }

    for (int i = 0; i < M; ++i) {
        int card;
        cin >> card;
        collectionB[card]++;
        countB[card]++;
    }

    for (int i = 0; i < Q; ++i) {
        int type;
        char player;
        int card;

        cin >> type >> player >> card;
        int diffCount = 0;

        if (player == 'A') {
            if (type == 1) {
                collectionA[card]++;
            } else {
                auto diff = collectionA[card] - 1;
                collectionA[card] = diff > 0 ? diff : 0;
            }
        } else
        {
            if (type == 1) {
                collectionB[card]++;
            } else {
                auto diff = collectionB[card] - 1;
                collectionB[card] = diff > 0 ? diff : 0;
            }
        }

        // Пересчет diffCount после каждого хода
        diffCount = 0;
        for (size_t i = 1; i <= MAX_CARD; ++i) {
            diffCount += abs(collectionA[i] - collectionB[i]);
        }

        // Сохранение разницы между коллекциями после хода
        diffCounts.push_back(diffCount);
    }

    for (int i = 0; i < diffCounts.size(); ++i) {
        if (i) {
            cout << " ";
        }
        cout << diffCounts[i];
    }

    return 0;
}
