#include <map>
#include <string>
using namespace std;

class ScoreTable
{
public:
    void AddScore(const string& name, int score);
    void DeleteScore(const string& name);
    void PrintScore(const string& name);
private:
    map<string, int> _table;
};