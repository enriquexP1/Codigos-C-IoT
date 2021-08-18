#include <stdio.h>
int retardo(unsigned int ciclos)
{
    unsigned int cuenta;

    for (cuenta = 0; cuenta < ciclos; cuenta++);
    return 0;
}
void imprimircuenta()
{
    unsigned int ciclos = 20000000;
    unsigned int x;
    for (size_t i = 0; i < 10; i++)
    {
        printf("0000\n");
        retardo(ciclos);
        printf("0001\n");
        retardo(ciclos);
        printf("0010\n");
        retardo(ciclos);
        printf("0100\n");
        retardo(ciclos);
        printf("1000\n");
        retardo(ciclos);
    }
}
int main()
{

    imprimircuenta();
    return 0;
}