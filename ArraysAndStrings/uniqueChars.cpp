#include <stdlib.h>
#include <iostream>

using namespace std;

bool uniqueChars_UsingBits(char *str) {
	int len = strlen(str);
	int hashTbl = 0;
	char c = 0;

	for (int i = 0; i < len; i++) {
		c = str[i];
		// check if char already exists in the hash
		if ((hashTbl >> c) & 1) {
			return false;
		}

		hashTbl |= (1 << c);
	}
	return true;
}

bool uniqueChars_NoExtraDataStructure(char *str) {
	int len = strlen(str);

	if (len <= 1 ) {
		return true;
	} 

	for (int x = 0; x < len; x++) {
		for (int y = x + 1; y < len; y++) {
			if (str[x] == str[y]) {
				return false;
			}
		}
	}
	return true;
}

int main (int argc, char **argv) {
	cout << "Number of argc: " << argc << endl;
	for (int i = 0; i < argc; i++) {
		cout << "#: " << i << " : " << argv[i] << endl;
	}

	if (argc > 1) {
		bool isUniqueV1 = uniqueChars_UsingBits(argv[1]);
		bool isUniqueV2 = uniqueChars_NoExtraDataStructure(argv[1]);
		cout << argv[1] << ":" << isUniqueV1 << " : " << isUniqueV2 << endl;
	}

	return 0;
}
