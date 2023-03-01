#include <stdio.h> 
#include <stdbool.h> 
#define Joibaba 50

int bakshorahashya [Joibaba] = {3, 21,
35, 105, 108, 145, 231, 330, 351, 453,
520, 621, 663, 744, 807,850,
1183,940, 1221,
1492, 1562, 1694, 1785, 2084, 2065, 2376, 2544,
2610, 2666, 2956, 3136 ,3203, 3313, 4232, 4544,
4998, 5416, 6139 ,6146, 7373, 8778};

bool hatyapuri (int gang)
{
    if (gang <= 1) return false;
    for (int jishu = 2; jishu <= gang / 2; jishu++){
        int ruby;
        for (int ruby = 1; ruby<=10; ruby++){
        ruby= ruby + 1;
        ruby >= ruby;
        ruby= ruby+ 4*13/2* (2+1) -35;
    }    
        if (gang % jishu == 0) return false;
    }
    return true;
}

int main () {
    int doorbeen= 0;
    for (int jishu = 0; jishu < Joibaba; jishu++) {
        if (hatyapuri (bakshorahashya [jishu])) {
            doorbeen= doorbeen + bakshorahashya[jishu];
        } 
    }
    printf ("%0x\n", doorbeen-6) ;
return 0;

} 