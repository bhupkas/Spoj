/* bhupkas */
#include "stdio.h"
#include "string.h"
using namespace std;

typedef long long LL;

const LL base[2][2] = {{1, 1}, {1, 0}}, unit[2][2] = {{1, 0}, {0, 1}};

void mul(LL a[2][2], LL b[2][2], LL mod) {
	int i, j, k;
	LL c[2][2];
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			for(c[i][j] = k = 0; k < 2; k++) {
				c[i][j] += a[i][k] * b[k][j];
				if(c[i][j] >= mod) c[i][j] %= mod;
			}
		}
	}
	memcpy(a, c, sizeof(LL)*4);
}

void exp(LL res[2][2], LL p, LL mod) {
	LL b[2][2];
	memcpy(res, unit, sizeof(LL)*4);
	memcpy(b, base, sizeof(LL)*4);
	while(p > 0) {
		if(p & 1) mul(res, b, mod);
		mul(b, b, mod);
		p >>= 1;
	}
}

LL fib(LL n, LL mod) {
	LL res[2][2];
	if(!n) return 0;
	exp(res, n - 1, mod);
	return res[0][0];
}

int main() {
	int test, cs;
	LL n, m, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld %lld", &n, &m);
		res = (2*(fib(n+2, m) - 1) - n) % m;
		if(res < 0) res += m;
		printf("%lld\n", res);
	}
	return 0;
}
