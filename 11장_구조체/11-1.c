// 11 - 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct vec3 {
	int x, y, z;
};

int main() {
	int x1, y1, z1;
	int x2, y2, z2;
	scanf("%d%d%d", &x1, &y1, &z1);
	scanf("%d%d%d", &x2, &y2, &z2);
	struct vec3 V1 = { x1, y1, z1 };
	struct vec3 V2 = { x2, y2, z2 };
	struct vec3 V3 = { V1.x * V2.x, V1.y * V2.y, V1.z * V2.z };

	printf("%d %d %d\n", V3.x, V3.y, V3.z);
	printf("%d", V3.x + V3.y + V3.z);

	return 0;
}