#include <iostream>
#include <sstream>
using namespace std;

bool isNum(char x) {
	if (x >= '0' && x <= '9') return true;
	return false;
}
bool isRGB(char x) {
	if (x == 'R' || x == 'G' || x == 'B') return true;
	return false;
}
string f(string arr) {
	string tmp;
	for (int i = 0; i < arr.size(); i++) {
		if (isNum(arr[i])) {
			int t = arr[i] - '0';
			if (isRGB(arr[i + 1])) {
				for (int j = 0; j < t; j++) tmp += arr[i + 1];
				i++;
			}
			else if (arr[i + 1] == '(') {
				string ttmp, tmp2;
				int g = 1;
				for (int j = i + 2;; j++) {
					if (arr[j] == '(') g++;
					else if (arr[j] == ')') {
						g--;
						if (!g) break;
					}
					tmp2 += arr[j];
					i = j;
				}
				i++;
				ttmp = f(tmp2);
				for (int j = 0; j < t; j++) tmp += ttmp;
			}
		}
		else if (isRGB(arr[i])) {
			tmp += arr[i];
			if (arr[i + 1] == '(') {
				string ttmp, tmp2;
				int g = 1;
				for (int j = i + 2;; j++) {
					if (arr[j] == '(') g++;
					else if (arr[j] == ')') {
						g--;
						if (!g) break;
					}
					i = j;
					tmp2 += arr[j];
				}
				i++;
				ttmp = f(tmp2);
				tmp += ttmp[0];
				for (int j = 1; j < ttmp.size(); j++) {
					tmp += arr[i];
					tmp += ttmp[j];
				}
			}
		}
	}
	return tmp;
}
void solution(int numOfOrder, string* orderArr) {

	for (int i = 0; i < numOfOrder; i++) {
		cout << f(orderArr[i]) << "\n";
	}
}

struct input_data {
	int numOfOrder;
	string* orderArr;
};

void process_stdin(struct input_data& inputData) {
	string line;
	istringstream iss;

	getline(cin, line);
	iss.str(line);
	iss >> inputData.numOfOrder;

	inputData.orderArr = new string[inputData.numOfOrder];
	for (int i = 0; i < inputData.numOfOrder; i++) {
		getline(cin, line);
		iss.clear();
		iss.str(line);
		iss >> inputData.orderArr[i];
	}
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.numOfOrder, inputData.orderArr);
	return 0;
}