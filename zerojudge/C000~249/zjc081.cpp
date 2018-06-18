#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int brown[5], green[5], clear[5];
  int move[10];
  const string answer[10] = { "BCG", "BGC","CBG", "CGB","GBC", "GCB" };
  int min_index;
  while( scanf( "%d", &brown[0] ) != EOF ){
    scanf( "%d%d%d%d%d%d%d%d", &green[0], &clear[0]
                             , &brown[1], &green[1], &clear[1]
                             , &brown[2], &green[2], &clear[2] );
    move[0] = brown[1]+brown[2]+green[0]+green[1]+clear[0]+clear[2];
    move[1] = brown[1]+brown[2]+green[0]+green[2]+clear[0]+clear[1];
    move[2] = brown[0]+brown[2]+green[0]+green[1]+clear[1]+clear[2];
    move[3] = brown[0]+brown[1]+green[0]+green[2]+clear[1]+clear[2];
    move[4] = brown[0]+brown[2]+green[1]+green[2]+clear[0]+clear[1];
    move[5] = brown[0]+brown[1]+green[1]+green[2]+clear[0]+clear[2];

    min_index = 0;
    for( int i = 1 ; i < 6 ; i++ )
      if( move[i] < move[min_index] )
        min_index = i;
    printf( "%s %d\n", answer[min_index].c_str(), move[min_index] );

  }
}
