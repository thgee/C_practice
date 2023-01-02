// .11-5 (추가)cpp

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Player {
	char name[11];
	int power;
	int hp;
}Player;


void fight(Player p[], int N);
void sortAndPrint(Player p[], int N);

int main() {

	int N;
	scanf("%d", &N);
	Player p[10];
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d", p[i].name, &p[i].power, &p[i].hp);
	}

	fight(p, N);
	sortAndPrint(p, N);



	return 0;
}


void fight(Player p[], int N) {
	char p1[11], p2[11]; // p1와 p2가 싸움
	int idx1, idx2;

	for (int n = 0; n < 5; n++) {

		scanf("%s%s", p1, p2);

		for (int i = 0; i < N; i++) {
			if (strcmp(p1, p[i].name) == 0) idx1 = i;
			if (strcmp(p2, p[i].name) == 0) idx2 = i;
		}

		p[idx1].hp -= p[idx2].power;
		p[idx2].hp -= p[idx1].power;

		for (int i = 0; i < N; i++)
			if (p[i].hp < 0) p[i].hp = 0;

		for (int i = 0; i < N; i++)
			if (p[i].hp == 0) return;

	}
}

void sortAndPrint(Player p[], int N) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1 - i; j++) {
			Player tmp;
			if (p[j].hp < p[j + 1].hp) {
				tmp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = tmp;
			}
		}
	for (int i = 0; i < N; i++)
		printf("%s %d\n", p[i].name, p[i].hp);
}

