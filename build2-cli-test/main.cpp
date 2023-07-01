#include <iostream>
//
#include <build2-cli-test/options.hpp>

using namespace std;

void usage() {
  cerr << "usage: driver [options] <names>" << endl << "options:" << endl;
  options::print_usage(cerr);
}

int main(int argc, char* argv[]) {
  try {
    int end;
    options o(argc, argv, end);
    if (o.help()) {
      usage();
      return 0;
    }
    if (end == argc) {
      cerr << "no names provided" << endl;
      usage();
      return 1;
    }
    for (int i = end; i < argc; i++) {
      cout << o.greeting() << ", " << argv[i];
      for (unsigned int j = 0; j < o.exclamations(); j++) cout << '!';
      cout << endl;
    }
  } catch (const cli::exception& e) {
    cerr << e << endl;
    usage();
    return 1;
  }
}
