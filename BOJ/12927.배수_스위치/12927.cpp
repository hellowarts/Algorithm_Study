#include<bits/stdc++.h>
std::string lights;

void switch_on_off(int start) {
    for(int i=start; i<=lights.size(); i+=start) {
        if(lights[i-1] == 'Y') lights[i-1] = 'N';
        else lights[i-1] = 'Y';
    }
}

int main(void) {
    std::cin >> lights;
    int count = 0;
    for(int i=1; i<=lights.size(); i++) {
        if(lights[i-1] == 'Y'){
            switch_on_off(i);
            ++count;
        }
    }
    std::cout << count;
}