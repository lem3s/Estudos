#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main(){
  int n=0;

  scanf("%d", &n);

  set <int>ordenada;

  for (int i=0; i < n; i++){
    int temp;
    scanf("%d", &temp);
    ordenada.insert(temp);
  }
  printf("%u\n", ordenada.size());
}
