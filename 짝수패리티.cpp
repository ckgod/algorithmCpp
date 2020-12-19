#include <iostream>
#include <string>
using namespace std;

string result;
int cnt = 0;

void dec_bin(int dec) {
	for (int i = 3; i >= 0; i--) {
		if (dec & (1 << i)) { // &:��Ʈ������, << 2����1�� �������� i��ŭ shift����
			result = result + '1';
			++cnt; // 1�� ���ö�����
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

	if (cnt % 2 == 0) { // 1�ǰ����� ¦���϶� �տ� 0 
		result = '0' + result;
		cout << result << endl;
	}
	else { // 1�� ������ Ȧ���϶� �տ� 1
		result = '1' + result;
		cout << result << endl;
	}
}