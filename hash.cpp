#include<iostream>
#include<fstream>
#include<stdio.h>
#define P 94000079
#define cin infile
#define cout outfile
#define SEG 200
using namespace std;
bool isTh[99005];
char type[100005];
int numTag[100005];
long bts[100005][8];
int Vm[100005];
int is[100005];
int is2[100005]
int bitis[2010];
int segco=0;
int max3(int a,int b, int c)
{
  if(a>b && a>c)
  return a;
  else if(b<c)
  return c;
  else
  return b;
}

int g(int r1, int r2)
{
  //count=0;

  int cur=r1;
  while(int i=0; i<=r2-r1; i++)
  {
    int max=2000000000;
    for(int j=r1; j<=r2; j++)
    {

        if(is[j]) continue;
        if(max3(inter(i,j),numTag[i]-inter(i,j),numTag[j]-inter(i,j))<min)
        {
          cur=j;
          max=max3(inter(i,j),numTag[i]-inter(i,j),numTag[j]-inter(i,j));
        }
    }
    if(!Vm[cur])
    {
        is[cur]=1;
    }
    else
        is[cur]=is[Vm[cur]]=1;
    Sli[rco++]=cur;
    if(Vm[cur])
    {
        Sli[rco++]=Vm[cur];
    }
  }
  bitis[segco++]=rco-1;

}

int f(int foto, int yer)
{
   bts[foto][yer/64]|=1<<(yer%64);
}

int inter(int a, int b)
{
  long le;
  int son=0;
  for(int i=0; i<8; i++)
  {
    le=bts[a][i]&bts[b][i];
    for(j=0; j<64; j++)
    {
      son+=(   le & (1<<j)   ) != 0;
    }
  }
  return son;
}

int union(int a, int b)
{
  long le;
  int son=0;
  for(int i=0; i<8; i++)
  {
    le=bts[a][i]!bts[b][i];
    for(j=0; j<64; j++)
    {
      son+=(   le & (1<<j)   ) != 0;
    }
  }
  return son;
}

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
    int count=0;
    int vc=0;
    int cur[2];
    for(i=0; i<N; i++)
    {
        cin>>type[i]>>numTag[i];
        for(j=0; j<numTag[i]; j++)
        {
            cin>>input;
            if(isTh[hashm(input)]==0)
            {
              isTh[hashm(input)]=1;
              kaci[hashm(input)]=count++;
              f(j,count-1);
            }
            else
              {
                f(j,kaci[hashm(input)]);
              }
        }
        if(type[i]=='V')
        {
          cur[vc]=i;
          if(vc)
          {
            Vm[cur[0]]=cur[1];
            Vm[cur[1]]=cur[0];
            numTag[cur[0]]=numTag[cur[1]]=union(cur[0],cur[1]);
          }
          vc=(vc+1)%2;
        }
    }


    int cur=0;
    while(int i=0; i<SEG; i++)
    {
      int max=2000000000;
      for(int j=0; j<SEG; j++)
      {

          if(is2[j]) continue;
          if(max3(inter(i,j),numTag[i]-inter(i,j),numTag[j]-inter(i,j))<min)
          {
            cur=j;
            max=max3(inter(i,j),numTag[i]-inter(i,j),numTag[j]-inter(i,j));
          }

      }
      if(!Vm[cur])
      {
          is[cur]=1;
      }
      else
          is[cur]=is[Vm[cur]]=1;
      Sli[rco++]=cur;
      if(Vm[cur])
      {
          Sli[rco++]=Vm[cur];
      }
    }
    bitis[segco++]=rco-1;










    /*int count=0;
    for(i=0; i<=90000000; i++)
    {
      if(isTh[i])
        count++;
    }
    cout<<count;*/



    return 0;
}
