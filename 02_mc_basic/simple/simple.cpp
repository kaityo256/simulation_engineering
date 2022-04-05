#include "sdouble.hpp"
#include <iostream>
#include <random>
#include <vector>

const int L = 10;
const int V = L * L;
const int SAMPLE = 100;
const int AVE = 50;

void mc(const double beta, std::mt19937 &mt) {
  std::uniform_int_distribution<> ud(0, V - 1);
  std::vector<double> vu;
  const double w = exp(beta);
  for (int i = 0; i < SAMPLE; i++) {
    double usum = 0.0;
    double wsum = 0.0;
    for (int j = 0; j < AVE; j++) {
      const int p1 = ud(mt);
      const int p2 = ud(mt);
      if (p1 == p2) continue;
      const int x1 = p1 % L;
      const int y1 = p1 / L;
      const int x2 = p2 % L;
      const int y2 = p2 / L;
      int dx = x1 - x2;
      int dy = y1 - y2;
      if (dx > L / 2) dx -= L;
      if (dx < -L / 2) dx += L;
      if (dy > L / 2) dy -= L;
      if (dy < -L / 2) dy += L;

      double ui = 0.0;
      double wi = 1.0;
      if (dx == 0 && std::abs(dy) == 1) {
        ui = -w;
        wi = w;
      } else if (dy == 0 && std::abs(dx) == 1) {
        ui = -w;
        wi = w;
      }
      usum += ui;
      wsum += wi;
    }
    vu.push_back(usum / wsum);
  }
  stat::sdouble su(vu);
  std::cout << beta << " " << su << std::endl;
}

void domc() {
  std::mt19937 mt;
  double b_start = 0.0;
  double b_end = 10.0;
  const int nd = 10;
  for (int i = 0; i < nd; i++) {
    double beta = (b_end - b_start) * i / nd + b_start;
    mc(beta, mt);
  }
}

int main() {
  domc();
}
