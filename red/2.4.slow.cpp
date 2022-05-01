#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

class ReadingManager {
public:

  void Read(int user_id, int page_count) {
    if (user_page.count(user_id))
      --page_count_of_user[user_page[user_id]];
    else
      ++count_of_users;
    user_page[user_id] = page_count;
    ++page_count_of_user[user_page[user_id]];
  }

  double Cheer(int user_id) const {
    if (!user_page.count(user_id))
      return 0;
    int count_of_lower = 0;
    int border = user_page.at(user_id);
    for (int i = 1; i < border; i++)
      count_of_lower += page_count_of_user[i];

    return (count_of_users == 1) ? 1 : (double)count_of_lower / ((double)count_of_users - 1);
  }

private:
  map<int, int> user_page;
  int count_of_users = 0;
  vector<int> page_count_of_user = vector<int>(1000, 0);
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}