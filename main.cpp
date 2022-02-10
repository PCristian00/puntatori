#include <iostream>

using namespace std;

//Restituisce il maggiore tra i due
int maxn(int a, int b) {
    if (a >= b) return a;
    return b;
}

//Restituisce un puntatore al maggiore tra i due
int *max(int *pa, int *pb) {
    if (*pa >= *pb) return pa;
    return pb;
}

//Restituisce l'indirizzo al maggiore tra i due
int &max(int &ra, int &rb) {
    if (ra >= rb) return ra;
    return rb;
}

//Incrementa ciò che riceve (char o int) di 1.
void incrementa(void *data, int pdim) {
    if (pdim == sizeof(char)) {
        char *pchar;
        pchar = (char *) data;
        ++(*pchar);
    } else if (pdim == sizeof(int)) {
        int *pint;
        pint = (int *) data;
        ++(*pint);
    }
}

//Addizione tra due interi
int addizione(int a, int b) { return (a + b); }

//Sottrazione tra due interi
int sottrazione(int a, int b) { return (a - b); }

//Operazione tra due interi (puntatore a funzione come parametro)
int operazione(int x, int y, int (*funzdachiamare)(int, int)) {
    int g;
    g = (*funzdachiamare)(x, y);
    return (g);
}


int main() {
    int x = 5, y = 10;
    //cin>> x >> y;
    // maxn(x,y)=0 non può essere compilato
    // La funzione non cambia i valori di x e y, è inutile per il nostro caso
    int maggiore = maxn(x, y);
    maggiore = 0;
    cout << "x = " << x << " y = " << y << '\n';

    cout << endl;

    //cin >> x >> y;
    //Il puntatore al maggiore diventa zero -> il maggiore diventa zero
    *max(&x, &y) = 0;
    cout << "x = " << x << " y = " << y << '\n';

    cout << endl;

    //cin >> x >> y;
    //Il maggiore diventa zero
    max(x, y) = 0;
    cout << "x = " << x << " y = " << y << '\n';

    cout << endl;

    char a = 'x';
    int b = 1602;
    cout << a << ", " << b << '\n';
    incrementa(&a, sizeof(a));
    incrementa(&b, sizeof(b));
    cout << a << ", " << b << '\n';

    int m, n;
    int (*meno)(int, int) = sottrazione; // definisce un puntatore a
    // funzione e lo assegna a sottrazione
    m = operazione(7, 5, addizione);
    cout << "7 + 5 = " << m << endl;
    n = operazione(20, m, meno);
    cout << "20 - " << m << " = " << n << endl;


    return 0;
}
