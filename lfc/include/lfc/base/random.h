#ifndef __LFC_RANDOM_H__
#define __LFC_RANDOM_H__

#include "lfc/base/type.h"
#include "lfc/stl/type_traits.h"
#include "lfc/base/system.h"
#include <assert.h>

#define BASE_RANDOM_START 0
#define BASE_RANDOM_END   1000

namespace lfc {


int     random_int();
int     random_int(int bound);
double  random_double();
double  random_double(double bound);
float   random_float();
float   random_float(float bound);

int __next_random_int(int seed);


template<typename T, typename Enable = void>
class Random{};

template<typename T>
class Random<T, typename enable_if<is_integral_v<T>>::type >{
public:
  Random(T start, T end) : m_start(start),m_index(0){
    m_bound = end - start;
    assert(m_bound > 0 );

    m_seed = (SYS_TIME + m_bound/2 ) % m_bound;
  }

  void set_seed(T seed){m_seed = seed;};
  T get_seed(){return m_seed;}

  int operator()(){
    return getNext();
  }

  int getNext() {
    int random_num_index = (int) m_seed + m_index++ + SYS_TIME % 2;
    int random_add = __next_random_int(random_num_index);
    m_seed = (13 * m_seed + (T) random_add) % m_bound;
    return m_start + m_seed;
  }

private:
  T m_start;
  T m_bound;
  T m_index;
  T m_seed;
};



template<>
class Random<double> {

public:

  Random(double start, double end) 
    : m_start(start)
    , m_end(end)
    , m_intR(BASE_RANDOM_START, BASE_RANDOM_END)
  {
    assert(start < end);

  }

  void set_seed(double seed){
    assert(seed >= m_start && seed <= m_end);
    m_intR.set_seed(((seed - m_start) / (m_end - m_start) * (BASE_RANDOM_END-BASE_RANDOM_START)));
  };

  double operator()(){
    return getNext();
  }

  double getNext() {
    double n = (double) m_intR.getNext();
    return (n / (BASE_RANDOM_END-BASE_RANDOM_START)) * (m_end - m_start) + m_start;
  }

private:
  
  double m_start;
  double m_end;

  Random<int> m_intR;
};


} // namespace lfc
#endif // __LFC_ABI_H__
