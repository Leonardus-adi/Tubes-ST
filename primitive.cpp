#include "Job_S.h"

void JobQueue::enqueue(Job job) {
  jobs.push(job);
}

Job JobQueue::dequeue() {
  // Buat variabel untuk menampung job yang akan dikembalikan
  Job highestPriorityJob;
  bool found = false;

  // Cari job dengan priority tertinggi di antrian
  queue<Job> temp = jobs;
  while (!temp.empty()) {
    auto job = temp.front();
    temp.pop();
    if (!found || job.priority > highestPriorityJob.priority) {
      highestPriorityJob = job;
      found = true;
    }
  }

  // Hapus job dengan priority tertinggi dari antrian
  int size = jobs.size();
  for (int i = 0; i < size; i++) {
    auto job = jobs.front();
    jobs.pop();
    if (job.id != highestPriorityJob.id) {
      jobs.push(job);
    }
  }

  // Tambahkan job dengan priority tertinggi ke dalam stack recentPriorityJobs
  addToRecentPriorityJobs(highestPriorityJob);

  // Kembalikan job dengan priority tertinggi
  return highestPriorityJob;
}

void JobQueue::addToRecentPriorityJobs(const Job& job) {
    if (recentPriorityJobs.size() == 10) {
    // Stack recentPriorityJobs sudah penuh, jadi tidak perlu menambahkan job lagi
        cout << "stack penuh !!";
        cout << endl;
        return;
  }

  stack<Job> temp;
  bool added = false;

  // Cari posisi yang tepat untuk menambahkan job ke dalam stack recentPriorityJobs
  while (!recentPriorityJobs.empty()) {
    auto currentJob = recentPriorityJobs.top();
    recentPriorityJobs.pop();
    if (!added && job.priority > currentJob.priority) {
      // Tambahkan job ke dalam stack
      temp.push(job);
      added = true;
    }
    // Tambahkan currentJob ke dalam stack
    temp.push(currentJob);
  }

  if (!added) {
    // Tambahkan job ke dalam stack jika belum ditambahkan sebelumnya
    temp.push(job);
  }

  // Salin stack temp ke dalam stack recentPriorityJobs
  while (!temp.empty()) {
    recentPriorityJobs.push(temp.top());
    temp.pop();
  }
}

void JobQueue::printRecentPriorityJobs() {
  cout << "Recent priority jobs:" << endl;
  if (recentPriorityJobs.empty()) {
    cout << "Tumpukan recent priority job kosong!" << endl;
  } else {
    stack<Job> temp = recentPriorityJobs;
    while (!temp.empty()) {
      auto job = temp.top();
      cout << "ID: " << job.id << ", Name: " << job.name << ", Priority: " << job.priority << endl;
      temp.pop();
    }
  }
}

void JobQueue::printJobQueue() {
  cout << "Jobs in the queue:" << endl;
  if (jobs.empty()) {
    cout << "Antrian kosong!" << endl;
  } else {
    queue<Job> temp = jobs;
    while (!temp.empty()) {
      auto job = temp.front();
      cout << "ID: " << job.id << ", Name: " << job.name << ", Priority: " << job.priority << endl;
      temp.pop();
    }
  }
}

void JobQueue::removeFromRecentPriorityJobs() {
  if (recentPriorityJobs.empty()) {
    cout << "Stack recentPriorityJobs kosong, tidak ada yang bisa dihapus" << endl;
  } else {
    recentPriorityJobs.pop();
  }
}

void JobQueue::clearRecentPriorityJobs() {
  while (!recentPriorityJobs.empty()) {
    recentPriorityJobs.pop();
  }
}
