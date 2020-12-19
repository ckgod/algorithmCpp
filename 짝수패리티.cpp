#include <iostream>
#include <string>
using namespace std;

string result;
int cnt = 0;

void dec_bin(int dec) {
	for (int i = 3; i >= 0; i--) {
		if (dec & (1 << i)) { // &:비트연산자, << 2진법1을 왼쪽으로 i만큼 shift해줌
			result = result + '1';
			++cnt; // 1이 나올때마다
		}
		else {
			result = result + '0';
		}
	}
}

void main() {
	char raw;
	int ten, one;
	cin >> raw;
	ten = raw / 10;
	one = raw % 10;

	dec_bin(ten);
	dec_bin(one);

	if (cnt % 2 == 0) { // 1의개수가 짝수일때 앞에 0 
		result = '0' + result;
		cout << result << endl;
	}
	else { // 1의 개수가 홀수일때 앞에 1
		result = '1' + result;
		cout << result << endl;
	}
}