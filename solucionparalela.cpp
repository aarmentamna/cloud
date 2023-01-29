#include <iostream>

#ifdef _OPENMP
    #include <omp.h>
#endif

#define N 24
using namespace std;
int tid;
int main()
{
    // INICIALIZACION DE VARIABLES
    int nNum = 15;
    int arreglos = 3;
    int nHilos = 2;
    int tamanio = nNum/arreglos;
    int resultSum[tamanio];
    int bidimensional[arreglos][tamanio];
    int contador = 0;
    int sum = 0;

    // MENSAJES CON LA CONFIGURACION
    cout << "SE ESTABLECIO UNA CANTIDAD DE VALORES NUMERICOS CON LOS QUE SE DESEA  TRABAJAR DE: !\n" <<nNum << endl;
    cout << "SE ESTABLECIO UNA CANTIDADA DE ARREGLOS QUE SE VAN A UTILIZAR DE!\n" << arreglos << endl;
    cout << "SE ESTABLECIO UNA CANTIDAD DE HILOS QUE VAN A UTILIZAR PARA PROCESAR LA OPERACION DE"; << nHilos << endl;

    // LLENAMOS LA MATRIZ CON VALORES DEL 1 A TAMAÑO
    while(contador < arreglos){
        for(int i = 0; i < tamanio; i++){
            bidimensional[contador][i] = sum +1;
            sum ++;
        }
        contador ++;
    }
    // INICIALIZAMOS EL ARREGLO DE RESULTADOS
    for(int i = 0; i<tamanio; i++){
        resultSum[i] = 0;   
    }    
    // DEFINIMOS LOS HILOS
    #ifdef _OPENMP
        omp_set_num_threads(nHilos);
    #endif
    // REALIZAMOS UN FOR PARALLEL PARA RESOLVER LA OPERACION CON N HILOS DEFINIDOS
    #pragma omp parallel for
    for(int i = 0; i < tamanio; i++)
    {
        tid = omp_get_thread_num();
        int contador = 0;
        while(contador < arreglos){
            cout << "LA OPERACION SUMA DE VECTORES EN LA POSICION [" << contador << "][" << i <<"] ES PROCESADA POR EL THREAD : " << tid << endl;
            resultSum[i] = resultSum[i] + bidimensional[contador][i]; 
            contador ++;
        }
    }
    // PRESENTAMOS RESULTADOS
    for(int i=0; i < tamanio; i++){
        cout << "EL RESULTADO DEL LA OPERACION EN LA POSICION :" << i <<" ES IGUAL A:  " << resultSum[i] << endl;
    }   
}