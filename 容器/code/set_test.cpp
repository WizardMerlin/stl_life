#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;



int main(void)
{
    int array[] = {1, 2, 3, 4, 5};
    set<int, greater<int>> s(array, array+5, greater<int>());

    copy(s.begin(), s.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
