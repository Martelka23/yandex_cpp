#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
  ostringstream output;
  if (1)
    PRINT_VALUES(output, 5, "red belt");
  else
    PRINT_VALUES(output, 4, "belt");

  cout << output.str() << endl;

  return 0;
}
