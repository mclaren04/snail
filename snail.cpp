#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

enum direction { right, down, left, up };

vector<int> snail(const vector<vector<int>> &snail_map)
{
  if (snail_map.size() == 1 && snail_map[0].empty()) {
    return {};
  }
  direction dir = right;
  int cur[] = { 0, 0 };
  int n = snail_map.size();
  int lim = n - 1;
  vector<int> res;
  res.reserve(n * n);
  for (int i = 0; i < n * n - 1; i++) {
    for (int j = 0; j < lim; j++) {
      res.push_back(snail_map[cur[0]][cur[1]]);
      switch (dir) {
        case right: cur[1]++; break;
        case down:  cur[0]++; break;
        case left:  cur[1]--; break;
        case up:    cur[0]--;
      }
    }
    dir = direction((dir + 1) % 4);
    if ((dir == down && lim != n - 1) || dir == up) {
      lim--;
    }
  }
  res.push_back(snail_map[cur[0]][cur[1]]);
  return res;
}

int main()
{
  vector<vector<int>> snail_map {
    { 1 , 2 , 3 , 4 , 5 , 6 , 7},
    { 24, 25, 26, 27, 28, 29, 8},
    { 23, 40, 41, 42, 43, 30, 9},
    { 22, 39, 48, 49, 44, 31, 10},
    { 21, 38, 47, 46, 45, 32, 11},
    { 20, 37, 36, 35, 34, 33, 12},
    { 19, 18, 17, 16, 15, 14, 13},
  };
  vector<int> res = snail(snail_map);
  if (res.empty()) {
    cout << "Empty" << endl;
  } else {
    for (auto it = res.begin(); it != res.end(); it++)
      cout << *it << " ";
    cout << endl;
  }
  return 0;
}
