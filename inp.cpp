#include<iostream>
#include<fstream>
#include<stdio.h>
#define P 94000079
#define cin infile
#define cout outfile
using namespace std;
bool isTh[P+5];
char type[100005];
int numTag[100005];

int hashm(string str)
{
  int len=str.length();
  int pow=1;
  int son=0;
  for(int i=0; i<len; i++)
  {
    son+= str[i]>80 ? (str[i]-97)*pow : (str[i]-22)*pow;
    pow*=37;
  }
  return son;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        return 1;
    }

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    int N,i,j;
    string input;

    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>type[i]>>numTag[i];
        for(j=0; j<numTag[i]; j++)
        {
            cin>>input;
            isTh[hashm(input)]=1;
        }
    }
    int count=0;
    for(i=0; i<=90000000; i++)
    {
      if(isTh[i])
        count++;
    }
    cout<<count;



    return 0;
}
