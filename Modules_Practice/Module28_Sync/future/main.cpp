using namespace std;
#include <iostream>
#include <future>

bool threadFunc() {
	// do something
	cout << " Hello " << endl;
	return true;
}

int main() {
	future<bool> f = async(launch::async, threadFunc);

	// some code ...
      try {
	    bool result = f.get();
      }
      catch (const std::exception &e) {
          //some code
      }
	return 0;
}