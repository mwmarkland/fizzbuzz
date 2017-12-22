#include <ostream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

class FizzBuzz {
  enum class state {fizz=1,buzz=2,fizzbuzz=3,identity=4};
  state theState;
  int number;
 public:
  FizzBuzz() : theState(state::identity),number(0) {};
  ~FizzBuzz() {}
  FizzBuzz(const FizzBuzz& fb) {
    this->theState = fb.theState;
    this->number = fb.number;
  }

  void setFizz(void) { theState = state::fizz; return; }
  void setBuzz(void) { theState = state::buzz; return; }
  void setFizzBuzz(void) { theState = state::fizzbuzz; return; }
  void setIdentity(int val) { theState = state::identity; number = val; return;}
  
  friend std::ostream& operator<< (std::ostream& out, const FizzBuzz& fb);
};

std::ostream& operator<< (std::ostream& out, const FizzBuzz& fb) {
  if(fb.theState == FizzBuzz::state::identity) {
    out << fb.number;
  } else if(fb.theState == FizzBuzz::state::fizz) {
    out << "fizz";
  } else if(fb.theState == FizzBuzz::state::buzz) {
    out << "buzz";
  } else if(fb.theState == FizzBuzz::state::fizzbuzz) {
    out << "fizzbuzz";
  }
  return out;
} // operator<<

void fizzbuzz_transform_to_class(const std::vector<int>& vInput) {

  // Create the FizzBuzz vector. Allocate enough of them to copy construct over.
  std::vector<FizzBuzz> vFizzBuzz(vInput.size());
  std::transform(vInput.begin(), vInput.end(),vFizzBuzz.begin(),
                 [](int val) -> FizzBuzz {
                   FizzBuzz fb;
                   if(val%15 == 0) {
                     fb.setFizzBuzz();
                   } else if(val%5 == 0){
                     fb.setBuzz();
                   } else if(val%3 == 0) {
                     fb.setFizz();
                   } else {
                     fb.setIdentity(val);
                   }
                   return fb;
                 });

  for(FizzBuzz f : vFizzBuzz) {
    std::cout << f << std::endl;
  }
  
  return;

} // fizzbuzz_transform_to_class

void fizzbuzz_transform_to_string(const std::vector<int>& vInput) {

  // Create the FizzBuzz vector. Allocate enough of them to copy construct over.
  std::vector<std::string> vString(vInput.size());
  std::transform(vInput.begin(), vInput.end(),vString.begin(),
                 [](int val) -> std::string {
                   if(val%15 == 0) {
                     return "fizzbuzz";;
                   } else if(val%5 == 0){
                     return "buzz";
                   } else if(val%3 == 0) {
                     return "fizz";
                   } else {
                     std::ostringstream os;
                     os << val;
                     return os.str();
                   }
                 });

  for(std::string f : vString) {
    std::cout << f << std::endl;
  }
  
  return;

} // fizzbuzz_transform_to_string


void fizzbuzz_loop(int count) {
  for(int i = 1; i <= count; i++) {
    if((i % 15) == 0) {
      std::cout << "fizzbuzz" << std::endl;
    } else if ((i % 5) == 0) {
      std::cout << "buzz" << std::endl;
    } else if ((i % 3) == 0) {
      std::cout << "fizz" << std::endl;
    } else {
      std::cout << i << std::endl;
    }
  } // for
  return;
}

int main(int argc,char *argv[]) {

  // Expect one argument, a count of how many iterations.
  if(argc != 2) {
    exit(-1);
  }
  int count = atoi(argv[1]);
  std::cout << "Generating " << count << " entries." << std::endl;

  // Create input vector.
  std::vector<int> vInput;
  for(int i = 1; i <= count; i++) {
    vInput.push_back(i);
  }

  fizzbuzz_transform_to_class(vInput);
  fizzbuzz_transform_to_string(vInput);
  
  return 0;
}
