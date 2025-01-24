#include<bits/stdc++.h>
static int T;

int is_Palindrome(std::string str, int left, int right, bool deleted){
	while(left < right) {
		if(str[left] != str[right]) {
            // 전에 문자를 삭제한 적이 없다면 1번의 기회 부여
			if(!deleted) {
				if(!is_Palindrome(str, left+1, right, true) || !is_Palindrome(str, left, right-1, true))
					return 1;
				return 2;
			}
			else return 2;
		}
		left++;
		right--;
	}
	return 0;
}

int main(void) {
    std::cin >> T;
    for(int i=0; i<T; i++) {
        std::string str;
        std::cin >> str;

        int left = 0;
        int right = str.size()-1;
        int answer = is_Palindrome(str, left, right, false);

        std::cout << answer << '\n';
    }

    return 0;
}