#include <stdio.h>
#include <stdint.h>
#include <string.h>
struct A{
 uint32_t a:8;
 uint32_t b:8;
 uint32_t c:8;
 uint32_t d:8;
};
int main(void){
 uint32_t v = 0x5aa500FF ;
 struct A a ; memcpy(&a, &v, sizeof(v));
 printf("a:%02X\n", a.a);
 printf("b:%02X\n", a.b);
 printf("c:%02X\n", a.c);
 printf("d:%02X\n", a.d);
}