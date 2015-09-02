#include "Map.h"

//訪れたことのないdistanceの一番小さいノード(添え字)を返す
int min_node(int num, int *distance, bool *checher){
  int node=-1, i;
  int dist=INF;
  for (i=0; i<num; i++) {
    if (!checher[i] && dist > distance[i]) {
      dist = distance[i];
      node = i;
    }
  }
  return node;
}

//ダイクストラのアルゴリズム
//重み付き最短経路問題を解くおそらく最もメジャーなアルゴリズム
//注意 隣接行列に負の数が含まれている場合では上手くいかないことがある。
//正の数であればおそらく最も単純で高速なアルゴリズムである
//アルゴリズムの簡単な流れは
//今まで通ってきた道のりと比較して、自分のノードを間接的に通るのとそのまま突っ切るのではどちらが重みが小さいかを調べる
//間接的な方が小さいならそのノードまでの最短距離を更新する。
//そして、更新した最短経路のうち一番小さいノードを選ぶ
//これを次のノードとする。
//そのノードがゴールになるまでこれを繰り返す。
//訪れた場所を記録しないと無限にループしてしまうので
//訪れたノードにはチェックを入れ、チェックが入ってるノードは選ばないようにする必要が有る。
void dijkstra(int s, int num, int **array, int *distance, int *path)
{
  int i;
  bool* checher = (bool*)malloc(sizeof(bool)*num);
  for(i=0;i<num;i++){
    distance[i] = INF;
    checher[i] = 0;
    path[i] = 0;
  }
  int node = s;
  distance[node] = 0;
  path[node] = 0;
  
  while (1) {
    int i;
    for (i=0; i<num; i++) {
      if(!checher[i] && distance[i] > distance[node] + array[node][i]){
        distance[i] = distance[node] + array[node][i];
        path[i] = node;
      }
    }
    if((node = min_node(num, distance, checher)) == -1)
      return;
    checher[node] = 1;
  }
}


//ワーシャルフロイド
//これは単純な3重ループ
//どこかを経由する方が重みが小さいかを見て、小さければそれに更新する
//重みが負の時でも正しい最短距離を見つけることができる
//構造が単純であり、3重ループであるため重たいアルゴリズム
//巨大な隣接行列には向かない
//隣接行列そのものを最短距離行列に変えてしまうアルゴリズムなので経路を示す問題には不向きである
void warshallFloyd(int num, int **array)
{
  int i,j,k;
  for (i=0; i<num; i++) {
    for (j=0; j<num; j++) {
      for (k=0; k<num; k++) {
        if (array[i][j] > array[i][k] + array[k][j])
          array[i][j] = array[i][k] + array[k][j];
      }
    }
  }
}



