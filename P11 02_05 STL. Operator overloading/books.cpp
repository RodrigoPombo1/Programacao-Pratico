#include "Page.h"
#include "Book.h"
#include <iostream>
using namespace std;

void Book::build_index(const set<string>& words) {
    for (string word : words) {
        int count_pages = 0;
        for (auto page : book_) {
            count_pages++;
            for (size_t i = 0; i < page.get_num_lines(); i++) {
                if (page.get_line(i).find(word) != string::npos) {
                    index_[word].emplace(count_pages);
                }
            }
        }
    }
}

int main() {
    { Book b;
  if (!(b.import("book_01.txt"))) cout << "book not found! \n";
  set<string> words = { "C++", "linux", "computer" };
  b.build_index(words);
  b.show_index(); }
  return 0;
}