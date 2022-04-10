#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <sdouble.hpp>

const int L = 64;
const int N = L * L;
std::vector<int> spin(N), newspin(N);
std::vector<std::array<int, 4>> neighbor(N);
std::vector<int> parent(N);
std::mt19937 mt;

int find(int i) {
  while (i != parent[i]) {
    i = parent[i];
  }
  parent[i] = i;
  return i;
}

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  parent[j] = i;
}

int pos2index(int ix, int iy) {
  ix = (ix + L) % L;
  iy = (iy + L) % L;
  return ix + iy * L;
}

void init_neighbors() {
  for (int iy = 0; iy < L; iy++) {
    for (int ix = 0; ix < L; ix++) {
      int i = pos2index(ix, iy);
      neighbor[i][0] = pos2index(ix + 1, iy);
      neighbor[i][1] = pos2index(ix, iy + 1);
      neighbor[i][2] = pos2index(ix - 1, iy);
      neighbor[i][3] = pos2index(ix, iy - 1);
    }
  }
}

void connect(int i, int j, double p) {
  std::uniform_real_distribution<> ud(0.0, 1.0);
  if (spin[i] != spin[j]) return;
  if (ud(mt) > p) return;
  unite(i, j);
}

double magnetization(void) {
  double m = std::accumulate(spin.begin(), spin.end(), 0.0);
  m /= static_cast<double>(N);
  return m * m;
}

void magnetization_ie(double &m2, double &m4, double &u) {
  std::vector<int> nc(N, 0);
  for (int i = 0; i < N; i++) {
    nc[find(i)]++;
  }
  m2 = 0.0;
  m4 = 0.0;
  for (int i = 0; i < N; i++) {
    double nc2_i = nc[i] * nc[i];
    m2 += nc2_i;
    m4 += nc2_i * nc2_i;
    for (int j = i + 1; j < N; j++) {
      double nc2_j = nc[j] * nc[j];
      m4 += 6 * nc2_i * nc2_j;
    }
  }
  double n = static_cast<double>(N);
  m2 /= n * n;
  m4 /= n * n * n * n;
  u = m4 / m2 / m2;
}

void mc_step(double beta) {
  std::uniform_int_distribution<> ud(0, 1);
  for (int i = 0; i < N; i++) {
    parent[i] = i;
    newspin[i] = ud(mt) * 2 - 1;
  }
  const double p = 1.0 - exp(-2.0 * beta);
  for (int i = 0; i < N; i++) {
    connect(i, neighbor[i][0], p);
    connect(i, neighbor[i][1], p);
  }
  for (int i = 0; i < N; i++) {
    spin[i] = newspin[find(i)];
  }
}

void mc(double t) {
  const double beta = 1.0 / t;
  const int ThermalizeLoop = 100;
  const int ObserveLoop = 100;
  std::fill(spin.begin(), spin.end(), 1);
  for (int i = 0; i < ThermalizeLoop; i++) {
    mc_step(beta);
  }
  stat::sdouble sm2;
  stat::sdouble sm4;
  stat::sdouble sm2_ie;
  stat::sdouble sm4_ie;
  stat::sdouble sU_ie;
  for (int i = 0; i < ObserveLoop; i++) {
    mc_step(beta);
    double m2 = magnetization();
    sm2 << m2;
    sm4 << m2 * m2;
    double m2_ie, m4_ie, U_ie;
    magnetization_ie(m2_ie, m4_ie, U_ie);
    sm2_ie << m2_ie;
    sm4_ie << m4_ie;
    sU_ie << U_ie;
  }
  std::cout << t << " ";
  std::cout << sm2 << " ";
  std::cout << sm2_ie << " ";
  std::cout << sm4 << " ";
  std::cout << sm4_ie << " ";
  std::cout << sm4 / sm2 / sm2 << " ";
  std::cout << sU_ie << " ";
  std::cout << std::endl;
}

int main(void) {
  init_neighbors();
  double ts = 0.1;
  double te = 4.0;
  const int ObservePoints = 10;
  for (int i = 0; i <= ObservePoints; i++) {
    double t = ts + (te - ts) * i / ObservePoints;
    mc(t);
  }
}