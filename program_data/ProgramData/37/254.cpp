/*
 * ????????????????.cpp
 * ?????t??????????????26???????
 *      ???????????????????????????????no
 * ????: 2010-11-20
 * ??: ??
 */



int main() {
	//??????????????????????????????????
	int t, i, j;
	cin >> t;
	for (i = 0; i < t; i++) {
		char str[100000];
		cin >> str;

		//???????
		int length = strlen(str);
		//times[0]????a??????initial[0]????a???????????
		int times[26];
		memset(times, 0, sizeof(times)); //??????????

		for (j = 0; j < length; j++) {
			//??????????
			times[str[j] - 'a']++;
		}

		//??str????????????1???????????
		for (j = 0; j < length; j++) {
			if (times[str[j] - 'a'] == 1) {
				cout << str[j] << endl;
				break;
			}
		}

		//????????"no"
		if (j == length)
			cout << "no" << endl;
	}
	return 0; //????
}
