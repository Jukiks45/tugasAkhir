#include <stdio.h>

void displayFood(char menu[2][7][50], int prices[2][7], int orderFood[20], int qtyFood[20])
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
        printf("jumlah  : ");
        scanf("%d", &qtyFood[j]);
        j++;
        getchar();
        printf("sudah (y/n) : ");
        scanf("%c", &end);
    }
};

void displayDrink(char menu[2][7][50], int prices[2][7],int orderDrink[20], int qtyDrink[20])
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
        printf("jumlah  : ");
        scanf("%d", &qtyDrink[j]);
        j++;
        getchar();
        printf("sudah (y/n) : ");
        scanf("%c", &end);
    }
}

int main()
{
    int cMenu, orderFood[20], orderDrink[20], qtyFood[20], qtyDrink[20];
    char menu[2][7][50] = {
        {"", "Nasi Goreng", "Mie Goreng", "Ayam Bakar", "Sate Ayam", "Rawon", "Tidak pesan"},
        {"", "Es Teh", "Es Jeruk", "Jus Alpukat", "Kopi", "Teh Hangat", "Tidak pesan"}};
    int prices[2][7] = {
        {0, 15000, 12000, 25000, 18000, 20000, 0},
        {0, 5000, 6000, 10000, 3000, 4000, 0}};
    printf("== WELCOME == \n");
    displayFood(menu, prices, orderFood, qtyFood);
    displayDrink(menu, prices,orderDrink,qtyDrink);
    for (size_t i = 0; i < 3; i++)
    {
        printf("order : %d \n",orderFood[i]);
    }
    for (size_t i = 0; i < 3; i++)
    {
        printf("qty : %d \n",qtyFood[i]);
    }
    
    return 0;
}
