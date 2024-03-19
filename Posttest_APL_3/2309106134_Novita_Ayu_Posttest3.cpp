#include <iostream>
#include <string>
using namespace std;

const int MAX_NARAPIDANA = 100; 
string nama_benar = "Novita";
string NIM_benar = "2309106134";

int pos = 0; 

struct Narapidana {
  string nama;
  string nomor_identifikasi;
  string jenis_kejahatan;
  string tanggal_masuk_penjara;
  string jangka_waktu_hukuman;
  string status_kesehatan;
};

Narapidana narapidana[MAX_NARAPIDANA];

bool login() {
    int i = 0;
    string nama, NIM;

    while (i < 3) {
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> NIM;

        if (nama == nama_benar && NIM == NIM_benar) {
            cout << "Selamat, login berhasil!" << endl;
            return true;
        } else {
            cout << "Maaf, login gagal." << endl;
            i++;
        }
    }

    cout << "Anda telah mencapai batas percobaan login. Program berhenti." << endl;
    return false;
}

bool empty() {
  return pos == 0;
}

char repeatInput() {
  char loop;
  cout << "Ulangi (y/t): ";
  cin >> loop;
  if (loop != 'y' && loop != 't') {
    cout << "Input tidak valid. Ulangi." << endl;
    return repeatInput(); // Rekursif jika input tidak valid
  }
  return loop;
}

void display() {
  cout << endl << "=== Daftar Narapidana ===" << endl;
  for (int i = 0; i < pos; i++) {
    cout << "Nama: " << narapidana[i].nama << endl;
    cout << "Nomor Identifikasi: " << narapidana[i].nomor_identifikasi << endl;
    cout << "Jenis Kejahatan: " << narapidana[i].jenis_kejahatan << endl;
    cout << "Tanggal Masuk Penjara: " << narapidana[i].tanggal_masuk_penjara << endl;
    cout << "Jangka Waktu Hukuman: " << narapidana[i].jangka_waktu_hukuman << endl;
    cout << "Status Kesehatan: " << narapidana[i].status_kesehatan << endl;
    cout << endl;
  }
}

void add() {
  int max = 100;
  char loop;
  do {
    display();
    if (pos < max) {
      cin.ignore(); 
      cout << "Masukkan nama narapidana: ";
      getline(cin, narapidana[pos].nama);
      cout << "Masukkan nomor identifikasi narapidana: ";
      getline(cin, narapidana[pos].nomor_identifikasi);
      cout << "Masukkan jenis kejahatan: ";
      getline(cin, narapidana[pos].jenis_kejahatan);
      cout << "Masukkan tanggal masuk penjara: ";
      getline(cin, narapidana[pos].tanggal_masuk_penjara);
      cout << "Masukkan jangka waktu hukuman: ";
      getline(cin, narapidana[pos].jangka_waktu_hukuman);
      cout << "Masukkan status kesehatan: ";
      getline(cin, narapidana[pos].status_kesehatan);

      pos++;
      cout << "Tambahkan data narapidana baru (y/t): ";
      cin >> loop;
    }
  } while (loop == 'y');
}

void edit() {
	if (empty()) {
		cout<< "DATA KOSONG. " << endl ;
		return ;
	}
	
  int y;
  char loop ;
  do {
    cin.ignore();
    display();
    cout << "Masukkan nomor narapidana yang ingin diubah: ";
    cin >> y;

    if (y >= 1 && y <= pos) {
    	cin.ignore() ;
      	cout << "Masukkan nama narapidana baru: ";
      	getline(cin, narapidana[y - 1].nama);
      	cout << "Masukkan nomor identifikasi narapidana baru: ";
      	getline(cin, narapidana[y - 1].nomor_identifikasi);
      	cout << "Masukkan jenis kejahatan narapidana baru: ";
      	getline(cin, narapidana[y - 1].jenis_kejahatan);
      	cout << "Masukkan tanggal masuk penjara narapidana baru: ";
      	getline(cin, narapidana[y - 1].tanggal_masuk_penjara);
      	cout << "Masukkan jangka waktu hukuman narapidana baru: ";
      	getline(cin, narapidana[y - 1].jangka_waktu_hukuman);
      	cout << "Masukkan status kesehatan narapidana baru: ";
      	getline(cin, narapidana[y - 1].status_kesehatan);

      	display();
      	cout << "Ubah data narapidana lain (y/t): ";
      	cin >> loop;
    	} else {
      	cout << "Nomor narapidana tidak valid." << endl;
    }
  } while (loop == 'y');
}

void del() {
  if (empty()) {
    cout << "Data kosong." << endl;
    return;
  }

  display();

  int index;
  char loop;
  do {
    cout << "Hapus data ke: ";
    cin >> index;
    cin.ignore();

    if (index >= 1 && index <= pos) {
      for (int i = index; i < pos; i++) {
        narapidana[i - 1] = narapidana[i];
      }
      pos--;
      display();
      cout << "Hapus data narapidana lain (y/t): ";
      cin >> loop;
    } else {
      cout << "Nomor narapidana tidak valid." << endl;
      cout << "Hapus data narapidana lain (y/t): ";
      cin >> loop;
    }
  } while (loop == 'y');
}

int main() {
    if (!login()) {
        cout << "Login gagal. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "::: DATA NARAPIDANA :::" << endl;
        cout << "-----------------------" << endl;

        cout << "[1]. Tambahkan data narapidana " << endl;
        cout << "[2]. Tampilkan data narapidana " << endl;
        cout << "[3]. Ubah data narapidana " << endl;
        cout << "[4]. Hapus data narapidana " << endl;
        cout << "[5]. Keluar" << endl;

        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1 :
                add() ;
                break ;
            case 2 :
                display() ;
                break;
            case 3 :
                edit() ;
                break ;
            case 4 :
                del() ;
                break ;
            case 5 :
                cout << "Keluar. " << endl ;
                break ;
            default :
                cout << "Pilihan tidak valid." << endl ;
                break ;
        }
    } while (pilihan != 5) ;

    cout << "PROGRAM SELESAI..." << endl;
    return 0;
}

