/**
  * KMP string search algo
  * ref at https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
*/

vector<int> kmp_table(string& w) {
	int len = w.length();
	vector<int> T(len);
	T[0] = -1;
	int cnt = 0;
	for (int i = 1; i < len; ++i) {
		if (w[i] == w[cnt]) {
			T[i] = T[cnt];
		} else {
			T[i] = cnt;
			while (cnt>=0 && w[i]!=w[cnt]) {
				cnt = T[cnt];
			}
		}
		++cnt;
	}
	return T;
}

int kmp_search(string& s, string& w) {
	vector<int> T = kmp_table(w);
	int p = -1;
	int j = 0, k = 0;
	while (j < s.length()) {
		if (s[j] == w[k]) {
			++j; ++k;
			if (k == w.length()) {
				p = j - k;
				break;
			}
		} else {
			k = T[k];
			if (k<0) {
				++j; ++k;
			}
		}
	}
	return p;
}
