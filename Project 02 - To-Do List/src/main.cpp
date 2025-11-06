#include "../include/Helper.h"

#include <iostream>
#include <vector>  
using namespace std;

const string FileName = "TasksLog.txt";

struct Tasks {
    string description;
    bool isCompleted;
};

void addTasks(vector<Tasks> & newTasksList) {
    string userInput;
    cout << "[✏️] Lütfen yeni görevin açıklamasını girin: "; 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    getline(cin, userInput);
    Tasks newTask = {userInput, false};
    
    if(userInput.size() > 0) {
        newTasksList.push_back(Tasks(newTask));
         cout << "[✅] Yeni görev başarıyla eklendi: " << userInput << endl; 
    } else {
        cout << "[⚠️] Hata: Boş bir görev giremezsiniz. Lütfen tekrar deneyin." << endl;
    }
};

void removeTasks(vector<Tasks> & TaskList) {
    if(TaskList.empty()){
        cout << "[ℹ️] Silinecek bir görev bulunmuyor. Liste zaten boş." << endl;
          return;
    } else {
        cout << "[🗑️] Silmek istediğiniz görevin numarasını girin: ";
        viewTasks(TaskList); 
        int numDeleteTasks = getUserInput(TaskList.size());
        
        string deletedTaskName = TaskList[numDeleteTasks - 1].description; 
        
        TaskList.erase(TaskList.begin() + (numDeleteTasks -1));
        
        cout << "[✅] '" << deletedTaskName << "' adlı görev başarıyla silindi." << endl;
    }
};

void viewTasks(vector<Tasks> & TaskList) {
    if(TaskList.empty()) {
        cout << "[ℹ️] Gösterilecek bir görev bulunmuyor. Listeniz boş." << endl;
          return;
    } else {
        cout << "\n--- YAPILACAKLAR LİSTENİZ ---" << endl;
        for(int i = 0; i < TaskList.size(); ++i) {
            string isNewCompleted = TaskList[i].isCompleted ? "✅" : "❎";
            cout << (i+1) << ". " << isNewCompleted << " " << TaskList[i].description << endl;
        }
        cout << "--------------------------------\n" << endl;
    }
};

void completedTasks(vector<Tasks> & TaskList) {
    if(TaskList.empty()) {
        cout << "[ℹ️] Tamamlanacak bir görev bulunmuyor. Liste boş." << endl;
          return;
    } else {
        cout << "[❓] Tamamlamak istediğiniz görevin numarasını girin: ";
        viewTasks(TaskList);
        int numTasks = getUserInput(TaskList.size());
        if(TaskList[numTasks -1].isCompleted == true) {
            cout << "[ℹ️] Bu görev zaten 'tamamlandı' olarak işaretlenmiş." << endl;
        } else {
            TaskList[numTasks -1].isCompleted = true;
            cout << "[🎉] Harika! '" << TaskList[numTasks -1].description << "' görevi tamamlandı." << endl;
        }
    }
};

int main() {
    vector<Tasks> TasksList;

      printMenu();
    int choice = 0;
      clearMenu();
       while (choice != 5) { 

        choice = getUserInput(5); 
        switch (choice) {
            case 1:
                addTasks(TasksList);
                break;
            case 2:
                removeTasks(TasksList);
                break;
            case 3:
                completedTasks(TasksList);
                break;
            case 4: 
                viewTasks(TasksList);
                break;
            case 5: 
                cout << "[👋] Programdan çıkılıyor. İyi günler!" << endl;
                break;
            default: 
                cout << "[⚠️] Geçersiz seçim. Lütfen menüden bir numara girin." << endl;
                printMenu(); 
                break;
        }
    }

    return 0;
}