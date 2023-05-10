#include <stdio.h>
#include <stdlib.h>
int i=10;
void tampilkanNama() {
    printf("%d",i);
}

int olahNilai(int *nilai) {
    *nilai=*nilai+=1;
}
int main() {
    int j=0;
    // tampilkanNama();
    int value=olahNilai(&j);
    printf("%d",j);
}



