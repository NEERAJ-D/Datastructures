// Allpermutationsstring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(char *a, int i, int n) {
    int j;
    if(i == n) {
        printf("%s\n", a);
    } else {
        for(j = i; j <= n; j++) {
            swap(a + i, a + j);
            print(a, i + 1, n);
            swap(a + i, a + j);
        }
    }
}

int main(void) {
    char a[100];
    //gets(a);
    cin>>a;
    print(a, 0, strlen(a) - 1);
    return 0;
}