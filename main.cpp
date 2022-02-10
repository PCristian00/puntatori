#include <iostream>
using namespace std;

//Restituisce il maggiore tra i due
int maxn(int a, int b){
    if(a>=b) return a;
    return b;
}

//Restituisce un puntatore al maggiore tra i due
int* max(int* pa, int* pb)
{
    if (*pa >= *pb) return pa;
    return pb;
}

//Restituisce l'indirizzo al maggiore tra i due
int& max(int& ra, int& rb)
{
    if (ra >= rb) return ra;
    return rb;
}


int main()
{ int x, y;
    cin>> x >> y;
    // maxn(x,y)=0 non può essere compilato
    // La funzione non cambia i valori di x e y, è inutile per il nostro caso
    int m=maxn(x,y);
    m=0;
    cout << "x = " << x << " y = " << y << '\n';

    cin >> x >> y;
    //Il puntatore al maggiore diventa zero -> il maggiore diventa zero
    *max(&x, &y) = 0;
    cout << "x = " << x << " y = " << y << '\n';

    cin >> x >> y;
    //Il maggiore diventa zero
    max(x, y) = 0;
    cout << "x = " << x << " y = " << y << '\n';

    return 0;
}
