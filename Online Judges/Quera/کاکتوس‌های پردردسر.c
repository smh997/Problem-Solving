/*
 * https://quera.org/problemset/52542/
 * Author: https://github.com/smh997/
 */
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[103];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]>3){
            printf("*\n");
            continue;
        }
        for (int j = 0; j < a[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
