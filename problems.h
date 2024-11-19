#include "stack.h"
#include <vector>
using namespace std;

// Takes in an integer num and reverses it using a Stack data structure.
// reverseInt(6883) should return 3886
// reverseInt(0) should return 0
// reverseInt(-2938947) should return -7498392
int reverseInt(int num)
{
    // Your code here
    bool Is_Negative = 0;
    if(num<0){
        Is_Negative = 1;
        num = abs(num);
    }
    string st1 = to_string(num);

      Stack s1 = Stack(st1[0]);
   for(int i=1;i<st1.length();i++){
      s1.push(st1[i]);
   }
    string answer;
    while(!s1.isEmpty()){
        answer += s1.pop();
    }
    int a = stoi(answer);
     if(Is_Negative){
       a*=-1;
    }
    return a;

    

}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int>>& matrix)
{   
    // Your code here
    bool not_celebrity = 0;

    Stack<int> s2 = Stack(0);
    for(int i=1;i<n;i++){
        s2.push(i);
    }
    
    while(s2.top->down!=nullptr){
        int a = s2.pop();
        int b = s2.pop();
        if(matrix[a][b]==1){
            s2.push(b);
        }else{
            s2.push(a);
        }
    }

    int help=s2.peek();

    for(int i=0;i<n;i++){
        if(help==i){
            continue;
        }
        if(matrix[help][i]==1||matrix[i][help]!=1){
            not_celebrity = 1;
            break;
        }
    }

    if(not_celebrity){
        return -1;
    }else{
        return help;
    }

}


// Moves a disk from stack a to stack b if possible, otherwise
// moves disk from stack b to stack a.
vector<Stack<int>> towers;
void moveDisk(int a, int b)
{
    char emotionalsupport1;
    if(a==0) emotionalsupport1 = 'S';
    else if(a==1) emotionalsupport1 = 'A';
    else if(a==2) emotionalsupport1 = 'D';

    char emotionalsupport2;
    if(b==0) emotionalsupport2 = 'S';
    else if(b==1) emotionalsupport2 = 'A';
    else if(b==2) emotionalsupport2 = 'D';

    if(towers[a].isEmpty()&&towers[b].isEmpty()){
        return;
    }

   int help;
    if(towers[b].isEmpty()||towers[a].peek()<towers[b].peek()){
        help = towers[a].pop();
        towers[b].push(help);
        cout<<"move Disk" <<help<< " from "<< emotionalsupport1 << " to " << emotionalsupport2<<endl;
    }else if(towers[a].isEmpty()||towers[a].peek()>towers[b].peek()){
        help = towers[b].pop();
        towers[a].push(help);
        cout<<"move Disk" <<help<< "from " << emotionalsupport2 << " to " << emotionalsupport1<<endl;
    }// Your code here

}
 
// Simulates the tower of Hanoi puzzle for n disks and solves it 
// using the moveDisk() fuunction. No iteration allowed!
void towerOfHanoi(int n)
{
    int moved_to = 1;
    int current_stack =0;
    int next_stack = 1;

    Stack<int> help;

    for(int i=0;i<=3;i++){
        towers.push_back(help);
    }

    for(int i=n;i>=1;i--){
        towers[0].push(i);
    }

    if(n%2==0){
        //moveright
        while(!(towers[0].isEmpty()&&towers[1].isEmpty()&&!towers[2].isEmpty())){
            //movethetop of current stack, to the one stack at the right of it, if it is available.
            //if It is not available, check next stack
            //If both is not available, move the top of next stack
            current_stack %= 3;
            //cout<<towers[2].top->val<<endl;
            if(towers[current_stack].isEmpty()||current_stack==moved_to){
                current_stack++;
                continue;
            }

            if(towers[(current_stack+1)%3].isEmpty()||towers[(current_stack+1)%3].peek()>towers[current_stack].peek()){
                moveDisk(current_stack,(current_stack+1)%3);
                 moved_to =(current_stack+1)%3;
            }else if(towers[(current_stack+2)%3].isEmpty()||towers[(current_stack+2)%3].peek()>towers[current_stack].peek()){
                moveDisk(current_stack,(current_stack+2)%3);
                 moved_to =(current_stack+2)%3;
            }
            current_stack++;

        }
    }else{

        while(!(towers[0].isEmpty()&&towers[1].isEmpty()&&!towers[2].isEmpty())){

            if(current_stack==-1){
                current_stack=2;
            }

            if(towers[current_stack].isEmpty()||current_stack==moved_to){
                current_stack--;
                continue;
            }

            if(towers[(current_stack-1+3)%3].isEmpty()||towers[(current_stack-1+3)%3].peek()>towers[current_stack].peek()){
                moveDisk(current_stack,(current_stack-1+3)%3);
                moved_to = (current_stack-1+3)%3;
            }else if(towers[(current_stack-2+3)%3].isEmpty()||towers[(current_stack-2+3)%3].peek()>towers[current_stack].peek()){
                moveDisk(current_stack,(current_stack-2+3)%3);
                moved_to =(current_stack-2+3)%3;
            }

            current_stack--;
        }
        //moveleft
    }
    // Your code here
}