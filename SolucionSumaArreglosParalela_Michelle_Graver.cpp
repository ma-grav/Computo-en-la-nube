// SolucionSumaArreglosParalela_Michelle_Graver.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

using namespace std;
#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main()
{
    cout << "Sumando arreglos en paralelo.\n";
    float a[N], b[N], c[N];
    int i;

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        a[i] = rand();
        b[i] = rand();

    }

    int pedazos = chunk;


#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i)\
    schedule(static, pedazos)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << endl;
    imprimeArreglo(a);
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << endl;
    imprimeArreglo(b);
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << endl;
    imprimeArreglo(c);

}

void imprimeArreglo(float* d) {
    for (int x = 0; x < mostrar; x++) {
        cout << d[x] << " - ";
    }
    cout << endl;
}