#ifndef JOB_S_H_INCLUDED
#define JOB_S_H_INCLUDED

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Job {
  int id;
  string name;
  int priority;
};

class JobQueue {
 public:
  void enqueue(Job job); //ADD DATA
  Job dequeue(); //HAPUS DATA
  void addToRecentPriorityJobs(const Job& job); // ADD DATA TO STACK
  void printRecentPriorityJobs(); //MENAMPILKAN DATA DI STACK
  void printJobQueue(); //MENAMPILKAN DATA DI QUEUE
  void removeFromRecentPriorityJobs(); //MENGHAPUS SATU PER SATU RECENT PRIORITY
  void clearRecentPriorityJobs(); //MENGHAPUS SEMUA RECENT PRIORITY
 private:
  queue<Job> jobs;
  stack<Job> recentPriorityJobs;
};


#endif // JOB_S_H_INCLUDED
