#include <iostream>
#include <string>
#include <map>
using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

void PrintTasksInfo(TasksInfo tasks_info);

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    TasksInfo GetPersonTasksInfo(const string& person) const
    {
        TasksInfo answer;
        if (persons.at(person).at(TaskStatus::NEW))
            answer[TaskStatus::NEW] = persons.at(person).at(TaskStatus::NEW);
        if (persons.at(person).at(TaskStatus::IN_PROGRESS))
            answer[TaskStatus::IN_PROGRESS] = persons.at(person).at(TaskStatus::IN_PROGRESS);
        if (persons.at(person).at(TaskStatus::TESTING))
            answer[TaskStatus::TESTING] = persons.at(person).at(TaskStatus::TESTING);
        if (persons.at(person).at(TaskStatus::DONE))
            answer[TaskStatus::DONE] = persons.at(person).at(TaskStatus::DONE);
        return answer;
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person)
    {
        persons[person][TaskStatus::NEW]++;
        persons[person][TaskStatus::IN_PROGRESS];
        persons[person][TaskStatus::TESTING];
        persons[person][TaskStatus::DONE];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
    {
        TasksInfo updates;
        while (persons[person][TaskStatus::NEW] && task_count)
        {
            --task_count;
            --persons[person][TaskStatus::NEW];
            ++updates[TaskStatus::IN_PROGRESS];
        }
        while (persons[person][TaskStatus::IN_PROGRESS] && task_count)
        {
            --task_count;
            --persons[person][TaskStatus::IN_PROGRESS];
            ++updates[TaskStatus::TESTING];
        }
        while (persons[person][TaskStatus::TESTING] && task_count)
        {
            --task_count;
            --persons[person][TaskStatus::TESTING];
            ++updates[TaskStatus::DONE];
        }

        TasksInfo untouched;
        if (persons[person][TaskStatus::NEW])
            untouched[TaskStatus::NEW] = persons[person][TaskStatus::NEW];
        if (persons[person][TaskStatus::IN_PROGRESS])
            untouched[TaskStatus::IN_PROGRESS] = persons[person][TaskStatus::IN_PROGRESS];
        if (persons[person][TaskStatus::TESTING])
            untouched[TaskStatus::TESTING] = persons[person][TaskStatus::TESTING];

        persons[person][TaskStatus::IN_PROGRESS] += updates[TaskStatus::IN_PROGRESS];
        persons[person][TaskStatus::TESTING] += updates[TaskStatus::TESTING];
        persons[person][TaskStatus::DONE] += updates[TaskStatus::DONE];

        if (!updates[TaskStatus::IN_PROGRESS])
            updates.erase(TaskStatus::IN_PROGRESS);
        if (!updates[TaskStatus::TESTING])
            updates.erase(TaskStatus::TESTING);
        if (!updates[TaskStatus::DONE])
            updates.erase(TaskStatus::DONE);

        return make_tuple(updates, untouched);
    }

private:
    map<string, TasksInfo> persons;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
