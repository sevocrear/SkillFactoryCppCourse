#include <fstream> 
  
int main() {

	std::ofstream outfile;
	outfile.open("test.txt");

	outfile.write("This is an apple", 16);
	long pos = outfile.tellp();
	outfile.seekp(pos - 7);
	outfile << " sam";

	outfile.close();

	return 0;
}