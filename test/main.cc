#include <iostream>
#include "../include/KMP.hpp"

using namespace std;
using namespace ns_KMP;  

int main(void)
{
    KMP* test_kmp = new KMP("abcabc");

    // test_kmp->print_dp();

    cout << "search result:" << test_kmp->search("-!@##$--abc^abcabc") << endl;

    cout << "search result:" << test_kmp->search("-!@##$--a1bcab1cab1c") << endl;

    return 0;
}
