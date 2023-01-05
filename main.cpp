#include "Job_S.h"

int main() {
  JobQueue jobQueue;

  cout << "Selamat datang di  Program Job Scheduling" << endl;
  cout << endl;
  cout << "Pilihan input :" << endl;
  cout << "> add: Menambahkan job baru ke antrian." << endl;
  cout << "> finish: Menghapus job (Prioritas tertinggi) yang sudah diselesaikan dari antrian dan memasukkan ke dalam stack recentPriorityJobs untuk proses dokumentasi." << endl;
  cout << "> recent: Menampilkan riwayat daftar job yang di kerjakan duluan sesuai prioritas tertinggi." << endl;
  cout << "> remove: Menghapus satu per satu riwayat recent priority job." << endl;
  cout << "> clear: Menghapus semua riwayat job yang sudah diselesaikan ditumpukan recent priority job." << endl;
  cout << "> exit: Keluar dari program." << endl;
  cout << endl;

  while (true) {
    string input;
    cout << "o> ";
    cin >> input;

    if (input == "add") {
      int id;
      string name;
      int priority;
      cout << "Masukkan ID job: ";
      cin >> id;
      cout << "Masukkan nama job: ";
      cin >> name;
      cout << "Masukkan prioritas job (1-5): ";
      cin >> priority;
      Job job = {id, name, priority};
      jobQueue.enqueue(job);
      cout << "Job berhasil ditambahkan ke antrian." << endl;
      cout << endl;
    } else if (input == "finish") {
      jobQueue.dequeue();
      cout << endl;
    } else if (input == "recent") {
      jobQueue.printRecentPriorityJobs();
      cout << endl;
    } else if (input == "queue") {
      jobQueue.printJobQueue();
      cout << endl;
    } else if (input == "priority") {
      int id;
      cout << "Masukkan ID job yang ingin dicari prioritasnya: ";
      cin >> id;
      jobQueue.printRecentPriorityJobs();
    } else if (input == "remove"){
      jobQueue.removeFromRecentPriorityJobs();
    } else if (input == "clear") {
      jobQueue.clearRecentPriorityJobs();
      cout << "Recent priority jobs telah dikosongkan." << endl;
      cout << endl;
    } else if (input == "exit") {
      cout << "Created by :" << endl;
      cout << "Mustaghfir Naufal Zaidan (1301213409)" << endl;
      cout << "Leonardus Adi Widjayanto (1301213423)";
      cout << endl;
      break;
    } else {
      cout << "Perintah tidak dikenali. Silakan coba lagi." << endl;
      cout << endl;
    }
  }

  return 0;
}
