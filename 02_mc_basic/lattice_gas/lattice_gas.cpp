#include "sdouble.hpp"
#include <array>
#include <cmath>
#include <cstdio>
#include <random>
#include <vector>

int LX, LY;        // System Size
int V;             // Number of sites
double e_table[5]; // Energy Table
enum { LEFT,
       RIGHT,
       UP,
       DOWN };

const int SAMPLE = 100;
const int AVE = 50;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

std::vector<int> lattice, gas;
std::vector<std::array<int, 4>> neighbor;

int pos2index(int ix, int iy) {
  ix = (ix + LX) % LX;
  iy = (iy + LY) % LY;
  return ix + iy * LX;
}

void index2pos(int index, int &ix, int &iy) {
  ix = index % LX;
  iy = index / LX;
}

void init(int size_x, int size_y, int number_of_particles) {
  LX = size_x;
  LY = size_y;
  V = LX * LY;
  gas.resize(number_of_particles);
  lattice.resize(V, 0);
  neighbor.resize(V);
  for (int i = 0; i < V; i++) {
    int ix = i % LX;
    int iy = i / LX;
    neighbor[i][LEFT] = pos2index(ix - 1, iy);
    neighbor[i][RIGHT] = pos2index(ix + 1, iy);
    neighbor[i][DOWN] = pos2index(ix, iy - 1);
    neighbor[i][UP] = pos2index(ix, iy + 1);
  }
  for (int i = 0; i < number_of_particles; i++) {
    lattice[i] = 1;
    gas[i] = i;
  }
}

void move_particle(std::mt19937 &mt) {
  const int N = gas.size();
  std::uniform_int_distribution<> uid(0, N - 1);
  std::uniform_int_distribution<> udir(0, 3);
  std::uniform_real_distribution<> ud(0.0, 1.0);

  int i1 = uid(mt);   // Particle to move
  int dir = udir(mt); // Direction to move
  int p1 = gas[i1];
  int n1 = 0;
  n1 += lattice[neighbor[p1][RIGHT]];
  n1 += lattice[neighbor[p1][LEFT]];
  n1 += lattice[neighbor[p1][UP]];
  n1 += lattice[neighbor[p1][DOWN]];
  int x1, y1;
  index2pos(p1, x1, y1);
  int x2 = x1 + dx[dir];
  int y2 = y1 + dy[dir];
  int p2 = pos2index(x2, y2);
  if (lattice[p2] != 0) return;
  int n2 = -1;
  n2 += lattice[neighbor[p2][RIGHT]];
  n2 += lattice[neighbor[p2][LEFT]];
  n2 += lattice[neighbor[p2][UP]];
  n2 += lattice[neighbor[p2][DOWN]];
  int nd = n1 - n2;
  if (nd < 0 || e_table[nd] > ud(mt)) {
    // accept
    lattice[p1] = 0;
    lattice[p2] = 1;
    gas[i1] = p2;
  }
}

void show_lattice() {
  for (int i = 0; i < LX; i++) {
    for (int j = 0; j < LY; j++) {
      if (lattice[i + j * LX] == 1) {
        printf("*");
      } else {
        printf("-");
      }
    }
    printf("\n");
  }
}

double calc_energy() {
  double e = 0;
  for (int i = 0; i < V; i++) {
    if (lattice[i] == 0) continue;
    e += lattice[neighbor[i][RIGHT]];
    e += lattice[neighbor[i][DOWN]];
  }
  return -e;
}

void make_table(double beta) {
  for (int i = 0; i < 5; i++) {
    e_table[i] = exp(-i * beta);
  }
}

void mc(double beta) {
  make_table(beta);
  std::mt19937 mt;
  std::vector<double> ve;
  for (int i = 0; i < SAMPLE; i++) {
    move_particle(mt);
  }

  for (int i = 0; i < SAMPLE; i++) {
    double usum = 0.0;
    for (int j = 0; j < AVE; j++) {
      move_particle(mt);
      usum += calc_energy();
    }
    usum /= static_cast<double>(AVE);
    ve.push_back(usum);
  }
  stat::sdouble se(ve);
  std::cout << beta << " " << se << std::endl;
}

void domc(int lx, int ly, int n) {
  double b_start = 0.0;
  double b_end = 10.0;
  const int nd = 10;
  init(lx, ly, n);
  for (int i = 0; i < nd; i++) {
    double beta = (b_end - b_start) * i / nd + b_start;
    mc(beta);
  }
}

void test() {
  init(5, 10, 25);
  show_lattice();
  std::mt19937 mt;
  make_table(10.0);
  for (int i = 0; i < 100; i++) {
    move_particle(mt);
  }
  show_lattice();
}

int main() {
  domc(10, 10, 2);
  // test2();
}
