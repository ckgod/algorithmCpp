#pragma once
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <complex>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long

template <typename T>
int binary_len(T n) {
	ll power_of_2 = 1;
	int ret = 0;
	while (power_of_2 <= n) power_of_2 <<= 1, ++ret;
	return ret;
}

template <typename T>
T bit_reverse(T n) {
	T ret = 0;
	while (n) {
		ret <<= 1;
		ret |= n & 1;
		n >>= 1;
	}
	return ret;
}

template <typename T>
T power_of_2_ge_than(T n) {
	T ret = 1;
	while (n > ret) ret <<= 1;
	return ret;
}

typedef complex<double> base;

void fft(vector<base>& a, bool inv) {
	int n = (int)a.size();
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		while (!((j ^= bit) & bit)) bit >>= 1;
		if (i < j) swap(a[i], a[j]);
	}
	for (int i = 1; i < n; i <<= 1) {
		double x = (inv ? 1 : -1) * M_PI / i;
		base w = { cos(x), sin(x) };
		for (int j = 0; j < n; j += i << 1) {
			base th(1);
			for (int k = 0; k < i; k++) {
				base tmp = a[i + j + k] * th;
				a[i + j + k] = a[j + k] - tmp;
				a[j + k] += tmp;
				th *= w;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; i++) a[i] /= n;
	}
}

vector<int> multiply(vector<int>& A, vector<int>& B) {
	vector<base> a(A.begin(), A.end());
	vector<base> b(B.begin(), B.end());
	int n = power_of_2_ge_than(max(a.size(), b.size())) * 2;

	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);

	for (int i = 0; i < n; i++) {
		a[i] *= b[i];
	}
	fft(a, true);

	vector<int> ret(n);
	for (int i = 0; i < n; i++) {
		ret[i] = (int)round(a[i].real());
	}
	return ret;
}

vector<int> n1, n2;
vector<int> ans;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;
	for (int i = 0; i < str1.length(); i++) {
		n1.push_back(str1[i] - 48);
	}
	for (int i = 0; i < str2.length(); i++) {
		n2.push_back(str2[i] - 48);
	}
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	ans = multiply(n1, n2);
	int idx = 0;
	while (idx < ans.size()) {
		if (ans[idx] >= 10) {
			if (idx == ans.size() - 1) {
				ans.push_back(ans[idx] / 10);
			}
			else {
				ans[idx + 1] += ans[idx] / 10;
			}
			ans[idx] %= 10;
		}
		++idx;
	}
	reverse(ans.begin(), ans.end());
	bool start = false;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != 0) start = true;
		if (start) cout << ans[i];
	}
	if (!start) cout << '0';

	return 0;
}