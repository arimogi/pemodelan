/* ===================================
 * 
 * Transmisi Data
 * 
 * =================================== */
using namespace std;

#include <stdio.h>
#include <math.h>

void sendData(char ID_send, char ID_recv, int number) {
	printf("send-- paket data ke-%i dikirim dari %c ke %c.\n", number, ID_send, ID_recv);
}

void receiveData(char ID_recv, char ID_send, int number) {
	printf("recv-- paket data ke-%i dari %c diterima oleh %c.\n", number, ID_send, ID_recv);
}

int countDataToSend(int data_size, int bandwidth) {
	int counter;
	float temp;
	temp = (float)data_size / (float)bandwidth;
	counter = ceil(temp);
	return counter;
}

int main() {
	int data_A = 100; 	// ukuran paket A: 100byte
	int data_B = 135; 	// ukuran paket B: 135byte
	int bandwidth = 10; // lebar jalur komunikasi 10byte per detik (satu satuan waktu)
	int i, n_paket;
	
	// 1. Proses pengiriman data dari A ke B
	// 		a. hitung banyaknya paket yang akan dikirimkan
	n_paket = countDataToSend(data_A, bandwidth);
	printf("Banyak paket untuk data A: %i paket berukuran %ibyte\n", n_paket, bandwidth);
	
	// 		b. kirimkan sesuai counter berdasarkan ukuran bandwidth
	for (i=1; i<=n_paket; i++) {
		// fungsi pengiriman
		sendData('A', 'B', i);
		// fungsi penerimaan
		receiveData('B', 'A', i);
	}
	//		c. selesai mengirimkan seluruh paket
	printf("Seluruh paket telah dikirimkan dari A ke B\n");
	
	// 2. Proses pengiriman data dari B ke A
	// 		a. hitung banyaknya paket yang akan dikirimkan
	n_paket = countDataToSend(data_B, bandwidth);
	printf("Banyak paket untuk data B: %i paket berukuran %ibyte\n", n_paket, bandwidth);
	
	// 		b. kirimkan sesuai counter berdasarkan ukuran bandwidth
	for (i=1; i<=n_paket; i++) {
		// fungsi pengiriman
		sendData('B', 'A', i);
		// fungsi penerimaan
		receiveData('A', 'B', i);
	}
	//		c. selesai mengirimkan seluruh paket
	printf("Seluruh paket telah dikirimkan dari B ke A\n");
	
	return 0;
}

// end of file main.cpp
