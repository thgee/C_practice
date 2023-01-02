#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
  int n[4];
  unsigned int s;
  for(int i = 0; i < 4; i++)
    scanf("%d", &n[i]);

  s = (n[0] << 24) | (n[1] << 16) | (n[2] << 8) | n[3];
  printf("%d", s);
}