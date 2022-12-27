#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 10000000
#define N 5

// graph[0].first = 정점 0에서 first로 감
// graph[0].second = 정점 0에서 first로 갈 때 드는 비용
vector<pair<int,int>> graph[N];
// 최단거리 배열

int d[N];

void dijkstra(int start)
{
  int dist = 0, now = 0, cost = 0;
  priority_queue<pair<int,int>> pq; // 거리, 정점 인덱스, 우선순위 큐는 기본이 내림차순에 유의할 것
  // 최대 힙은 루트에 최대값이 저장된다. 하지만 우리가 원하는건 최소값이 루트에 오는 것,
  // 최대 힙에서 이걸 어떻게 구현해야할까?

  pq.push({0, start}); // 시작 정점으로 가기 위한 최단 경로는 0으로 설정 (거리, 정점)
  d[start] = 0;

  while (!pq.empty()) {
    // do something
    // 최단거리, 최단거리 노드
    dist = -pq.top().first;
    now = -pq.top().second;
    pq.pop();

    if (d[now] < dist) // 이미 최단경로를 체크한 경우
      continue;

    for (int i = 0; i < graph[now].size(); i++) {
      // do something
      cost = dist + graph[now][i].second;
      if (cost < d[graph[now][i].first])
      {
          d[graph[now][i].first] = cost;
          pq.push({-cost, graph[now][i].first});
      }
    }
  }
}

int main(void)
{
  // 간선 정보 입력.
  // 아래 줄 내용: 정점 0에서 정점 0으로 갈 때 드는 비용은 0이다
  graph[0].push_back({0, 0});
  graph[0].push_back({1, 10});
  graph[0].push_back({2, 5});

  graph[1].push_back({1, 0});
  graph[1].push_back({2, 2});
  graph[1].push_back({3, 1});
  
  graph[2].push_back({1, 3});
  graph[2].push_back({2, 0});
  graph[2].push_back({3, 9});
  graph[2].push_back({4, 2});

  graph[3].push_back({3, 0});
  graph[3].push_back({4, 4});

  graph[4].push_back({0, 7});
  graph[4].push_back({3, 6});
  graph[4].push_back({4, 0});

  // 최단거리 배열을 모두 INF로 초기화
  fill(d, d + N, INF);

  dijkstra(0);

  for (int i = 0; i < N; i++)
    printf("d[%d]: %d\n", i, d[i]);
  
  return 0;
}

