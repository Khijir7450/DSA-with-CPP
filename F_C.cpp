#include<iostream>
using namespace std;
int main()
{
    int f;
    int c;
    cout<<"Enter the tempareture in Farenhite scale" <<endl;
    cin>>f;
    //c=(5/9)*(f-32);
    //c=(5.0/9)*(f-32);
    //c=(5/9.0)*(f-32);
    c=(5.0/9.0)*(f-32);
    cout<< c <<endl;
}
/*#include <iostream>
using namespace std;

int main() {
	int i = 10;
	char c = 'a';//ASCII VALUE OF a is 97

	int o = i + c;//c==97(a=97)
	char d = i + c;//d=107,is a integer but store in cher so output is an cher,(107==k)
	cout << o << endl;
	cout << d << endl;
}*/
