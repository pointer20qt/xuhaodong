#include <iostream>
#include <cassert>
using namespace std;

int main() {
	int i = 22;
	assert(i != 22);
	system("pause");
	return 0;
}

/*¾²Ì¬¶ÏÑÔ
#include <iostream>
using namespace std;

int main() {
const int i = 22;
static_assert(i != 22, "i equals to 22");
system("pause");
return 0;
}
*/