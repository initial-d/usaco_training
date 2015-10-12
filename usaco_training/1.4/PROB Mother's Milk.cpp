/*
ID: duyimin1
PROG: milk3
LANG: C++
*/
//bfs
#include<iostream>
#include<string>
#include<queue>
#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;
struct milk{
  int a;
  int b;
  int c;
}foo1,foo;
bool vis[21][21];
queue<milk> q;

void bfs(){
  milk foo2,foo3 ;
  while(!q.empty()){
	foo2 = q.front();
	foo3 = foo2;
	q.pop();
	vis[foo2.a][foo2.b] = true;
	
	if(foo.b - foo2.b > 0){
	  if(foo.b - foo2.b >= foo2.a){
		foo2.b += foo2.a;
		foo2.a = 0;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	  else{
		foo2.a -= (foo.b - foo2.b);
		foo2.b = foo.b;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	}
	foo2 = foo3;
	if(foo.a - foo2.a > 0){
	  if(foo.a - foo2.a >= foo2.b){
		foo2.a += foo2.b;
		foo2.b = 0;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	  else{
		foo2.b -= (foo.a - foo2.a);
		foo2.a = foo.a;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	}
	foo2 = foo3;
	if(foo.a - foo2.a > 0){
	  if(foo.a - foo2.a >= foo2.c){
		foo2.a += foo2.c;
		foo2.c = 0;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	  else{
		foo2.c -= (foo.a - foo2.a);
		foo2.a = foo.a;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	}
	foo2 = foo3;
	if(foo.c - foo2.c > 0){
	  if(foo.c - foo2.c >= foo2.a){
		foo2.c += foo2.a;
		foo2.a = 0;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	  else{
		foo2.a -= (foo.c - foo2.c);
		foo2.c = foo.c;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	}
	foo2 = foo3;
	if(foo.b - foo2.b > 0){
	  if(foo.b - foo2.b >= foo2.c){
		foo2.b += foo2.c;
		foo2.c = 0;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	  else{
		foo2.c -= (foo.b - foo2.b);
		foo2.b = foo.b;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	}
	foo2 = foo3;
	if(foo.c - foo2.c > 0){
	  if(foo.c - foo2.c >= foo2.b){
		foo2.c += foo2.b;
		foo2.b = 0;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	  else{
		foo2.b -= (foo.c - foo2.c);
		foo2.c = foo.c;
		if(!vis[foo2.a][foo2.b])
		  q.push(foo2);
	  }
	}
  }
}
int main()
{
  ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");
  fin>>foo.a>>foo.b>>foo.c;
  foo1.a = 0;
  foo1.b = 0;
  foo1.c  = foo.c;
  memset(vis , false , sizeof(vis));
  q.push(foo1);
  bfs();
  int ans[21];
  int t = 0;
  for(int i = 0; i < 21; i++){
	if(vis[0][i])
	  ans[t++] = foo.c - i;
  }
  sort(ans , ans + t);
  fout<<ans[0];
  for(int i = 1;  i < t; i++)
	fout<<" "<<ans[i];
  fout<<endl;
  return 0;
}
