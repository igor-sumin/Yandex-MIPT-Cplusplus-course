
#include <bits/stdc++.h>

using namespace std;

enum class TaskStatus {
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

// Позволяет хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

// перегрузка инкремента
TaskStatus& operator++(TaskStatus& ts) { 
	return (TaskStatus&)(++(int&)ts); 
}

TaskStatus MoveStatus(TaskStatus ts) { 
	return static_cast<TaskStatus>(static_cast<int>(ts) + 1);
}

class TeamTasks {
private:
	map<string, TasksInfo> personInfo;
	// map<string, map<TaskStatus, int>> personInfo;
public:
	// Получить статистику по статусам задач конкретного разработчика
	// TasksInfo == map<TaskStatus, int>
	const TasksInfo GetPersonTasksInfo(const string& person) const {
		return personInfo.find(person)->second;
	   // return personInfo.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person) {
		++personInfo[person][TaskStatus::NEW];
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		TasksInfo updated_tasks, untouched_tasks;

		for(TaskStatus status = TaskStatus::NEW; status <= TaskStatus::DONE; status = MoveStatus(status)) {
			// Считаем обновлённые
		    updated_tasks[MoveStatus(status)] = min(task_count, personInfo[person][status]);
		    // Считаем, сколько осталось обновить
		    task_count -= updated_tasks[MoveStatus(status)];
		}

		for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = MoveStatus(status)) {
			untouched_tasks[status] = personInfo[person][status] - updated_tasks[MoveStatus(status)];
			personInfo[person][status] = updated_tasks[status] + untouched_tasks[status];
		}

		// По условию, DONE задачи не нужно возвращать в не обновлённых задачах
		personInfo[person][TaskStatus::DONE] += updated_tasks[status];

  		// По условию в словарях не должно быть нулей
		RemoveZeros(personInfo.at(person));
		RemoveZeros(untouched_tasks);
		RemoveZeros(updated_tasks);		

		return make_tuple(updated_tasks, untouched_tasks);
	}

	// Функция для удаления нулей из словаря
	void RemoveZeros(TasksInfo& tasks_info) {
		// Соберём те статусы, которые нужно убрать из словаря
		vector<TaskStatus> statuses_to_remove;
		for (const auto& task_item : tasks_info) {
			if (task_item.second == 0) {
			  statuses_to_remove.push_back(task_item.first);
			}
		} 

		for (const TaskStatus status : statuses_to_remove) {
			tasks_info.erase(status);
		}
	}
};

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

	// Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
	// Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
	// Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
	// Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
	// Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
	// Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done

	return 0;
}
