//T-PRIME
#include <iostream>
#include <math.h>
using namespace std;

const int MAX_PRIME = 1e6;

bool *is_prime;

void initPrimeList(int max_prime) { //Khoi tao danh sach so nguyen to
	max_prime = max_prime + 1;
	is_prime = new bool[max_prime];
	for (int i = 0; i < max_prime; ++i) { //GS Ban dau tat ca deu la so nguyen to
		is_prime[i] = true;
	}
	
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i < max_prime; ++i) {
		if (is_prime[i]) { //neu so i la nguyen to
			for (int j = i * i; j < max_prime; j += i) { //danh dau nhung so chia het cho i la khong nguyen to
				is_prime[j] = false;
			}
		}
	}
}

int findSqrt(unsigned long long x) { //tim y : y^2 = x
	unsigned long long left = 0;
	unsigned long long right = x;
	unsigned long long middle, sqr_middle;
	while (left <= right) {
		middle = (left + right) / 2;
		sqr_middle = middle * middle;
		//cout << left << " " << right << " " << middle << " " << sqr_middle << endl;
		if (sqr_middle == x) return middle;
		if (sqr_middle > x) {
			right = middle - 1;
			continue;
		}
		left = middle + 1;
	}
	return 0;
}

void solve1(unsigned long long value) {
	unsigned long long sqrt_value = (unsigned long long)sqrt(value);
	if (sqrt_value * sqrt_value == value && is_prime[sqrt_value]) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

void solve2(unsigned long long value) {
	unsigned long long sqrt_value = findSqrt(value);
	//cout << sqrt_value << endl;
	if (is_prime[sqrt_value]) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

int main() {
	int n;
	unsigned long long value;
	unsigned long long sqrt_value;
	//cout << findSqrt(9) << endl;
	cin >> n;
	initPrimeList(MAX_PRIME);
	for (int i = 0; i < n; ++i) {
		cin >> value;
		//solve1();
		solve2(value);
	}	
	return 0;
}
