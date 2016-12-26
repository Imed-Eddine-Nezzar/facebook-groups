#include <array>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

class Term {
public:
  Term(const std::string& en = {}, const std::string& fr = {}, Term* next = nullptr) :
    _en{en},
    _fr{fr}
  {}

  // TODO: check empty string?
  static char section(const Term& term) {
    return ::tolower(term._en[0]) - 'a';
  }

  inline std::string en() const { return _en; }
  inline std::string fr() const { return _fr; }

  inline char section() const {
    return Term::section(_en);
  }

private:
  std::string _en;
  std::string _fr;

  friend std::istream& operator>>(std::istream& is, Term& term) {
    std::getline(is, term._en, ':');
    std::getline(is, term._fr, ';');
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Term& term) {
    os << term._en << " : " << term._fr;
    return os ;
  }
};


class TermParser {
public:
  TermParser(std::ifstream& ifs) :
    _ifstream{ifs}
  {}
  using iterator = std::istream_iterator<Term>;
  iterator begin() { return std::istream_iterator<Term>{_ifstream}; }
  iterator end() { return std::istream_iterator<Term>{}; }

private:
  std::ifstream& _ifstream;
};


class Dictinary {
public:
  Dictinary(const char* path) :
    _sections{}
  {
    std::ifstream source{path};
    if (source) {
      for (auto& term : TermParser(source))
        insert(term);
    }
    else {
      // TODO: throw exception
      std::cerr << "couldn't open file!\n";
    }
  }

  void display() const {
    char section = 'A';
    for (auto sec = std::begin(_sections); sec != std::end(_sections); ++sec) {
      std::cout << "section " << section << ":\n"
                << std::string(10, '=') << "\n";
      std::copy(std::begin(*sec),std::end(*sec),
                std::ostream_iterator<Term>(std::cout, "\n"));
      std::cout << "\n";
      ++section;
    }
  }

  inline void insert(const Term& term) {
    _sections[term.section()].push_front(term);
  }

  std::string translate(const std::string& en) {
    auto& section = _sections[Term::section(en)];

    for (auto& term : section)
      if (term.en() == en)
        return term.fr();

    // TODO: maybe throw exception?
    return "no translation!";
  }

private:
  std::array<std::forward_list<Term>, 26> _sections;
};

int main(void) {
  Dictinary dict{"dic.txt"};
  dict.display();

  std::string word;
  for (int i = 3; i--;) {
    std::cout << "Text word: ";
    std::cin >> word;
    std::cout << word << " : " << dict.translate(word) << "\n";
  }
}