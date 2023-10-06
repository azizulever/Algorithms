#include<bits/stdc++.h>
#define nl endl
using namespace std;

void knapsack(int n, float* weights, float* profits, float capacity) {
    float x[20], total_profit = 0;
    int i, j;
    float remaining_capacity = capacity;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++) {
        if (weights[i] > remaining_capacity)
            break;
        else {
            x[i] = 1.0;
            total_profit += profits[i];
            remaining_capacity -= weights[i];
        }
    }
    if (i < n)
        x[i] = remaining_capacity / weights[i];

    total_profit += (x[i] * profits[i]);

    cout << "Maximum profit is: " << total_profit;
}

int main() {
    float weights[20], profits[20], capacity;
    int num, i, j;
    float profit_to_weight_ratio[20], temp;

    cout << "Number of objects: ";
    cin >> num;

    cout << endl << "Weights & profits: ";
    for (i = 0; i < num; i++) {
        cin >> weights[i] >> profits[i];
    }

    cout << endl << "Capacity: ";
    cin >> capacity;

    for (i = 0; i < num; i++) {
        profit_to_weight_ratio[i] = profits[i] / weights[i];
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            if (profit_to_weight_ratio[i] < profit_to_weight_ratio[j]) {
                temp = profit_to_weight_ratio[j];
                profit_to_weight_ratio[j] = profit_to_weight_ratio[i];
                profit_to_weight_ratio[i] = temp;

                temp = weights[j];
                weights[j] = weights[i];
                weights[i] = temp;

                temp = profits[j];
                profits[j] = profits[i];
                profits[i] = temp;
            }
        }
    }
    knapsack(num, weights, profits, capacity);
    return 0;
}
