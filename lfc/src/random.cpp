#include "lfc/base/random.h"

namespace lfc {


const static int random_num[] = {
  03,47,43,73,86,36,96,47,36,61,46,99,69,81,62,
  97,74,24,67,62,42,81,14,57,20,42,53,32,37,32,
  16,76, 2,27,66,56,50,26,71, 7,32,90,79,78,53,
  12,56,85,99,26,96,96,68,27,31, 5, 3,72,93,15,
  55,59,56,35,64,38,54,82,46,22,31,62,43, 9,99,
  16,22,77,94,39,49,54,43,54,82,17,37,93,23,78,
  84,42,17,53,31,57,24,55, 6,88,77, 4,74,47,67,
  63, 1,63,78,59,16,95,55,67,19,98,10,50,71,75,
  33,21,12,34,29,78,64,56, 7,82,52,42, 7,44,28,
  57,60,86,32,44, 9,47,27,96,54,49,17,46, 9,62,
  18,18, 7,92,46,44,17,16,58, 9,79,83,86,19,62,
  26,62,38,97,75,84,16, 7,44,99,83,11,46,32,24,
  23,42,40,54,74,82,97,77,77,81, 7,45,32,14, 8,
  62,36,28,19,95,50,92,26,11,97, 0,56,76,31,38,
  37,85,94,35,12,83,39,50, 8,30,42,34, 7,96,88,
  70,29,17,12,13,40,33,20,38,26,13,89,51, 3,74,
  56,62,18,37,35,96,83,50,87,75,97,12,25,93,47,
  99,49,57,22,77,88,42,95,45,72,16,64,36,16, 0,
  16, 8,15, 4,72,33,27,14,34, 9,45,59,34,68,49,
  31,16,93,32,43,50,27,89,87,19,20,15,37, 0,49,
};

const static int random_num_len = sizeof(random_num) /  sizeof(int);


int __next_random_int(int seed){
  seed = (seed + random_num_len) %random_num_len;			
  return random_num[seed];
}

static Random<int> _G_Random(BASE_RANDOM_START, BASE_RANDOM_END);

int random_int() {
  return _G_Random.getNext();
}

int random_int(int bound) {

  if(bound == BASE_RANDOM_END)
    return random_int();

  if(bound < BASE_RANDOM_END)
    return random_int() % bound;
 
  return (int) random_double((double) bound);
}

double random_double() {
  return (double) random_int();
}

double random_double(double bound) {
  return (random_double() / (BASE_RANDOM_END-BASE_RANDOM_START)) * bound;
}

float random_float() {
  return (float) random_int();
}

float random_float(float bound) {
  return (random_float() / (BASE_RANDOM_END-BASE_RANDOM_START)) * bound;
}


} // namespace lfc