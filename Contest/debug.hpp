#pragma once
#include <bits/stdc++.h>

#define COLORS

template<typename T>
struct has_const_iterator {
  template<typename C> static int8_t test(typename C::const_iterator*);
  template<typename C> static int16_t test(...);
  enum { value = sizeof(test<T>(0)) == sizeof(int8_t) };
};
template<typename T>
struct is_pair {
  template<typename C> static int8_t test(typename C::first_type*);
  template<typename C> static int16_t test(...);
  enum { value = sizeof(test<T>(0)) == sizeof(int8_t) };
};
template<typename T>
struct is_map {
  template<typename C> static int8_t test1(typename C::key_type*);
  template<typename C> static int8_t test2(typename C::value_type::first_type*);
  template<typename C> static int16_t test1(...);
  template<typename C> static int16_t test2(...);
  enum { value = (sizeof(test1<T>(0)) == sizeof(int8_t) and sizeof(test2<T>(0)) == sizeof(int8_t)) };
};
template<typename T>
struct is_str {
  template<typename C> static int8_t test(typename C::_Char_alloc_type*);
  template<typename C> static int16_t test(...);

  enum { value = sizeof(test<T>(0)) == sizeof(int8_t) };
};

namespace colors {
#ifdef COLORS
  std::string RESET = "\033[0m";
  std::string BLACK = "\033[30m";
  std::string RED = "\033[31m";
  std::string GREEN = "\033[32m";
  std::string YELLOW = "\033[33m";
  std::string BLUE = "\033[34m";
  std::string IBLUE = "\033[44m";
  std::string MAGENTA = "\033[35m";
  std::string CYAN = "\033[36m";
  std::string WHITE = "\033[39m";

  std::string CURS = "\033[3m";
  std::string BGREEN = "\033[102m";
#else
  const std::string RESET = "";
  const std::string BLACK = "";
  const std::string RED = "";
  const std::string GREEN = "";
  const std::string YELLOW = "";
  const std::string BLUE = "";
  const std::string IBLUE = "";
  const std::string MAGENTA = "";
  const std::string CYAN = "";
  const std::string WHITE = "";

  const std::string CURS = "";
  const std::string BGREEN = "";
#endif
};
using namespace colors;

struct dbstream {

  std::string BRCOLOR = GREEN;
  std::string MCOLOR = WHITE;
  std::string KEYCOLOR = BLUE;


  int depth = 0;
  std::ostream& os;
  std::string CUR;

  template<typename T>
  typename std::enable_if <!is_pair<T>::value && !has_const_iterator<T>::value, void>::type dbprint(const T& t) {
    os << t;
  }

  template<typename T>
  typename std::enable_if<is_pair<T>::value, void>::type dbprint(const T& p) {
    os << BRCOLOR + "{" + CUR;
    dbprint(p.first);
    os << " ";
    dbprint(p.second);
    os << BRCOLOR + "}" + CUR;
  }

  void dbprint(const std::string& p) {
    os << BRCOLOR + "'" + CUR << p << BRCOLOR + "'" + CUR;
  }

  template <typename T>
  typename std::enable_if<
    !is_map<T>::value&&
    has_const_iterator<T>::value&&
    std::is_fundamental<typename T::value_type>::value
    , void>::type dbprint(const T& c) {

    os << BRCOLOR + "[" + CUR;
    int pos = 0;
    for (auto& i : c) {
      if (pos) os << " ";
      #ifdef IDS
      os << KEYCOLOR << pos << CUR + ":";
      #endif
      os << i;
      ++pos;
    }
    os << BRCOLOR + "]" + CUR;
  }

  template <typename T>
  typename std::enable_if<
    has_const_iterator<T>::value &&
    !is_map<T>::value &&
    !is_str<T>::value &&
    !std::is_fundamental<typename T::value_type>::value
    , void>::type
    dbprint(const T& c) {
    ++depth;

    os << BRCOLOR + "[" + CUR;
    int pos = 0;
    for (auto& i : c) {
      os << "\n" << std::string(depth * 2, ' ') + CURS + KEYCOLOR;
      auto t = CUR;
      CUR = CURS + KEYCOLOR;

      os << std::to_string(pos) + ": " + RESET + MCOLOR;
      CUR = t;
      dbprint(i);
      ++pos;
    }
    --depth;
    os << "\n" << std::string(depth * 2, ' ') << BRCOLOR + "]" + CUR;
  }

  template <typename T>
  typename std::enable_if<is_map<T>::value, void>::type dbprint(const T& c) {
    ++depth;

    os << BRCOLOR + "[" + CUR;
    int pos = 0;
    for (auto& i : c) {
      os << "\n" << std::string(depth * 2, ' ') + CURS + KEYCOLOR;
      auto t = CUR;
      CUR = CURS + KEYCOLOR;
      dbprint(i.first);
      os << ": " + RESET + MCOLOR;
      CUR = t;

      dbprint(i.second);
      ++pos;
    }
    --depth;
    os << "\n" << std::string(depth * 2, ' ') << BRCOLOR + "]" + CUR;
  }
  template<typename T>
  void print(const T& t) {
    os << MCOLOR;
    CUR = MCOLOR;
    dbprint(t);
    os << RESET;
    CUR = RESET;
  }
  void printName(const std::string& s) {
    os << KEYCOLOR << s << BRCOLOR << "=" << RESET;
  }
  dbstream(std::ostream& new_os) : os(new_os) {}
};
template<typename T>
dbstream& operator << (dbstream& dbs, const T& t) {
  dbs.print(t);
  dbs.os << "\n";
  return dbs;
}

#pragma region
#define FIRST(a, ...) a
#define SECOND(a, b, ...) b

#define EMPTY()

#define EVAL(...) EVAL1024(__VA_ARGS__)
#define EVAL1024(...) EVAL512(EVAL512(__VA_ARGS__))
#define EVAL512(...) EVAL256(EVAL256(__VA_ARGS__))
#define EVAL256(...) EVAL128(EVAL128(__VA_ARGS__))
#define EVAL128(...) EVAL64(EVAL64(__VA_ARGS__))
#define EVAL64(...) EVAL32(EVAL32(__VA_ARGS__))
#define EVAL32(...) EVAL16(EVAL16(__VA_ARGS__))
#define EVAL16(...) EVAL8(EVAL8(__VA_ARGS__))
#define EVAL8(...) EVAL4(EVAL4(__VA_ARGS__))
#define EVAL4(...) EVAL2(EVAL2(__VA_ARGS__))
#define EVAL2(...) EVAL1(EVAL1(__VA_ARGS__))
#define EVAL1(...) __VA_ARGS__

#define DEFER1(m) m EMPTY()
#define DEFER2(m) m EMPTY EMPTY()()
#define DEFER3(m) m EMPTY EMPTY EMPTY()()()
#define DEFER4(m) m EMPTY EMPTY EMPTY EMPTY()()()()

#define IS_PROBE(...) SECOND(__VA_ARGS__, 0)
#define PROBE() ~, 1

#define CAT(a,b) a ## b

#define NOT(x) IS_PROBE(CAT(_NOT_, x))
#define _NOT_0 PROBE()

#define BOOL(x) NOT(NOT(x))

#define IF_ELSE(condition) _IF_ELSE(BOOL(condition))
#define _IF_ELSE(condition) CAT(_IF_, condition)

#define _IF_1(...) __VA_ARGS__ _IF_1_ELSE
#define _IF_0(...)             _IF_0_ELSE

#define _IF_1_ELSE(...)
#define _IF_0_ELSE(...) __VA_ARGS__

#define HAS_ARGS(...) BOOL(FIRST(_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _END_OF_ARGUMENTS_() 0

#define MAP(m, first, ...)           \
  m(first)                           \
  IF_ELSE(HAS_ARGS(__VA_ARGS__))(    \
    DEFER2(_MAP)()(m, __VA_ARGS__)   \
  )(                                 \
    /* Do nothing, just terminate */ \
  )
#define _MAP() MAP
#pragma endregion

#undef gg

#define _deb(x) dd.printName(#x);dd.print(x);dd.os<<" ";
#define gg(...) {EVAL(MAP(_deb,__VA_ARGS__)) dd.os<<"\n";}