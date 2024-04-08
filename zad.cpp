#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define max_rozm 100

typedef struct {
    int tab[max_rozm];
    int wierzch;
} Stos;

void init(Stos& s) {
    s.wierzch = -1;
}

void push(Stos& s, int licz) {
    if (s.wierzch < max_rozm - 1) {
        s.tab[++s.wierzch] = licz;
    } else {
        cout << "Stos jest pe³ny, nie mo¿na dodaæ elementu: " << licz << endl;
    }
}

void pop(Stos& s) {
    if (s.wierzch != -1) {
        --s.wierzch;
    }
}

int top(Stos& s) {
    if (s.wierzch != -1) {
        return s.tab[s.wierzch];
    }

    return -1;
}

int empty(Stos& s) {
    return s.wierzch == -1 ? 1 : 0;
}

int full(Stos& s) {
    return s.wierzch == max_rozm - 1? 1 : 0;
}

int main() {
    srand(time(NULL));

    Stos stos;
    init(stos);

    int liczbaElementow = rand() % (max_rozm + 1);

    for(int i = 0; i < liczbaElementow; i++) {
        push(stos, rand() % 100);
    }

    cout << "Elementy stosu:" << endl;
    while (empty(stos) == 0) {
        cout << top(stos) << endl;
        pop(stos);
    }

    return 0;
}
