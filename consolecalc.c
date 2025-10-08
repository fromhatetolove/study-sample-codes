#include <stdio.h>

int main()
{
    /* We define result, inputed num, flag and operator */
    int res = 0, inn, flag = 1;
    char ope;

    scanf("%d", &inn);
    res = inn;

    for (;;) {
        if (flag == 1) {
            scanf("%c", &ope); 
            if (ope == '=') break;
        } else if (flag == -1) {
            scanf("%d", &inn);
            switch(ope) {
                case '+': res += inn; break;
                case '-': res -= inn; break;
                case '*': res *= inn; break;
                case '/': res /= inn; break;
            }
        }
        flag = -flag; // set opposite
    }

    printf("Result=%d\n", res);

    return 0;
}