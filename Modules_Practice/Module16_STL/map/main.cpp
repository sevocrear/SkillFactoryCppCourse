#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main()
{
  map <string,int> myMap;

  myMap.insert({ "John", 23 });
  myMap.emplace(make_pair( "Lisa", 19 ));
  myMap.emplace(make_pair( "Alex", 9 ));
  
  for (map<string,int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
  {
      cout << it->first << " : " << it->second << endl;
  }
  
  map <string,int>::iterator it = myMap.find("Lisa");
  myMap.erase(it);
  myMap.erase("John");

  cout << "After Erase: " << endl;
  for (map<string,int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
  {
      cout << it->first << " : " << it->second << endl;
  }
  return 0;
}