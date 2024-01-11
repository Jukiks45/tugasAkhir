#include <stdio.h>

void displayFood(char menu[2][7][50], int prices[2][7], int orderFood[20], int qtyFood[20], int *jumlahElemenF)
{
    char end = 'n';
    int j = 0;
    printf("Pilih makanan pelanggan : \n");
    for (int i = 1; i < 6; i++)
    {
        printf("%d. %s - Harga: Rp %d\n", i, menu[0][i], prices[0][i]);
    }
    printf("6. %s\n", menu[0][6]);
    for (int i = 0; end != 'y'; i++)
    {
        printf("Masukkan pilihan pelanggan : ");
        scanf("%d", &orderFood[j]);
        if (orderFood[j] == 6)
        {
            break;
        }
        (*jumlahElemenF)++;
        printf("jumlah  : ");
        scanf("%d", &qtyFood[j]);
        j++;
        getchar();
        printf("sudah (y/n) : ");
        scanf(" %c", &end);
        if (end != 'y' && end != 'n')
        {
            printf("sudah (y/n) : ");
            scanf(" %c", &end);
        }
    }
}

void displayDrink(char menu[2][7][50], int prices[2][7], int orderDrink[20], int qtyDrink[20], int *jumlahElemenD)
{
    char end = 'n';
    int j = 0;
    printf("Pilih minuman pelanggan : \n");
    for (int i = 1; i < 6; i++)
    {
        printf("%d. %s - Harga: Rp %d\n", i, menu[1][i], prices[1][i]);
    }
    printf("6. %s \n", menu[1][6]);
    for (int i = 0; end != 'y'; i++)
    {
        printf("Masukkan pilihan pelanggan : ");
        scanf("%d", &orderDrink[j]);
        if (orderDrink[j] == 6)
        {
            break;
        }
        (*jumlahElemenD)++;
        printf("jumlah  : ");
        scanf("%d", &qtyDrink[j]);
        j++;
        getchar();
        printf("sudah (y/n) : ");
        scanf(" %c", &end);
        if (end != 'y' && end != 'n')
        {
            printf("sudah (y/n) : ");
            scanf(" %c", &end);
        }
    }
}

int main()
{
    int cMenu, orderFood[20], orderDrink[20], qtyFood[20], qtyDrink[20], jumlahElemenF = 0, jumlahElemenD = 0, totbayar, bayar, kembalian, totmakanan = 0, totminuman = 0, diskon;
    char member;
    char menu[2][7][50] = {
        {"", "Nasi Goreng", "Mie Goreng", "Ayam Bakar", "Sate Ayam", "Rawon", "Tidak pesan"},
        {"", "Es Teh", "Es Jeruk", "Jus Alpukat", "Kopi", "Teh Hangat", "Tidak pesan"}};
    int prices[2][7] = {
        {0, 15000, 12000, 25000, 18000, 20000, 0},
        {0, 5000, 6000, 10000, 3000, 4000, 0}};
    printf("== WELCOME == \n");
    displayFood(menu, prices, orderFood, qtyFood, &jumlahElemenF);
    displayDrink(menu, prices, orderDrink, qtyDrink, &jumlahElemenD);

    if (orderFood[0] == 6)
    {
        printf("Anda tidak memesan makanan \n");
    }
    else
    {
        printf("Pesanan Makanan Anda: \n");
        for (size_t i = 0; i < jumlahElemenF; i++)
        {
            printf("%d. %s Rp -", i + 1, menu[0][orderFood[i]]);
            printf("%d  ", prices[0][orderFood[i]]);
            printf("%dx \n", qtyFood[i]);
        }
    }
    // printf("%d", orderDrink[0]);
    if (orderDrink[0] == 6)
    {
        printf("Anda tidak memesan minuman \n");
    }
    else
    {
        printf("Pesanan Minuman Anda: \n");
        for (size_t i = 0; i < jumlahElemenD; i++)
        {
            printf("%d. %s Rp -", i + 1, menu[1][orderDrink[i]]);
            printf("%d  ", prices[1][orderDrink[i]]);
            printf("%dx \n", qtyDrink[i]);
        }
    }
    for (size_t i = 0; i < jumlahElemenF; i++)
    {
        totmakanan += prices[0][orderFood[i]] * qtyFood[i];
    }
    for (size_t i = 0; i < jumlahElemenD; i++)
    {
        totminuman += prices[1][orderDrink[i]] * qtyDrink[i];
    }
    printf("Apakah anda punya member (y/n) :  ");
    scanf("%s", &member);
    if (member == 'y')
    {
        diskon = (totmakanan + totminuman) * 0.1;
        totbayar = (totmakanan + totminuman) - diskon;
        printf("Total pesanan anda jika tidak member : %d \n", totmakanan + totminuman);
    }
    else
    {
        totbayar = totmakanan + totminuman;
    }
    printf("Total Pesanan Anda :  %d \n", totbayar);
    printf("Masukkan Uang Anda : ");
    scanf("%d", &bayar);

    if (bayar > totbayar)
    {
        kembalian = bayar - totbayar;
        printf("Kembalian anda : %d \n", kembalian);
    }
    else if (bayar == totbayar)
    {
        printf("Uang Anda pas \n");
    }
    else
    {
        printf("Uang anda kurang");
        while (bayar < totbayar)
        {
            printf("Masukkan uang pas / lebih :");
            scanf("%d", &bayar);
            if (bayar > totbayar)
            {
                kembalian = bayar - totbayar;
                printf("Kembalian anda : %d \n", kembalian);
            }
            else if (bayar == totbayar)
            {
                printf("Uang Anda pas \n");
            }
        }
    }

    return 0;
}
