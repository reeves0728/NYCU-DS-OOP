#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
stack<int> st;
int size = pushed.size(), j = 0;
for (int i = 0; i < size; ++i) {
st.push(pushed[i]);
while (!st.empty() && st.top() == popped[j]) {
++j;
st.pop();
}
}
return st.empty();
}

int main() {
int n;
while (cin >> n) {
vector<int> pushed(n);
vector<int> popped(n);
for (int i = 0; i < n; i++) {
cin >> pushed[i];
}
for (int i = 0; i < n; i++) {
cin >> popped[i];
}
if (validateStackSequences(pushed, popped)) {
cout << "true" << endl;
} else {
cout << "false" << endl;
}
}
return 0;
}




