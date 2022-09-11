#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void LetraA();
void LetraB();
void LetraC();
void LetraD();




int main()
{
    int op;
    setlocale(LC_ALL,"portuguese");
    system("CLS");

    printf("Escolha uma opção: ");
    printf("\n1 - Letra A");
    printf("\n2 - Letra B");
    printf("\n3 - Letra C");
    printf("\n4 - Letra D");
    printf("\n0 - SAIR");
    printf("\n- Escolha: ");
    scanf("%i", &op);

    do
    {
        switch(op)
        {
        case 0:
            return 0;
            break;
        case 1:
            LetraA();
            break;
        case 2:
            LetraB();
            break;
        case 3:
            LetraC();
            break;
        case 4:
            LetraD();
            break;
        default:
            return 0;
        }
        system("pause");
    }
    while (op != 0);

    fflush(stdin);
}

void LetraA()
{
    FILE * serie_de_fibonacci;
    if((serie_de_fibonacci=fopen("serie_de_fibonacci.txt","w"))==NULL)
    {
        printf("Erro de abertura do arquivo!\n");
    }
    else
    {
       double n, aux, ter, fib;
        ter=0;
        aux=1;
        n=0;
        fib=1;
        fprintf(serie_de_fibonacci,"%5.2lf\n",fib);
        while(ter<=64)
        {
            fib=aux+n;
            fprintf(serie_de_fibonacci,"%5.2lf\n",fib);
            n=aux;
            aux=fib;
            ter++;
        }
        fprintf(serie_de_fibonacci,"Esses sao os numeros de fibonacii!\n");

    }
    fclose(serie_de_fibonacci);
    main();
}
void LetraB()
{
    FILE * pares, * impares, * arquivo;
    double num, resto;
    if((arquivo=fopen("serie_de_fibonacci.txt","r"))==NULL)
    {
        printf("Erro de sintaxe");
    }
    else
    {
        pares=fopen("pares.txt","w");
        impares=fopen("impares.txt","w");
        while(!feof(arquivo))
        {
            fscanf(arquivo,"%lf",&num);
            resto = remainder(num,2);
            if(resto == 0)
            {
                fprintf(pares,"%.0f\n",num);
            }
            else
            {
                fprintf(impares,"%.0f\n",num);
            }
        }
    }
    fclose(pares);
    fclose(impares);
    fclose(arquivo);
    fflush(stdin);
    main();
}
//c) - ler o arquivo letra a e armazenar apenas os primos em um arquivo

void LetraC ()
{
    FILE * Serie_de_Fibonacci, * primo;
    long long int a;
    if((Serie_de_Fibonacci= fopen("serie_de_fibonacci.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        primo = fopen("primo.txt","w");
        while(a!=10610209857723)
        {
            fscanf(Serie_de_Fibonacci,"%lli",&a);
            if(a%2==0 && a!=2 && a!=1 || a%3==0 && a!=3 && a!=1 || a%5==0 && a!=5 && a!=1)
            {
                continue;
            }
            else
            {
                fprintf(primo, "%lli\n",a);
            }
        }
        fclose(primo);
        printf("Valores primos separados e gravados com sucesso!\n\n");
    }
    fflush(stdin);
    main();
}

/*d) - leia um conjunto de valores (flag -1) e verifique para cada valor se ele se encontra ou não no arquivo
gravado na letra a. Caso não exista deverá mostrar o valor anterior e o posterior a esse valor. Exemplo:
caso seja lido o valor 8 – deverá ser mostrada a informação o valor 8 está no arquivo na posição 6, caso o
valor lido seja o 17 – deverá ser mostrada a informação o valor 17 não está no arquivo, valores mais
próximos: 13 e 21.*/

void LetraD ()
{
    FILE*Serie_de_Fibonacci;
    long long int a, numb;
    int conjval, posinum;
    posinum=0;
    conjval=0;
    if((Serie_de_Fibonacci = fopen("Serie_de_Fibonacci","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        while(conjval!=-1)
        {
            printf("Qual o valor deseja buscar: \n");
            scanf("%i",&conjval);
            Serie_de_Fibonacci = fopen("Serie de Fibonacci.txt","r");
            while(!feof(Serie_de_Fibonacci))
            {
                fscanf(Serie_de_Fibonacci,"%lli",&a);
                posinum++;
                if(conjval==a)
                {
                    printf("O valor %i esta no arquivo na posicao %i\n\n\n",conjval, posinum);
                }
                if(numb<conjval && conjval<a)
                {
                    printf("O valor %i nao esta no arquivo, valores mais proximos:%lli e %lli\n\n\n", conjval, numb, a);
                }
                numb=a;
            }
            system("pause");
            system("CLS");
            printf("Para parar a busca digite -1\n");
            posinum=0;
        }
        system("CLS");
        fclose(Serie_de_Fibonacci);
    }
    fflush(stdin);
    main();
}
