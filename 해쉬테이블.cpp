#include <iostream>
using namespace std;

class item {
public:
	int key;
	item() {
		key = -1;
	}
	item(int key) {
		this->key = key;
	}
};

class hash_arr {
public:
	item* data;
	bool* flag;
	hash_arr() {
		this->flag = new bool[353333];
		this->data = new item[353333];
	}
	int hash_code(int key) {
		return key % 353333;
	}
	int hash_code2(int key) {
		return (17 - (key % 17));
	}
	void linear_probing(int key) {
		int index = hash_code(key);
		int i = index;
		while (flag[i] == true) {
			if (data[i].key == key) {
				return;
			}
			i = (i + 1) % 353333;
			if (i == index) {
				return;
			}
		}
		flag[i] = true;
		item ins(key);
		data[i] = ins;
	}

	void linear_search(int key) {
		int e = 0;
		int cnt = 1;
		item* ret = NULL;
		int index = hash_code(key);
		int i = index;
		while (flag[i] == true) {
			e = 1;
			if (data[i].key == key) {
				break;
			}
			i = (i + 1) % 353333;
			cnt++;
			if (i == index) {
				break;
			}
		}
		cout << e << " " << cnt << endl;
	}

	void double_hashing(int key) {
		int code1 = hash_code(key);
		int code2 = hash_code2(key);
		int i = code1;
		while (flag[i] == true) {
			i = (i + code2) % 353333;
			if (i == code1) { break; }
		}
		flag[i] = true;
		item ins(key);
		data[i] = ins;
	}

	void double_hashing_search(int key) {
		int code1 = hash_code(key);
		int code2 = hash_code2(key);
		int i = code1;
		while (flag[i] == true) {
			if (data[i].key == key) {
				cout << 1 << endl;
				return;
			}
			else {
				i = (i + code2) % 353333;
			}
			if (i == code1) {
				return;
			}
		}
		cout << 0 << endl;
	}
};

int main() {
	int N, M;
	int in;
	cin >> N;
	hash_arr H;
	for (int i = 0; i < N; i++) {
		cin >> in;
		H.linear_probing(in);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> in;
		H.linear_search(in);
	}
	return 0;
}