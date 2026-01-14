#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long c = get_long("Qual o numero do cartao: ");
    long num_original = c;
    int contador = 0;
    int soma1 = 0;
    int soma2 = 0;

    int resto = 0;
    long inteiro = 0;
    int mult = 0;
    int restin = 0;
    int somatotal = 0;

    do
    {
        resto = c % 10;
        if (contador % 2 == 0)
        {
           soma1 = soma1 + resto;
        }
        else
        {
            mult = resto * 2;
            inteiro = mult / 10;
            restin = mult % 10;
            soma2 = soma2 + inteiro + restin;
        }
        c = c / 10;
        contador++;
    }
    while (c > 0);

    somatotal = soma1 + soma2;
    if (somatotal % 10 == 0)
    {
        while (num_original >= 100)
        {
            num_original = num_original / 10;
        }
        if ((num_original / 10 == 4) && (contador == 13 || contador == 16))
        {
            printf("VISA\n");
        }
        else if ((num_original == 34 || num_original == 37) && (contador == 15))
        {
            printf("Cartao AMEX\n");
        }
        else if ((num_original == 51 || num_original == 52 || num_original == 53 || num_original == 54 || num_original == 55)
        && (contador == 16))
        {
            printf("Cartao MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
