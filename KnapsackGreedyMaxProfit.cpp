#include <iostream>
#define MAX 100
using namespace std;
int main ()
{
    freopen ("knapsack.txt", "r", stdin);

    int items, capacity, remainingCapacity, totalProfit = 0, totalWeight = 0;
    cout << "How many items are there?" << endl;
    cin >> items;

    struct A {
        double object, weight, benefit, benPerUnit;
    } knapsack[MAX];

    for (int i = 0; i < items; i++){
        knapsack[i].object = i+1;
    }

    cout << "Input the weights :" << endl;
    for (int i = 0; i < items; i++){
        cin >> knapsack[i].weight;
    }
    cout << "Input the benefits :" << endl;
    for (int i = 0; i < items; i++){
        cin >> knapsack[i].benefit;
    }

    for (int i = 0; i < items; i++){
        knapsack[i].benPerUnit = knapsack[i].benefit / knapsack[i].weight;
    }

    cout << "Enter the capacity of the knapsack : ";
    cin >> capacity;
    remainingCapacity = capacity;

    //sorting with respect to benefit per unit
    for (int i = 0; i < items; i++){
        for (int j = i+1; j < items; j++){

            if (knapsack[i].benPerUnit < knapsack[j].benPerUnit){

                struct A temp = knapsack[i];
                knapsack[i] = knapsack[j];
                knapsack[j] = temp;
            }
        }
    }

    int i = 0;
    while (remainingCapacity > 0){

        if (knapsack[i].weight < remainingCapacity){

            totalWeight += knapsack[i].weight;
            totalProfit += knapsack[i].benefit;
            remainingCapacity -= knapsack[i].weight;

            cout << knapsack[i].weight << " unit of jar no. " << knapsack[i].object << " with benefit " << knapsack[i].benefit << endl;

            i++;
        }
        else{

            totalWeight += remainingCapacity;
            totalProfit += remainingCapacity * knapsack[i].benPerUnit;

            cout << remainingCapacity << " unit of jar no. " << knapsack[i].object << " with benefit " << remainingCapacity * knapsack[i].benPerUnit << endl;
            remainingCapacity -= remainingCapacity;

            i++;
        }

    }

    cout << "Maximum profit : " << totalProfit << endl;
    cout << "Total capacity : " << totalWeight << endl;

    return 0;
}