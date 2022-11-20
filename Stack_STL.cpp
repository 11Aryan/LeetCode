#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>s;
    s.push(2);
    s.push(35);
    cout<<"Top:"<<s.top()<<endl;
    s.pop();
    cout<<"After pop:"<<s.top()<<endl;
    cout<<"Size"<<s.size()<<endl;
    cout<<"Empty? "<<s.empty();
}
