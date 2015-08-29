#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//DFS
bool toReachTheGoal(int width, int height, int x, int y, int gx, int gy, int** map);

//BFS
int shortestPathDistance(int width, int height, int x, int y, int gx, int gy, int** map);

//DFS_Recursion
bool toReachTheGoal_Recursion(int width, int height, int x, int y, int gx, int gy, int** map);

/*
* exercises
*/
//スタックの問題
//文字列を与えてその中のカッコの対応がしっかりできているかどうかを判定するプログラムを作ろう
//bool check(char *str);
//str = "hogehoge(hoge)hoge(h(oge))" => true
//str = "hogehoge(hoge)hoge(h(oge)" => false
//ヒント1 : '('があったらスタックに積む
//ヒント2 : ')'があったらスタックから取り出す
//ヒント3 : 文字を最後まで見た時にスタックが空ならtrue/そうじゃなきゃfalse

//DFSの問題
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0030&lang=jp

//BFSの問題
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0121



