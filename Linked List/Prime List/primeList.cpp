#include <string>


class Node {
    public:

    int val;
    Node* next;

    Node(int num): val(num) {};
};


class Solution {

    bool isPrime[10001];
    int nearestPrime[10001];

    Solution(): isPrime{0}, nearestPrime{0} {};

    void computePrimes() {

        memset(isPrime, 1, sizeof isPrime);

        for (int i = 2; i < 10001; i++) {
            if (!isPrime[i]) continue;
            for (int j = i*i; j < 10001; j*=i) 
                isPrime[j] = false;
        }
        int currPrime = 2;

        for (int i = 0; i < 10001; i++) {
            if (isPrime[i]) {
                nearestPrime[i] = i;
                currPrime = i;
            } else {
                nearestPrime[i] = currPrime;
            }
        }

        currPrime = 10007;  // last Prime Number nearest to 10000

        for (int i = 10000; i >= 0; i--) {
            if (isPrime[i]) 
                currPrime = i;
            else if (i - nearestPrime[i] > currPrime - i) 
                nearestPrime[i] = currPrime;
        }
    }

    public:

    Node* primeList(Node *head) {

        Node *temp = head;

        while (temp != nullptr) {
            if (!isPrime[temp->val]) 
                temp->val = nearestPrime[temp->val];
            temp = temp->next;
        }

        return head;
    }

};