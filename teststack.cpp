#include "problems.h"
using namespace std;



int main()
{

    cout<<reverseInt(-12890)<<endl;
    cout<<reverseInt(10987)<<endl;

    vector<vector<int>> help1 = {{1,0,0,1,0}, {0,1,0,1,0}, {0,0,1,1,0},{0,0,0,1,0},{0,1,0,1,0}};

    /*help1[1][0]=1;
    help1[2][0]=1;
    help1[13][0]=1;
    help1[4][0]=1;*/

    int help = findCelebrity(5,help1);
    cout<<help<<endl;


    towerOfHanoi(2);
    return 0;


}
    // Test your code!
