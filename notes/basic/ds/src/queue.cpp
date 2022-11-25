#include <iostream>

using namespace std;

const int N = 100010;

int q[N], hh, tt = -1;
void enqueue(int x) { q[++tt] = x; }
int dequeue() { return q[hh++]; }
bool empty() { return hh <= tt; }
int head() { return q[hh]; }
int tail() { return q[tt]; }