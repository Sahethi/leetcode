struct Task {
    int id;
    int userId; // Track the owner
    string desc;
    int dueDate;
    unordered_set<string> tags;
};

class TodoList {
public:
    int nextTaskId;

    unordered_map<int, list<Task>> userTasks;
    unordered_map<int, list<Task>::iterator> taskLookup;

    TodoList() {
        nextTaskId = 1;
    }
    
    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        int taskId = nextTaskId++;

        unordered_set<string> tagSet(tags.begin(), tags.end());
        
        Task newTask = {taskId, userId, taskDescription, dueDate, tagSet};

        auto& currentList = userTasks[userId];
        auto it = currentList.begin();
        
        while (it != currentList.end() && it->dueDate <= dueDate) {
            it++;
        }

        auto insertedIt = currentList.insert(it, newTask);
        taskLookup[taskId] = insertedIt;
        
        return taskId;
    }
    
    vector<string> getAllTasks(int userId) {
        vector<string> result;
        
        // If the user has no tasks, return an empty list
        if (userTasks.find(userId) == userTasks.end()) {
            return result;
        }
        
        // Since the list is kept sorted on write, we just read from front to back
        for (const auto& task : userTasks[userId]) {
            result.push_back(task.desc);
        }
        
        return result;
    }
    
    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> result;
        
        if (userTasks.find(userId) == userTasks.end()) {
            return result;
        }
        
        // Scan the sorted list and filter by tag
        for (const auto& task : userTasks[userId]) {
            if (task.tags.count(tag)) {
                result.push_back(task.desc);
            }
        }
        
        return result;
    }
    
    void completeTask(int userId, int taskId) {
        if (taskLookup.find(taskId) == taskLookup.end()) {
            return;
        }

        auto it = taskLookup[taskId];
        
        // Check if the task actually belongs to the user making the request
        if (it->userId != userId) {
            return; 
        }

        userTasks[userId].erase(it);
        taskLookup.erase(taskId);
        
        if (userTasks[userId].empty()) {
            userTasks.erase(userId);
        }
    }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */