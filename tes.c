#include <stdio.h>

// Fungsi untuk mengubah nilai int
void ubahNilai(int *nilai)
{
    // Ubah nilai menggunakan pointer
    *nilai = 42;
}

int main()
{
    int angka = 10;

    // Sebelum pemanggilan fungsi
    printf("Nilai sebelum diubah: %d\n", angka);

    // Panggil fungsi untuk mengubah nilai
    ubahNilai(&angka);

    // Setelah pemanggilan fungsi
    printf("Nilai setelah diubah: %d\n", angka);

    return 0;
}
