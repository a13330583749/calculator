#include <iostream>
class Book {
  int mCount {1};
  std::string mName;
  public:
  std::string& get_name() {
      return mName;
  }
  Book(std::string iName): mName(iName) {}
  Book(Book&& iBook) {
    swap(this->mName, iBook.mName);
    mCount = 3;
  }
  int get_count() {
      return mCount;
  }
};

int main() {
    Book b("Im");
    Book tb = std::move(b);
    std::cout<<"old b name is " << b.get_name()<< " count is "<< b.get_count();
    std::cout<<"\ntb name is " << tb.get_name()<<  " count is "<< tb.get_count();
}