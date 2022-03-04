/*
 * https://quera.org/problemset/52548/
 * Author: https://github.com/smh997/
 */
#include <stdio.h>

int main()
{
    int n, T, t, e, s = 0, se = 0, me;
    scanf("%d %d", &n, &T);
    me = - T;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &t, &e);
        if(t + s <= T){
            s += t;
            se += e;
            if(me < se - (T - s)){
                me = se - (T - s);
            }
        }
        else
            break;
    }
    printf("%d\n", me);
    return 0;
}

