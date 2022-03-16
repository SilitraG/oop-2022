#define _CRT_SECURE_NO_WARNINGS  

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define length 255

int main()
{
    char string[length], *p, v[20][20], aux[length];
    int i, j, n=0;
    scanf("%[^\n]s", string);       ///citeste string.ul

    p = strtok(string, " ");        ///extrage primul cuvant
    while (p)
    {
        strcpy(v[n], p);            ///formez vectorul de cuvinte
        n++;                        ///dimensiunea vectorului
        p = strtok(NULL, " ");      ///continuitate pe extragere
    }
    
    ///sortare
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((strlen(v[i]) < strlen(v[j])) || (strlen(v[i]) == strlen(v[j]) && strcmp(v[i], v[j]) < 0))
            {
                strcpy(aux, v[i]);
                strcpy(v[i], v[j]);
                strcpy(v[j], aux);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", v[i]);       ///afisare
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
