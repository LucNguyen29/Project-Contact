#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "DanhBa.dat"

struct hoTen
{
    char HO[11];
    char DEM[20];
    char TEN[20];
};

struct person
{
    int yeuThich;
    struct hoTen HovaTen;
    char viecLam[20];
    char soDienThoai[11];
    char Email[50];
    char diaChi[50];
    char ngaySinh[11];
};

void nhapHoVaTen(struct hoTen *ten);
struct person nhapTTLH();
void hienThiTTLH(struct person ps);
void timTheoTen(struct person *ds, int sllh);
void ghiFile(struct person *ds, int sllh);
void docFile(struct person *ds, int *sllh);
void addFavorite(struct person *ps, int sllh);
void hienThiDSYT(struct person *ps, int sllh);
void hienThiCHiTiet(struct person *ps);

int main(int argc, char const *argv[])
{
    struct person danhBa[150];
    // struct person yeuThich[10];
    int sllh = 0;

    char choice;
    char choice1;
    struct person person1;
    char choice2;
    char ten[20];
    docFile(danhBa, &sllh);
    int n;
    do
    {

        system("cls");
        printf("=======================================\n");
        printf(" --- VTC ACADEMY CONTACT MANAGEMENT ---\n");
        printf("=======================================\n");
        printf("  1. Tim kiem\n");
        printf("  2. Them lien he\n");
        printf("  3. Hien lien he yeu thich\n");
        printf("  4. Hien danh sach lien he\n");
        printf("  5. Thoat khoi danh ba\n");
        printf("=======================================\n");
        printf("  Ban chon: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice)
        {
        case '1':

            system("cls");
            timTheoTen(danhBa, sllh);
            printf("Nhan phim bat ki de tiep tuc...");
            fflush(stdin);
            scanf("%c", &choice2);

            break;
        case '2':
            system("cls");
            person1 = nhapTTLH();
            danhBa[sllh++] = person1;
            ghiFile(danhBa, sllh);
            printf("=======================================\n");
            printf("Ban da them lien he thanh cong!\n");
            printf("Nhan phim bat ki de tiep tuc...");
            fflush(stdin);
            scanf("%c", &choice2);

            break;
        case '3':

            hienThiDSYT(danhBa, sllh);
            printf("Nhan phim bat ki de tiep tuc...");
            fflush(stdin);
            scanf("%c", &choice2);

            break;
        case '4':
            system("cls");
            printf("Day la cac danh sach lien he:\n");
            printf("Danh sach lien he:\n");
            printf("-------------------------------------\n");

            for (int i = 0; i < sllh; i++)
            {
                printf("%d. ", i + 1);
                hienThiTTLH(danhBa[i]);
            }
            printf("-------------------------------------\n");
            printf("Nhap so thu tu de xem chi tiet hoac nhan 0 de quay lai menu chinh:  ");
            scanf("%d", &n);
            if (n < 0 || n > sllh)
            {
                printf("Chon sai!\n");
            }
            else
            {
                if (n != 0)
                {
                    hienThiCHiTiet(&danhBa[n - 1]);
                }
            }

            printf("Nhan phim bat ki de tiep tuc...");
            fflush(stdin);
            scanf("%c", &choice2);

            break;
        case '5':
            printf("Hen gap lai ban sau!\n");

            break;

        default:
            break;
        }

    } while (choice != '5');

    return 0;
}

void nhapHoVaTen(struct hoTen *ten)
{
    printf("Ho: ");
    fflush(stdin);
    gets(ten->HO);
    printf("Ten dem: ");
    fflush(stdin);
    gets(ten->DEM);
    printf("Ten: ");
    fflush(stdin);
    gets(ten->TEN);
}

struct person nhapTTLH()
{

    struct person ps;
    printf("=======================================\n");
    printf("  Tao Lien He Moi\n");
    printf("=======================================\n");
    nhapHoVaTen(&ps.HovaTen);
    printf("Cong viec: ");
    gets(ps.viecLam);
    printf("So lien he: ");
    gets(ps.soDienThoai);
    printf("Email: ");
    gets(ps.Email);
    printf("Dia chi: ");
    gets(ps.diaChi);
    printf("Ngay Sinh: ");
    gets(ps.ngaySinh);
    ps.yeuThich = 0;

    return ps;
}

void hienThiTTLH(struct person ps)
{

    printf("%s %s %s\n", ps.HovaTen.HO, ps.HovaTen.DEM, ps.HovaTen.TEN);
}

void timTheoTen(struct person *ds, int sllh)
{
    char ten[20];
    int count = 0;
    printf("Nhap ten: ");
    scanf("%s", ten);
    for (int i = 0; i < sllh; i++)
    {

        if (strcmp(ten, ds[i].HovaTen.TEN) == 0)
        {

            hienThiTTLH(ds[i]);
            count++;
        }
    }

    if (count == 0)
    {
        printf("Khong tim thay nguoi lien he ten %s trong danh ba\n", ten);
    }
}

void ghiFile(struct person *ds, int sllh)
{
    FILE *ptr = fopen(FILE_NAME, "w");

    for (int i = 0; i < sllh; i++)
    {
        struct person ps = ds[i];
        fprintf(ptr, "%s\n", ps.HovaTen.HO);
        fprintf(ptr, "%s\n", ps.HovaTen.DEM);
        fprintf(ptr, "%s\n", ps.HovaTen.TEN);
        fprintf(ptr, "%s\n", ps.viecLam);
        fprintf(ptr, "%s\n", ps.soDienThoai);
        fprintf(ptr, "%s\n", ps.Email);
        fprintf(ptr, "%s\n", ps.diaChi);
        fprintf(ptr, "%s\n", ps.ngaySinh);
        fprintf(ptr, "%d\n", ps.yeuThich);
    }

    fclose(ptr);
}

void docFile(struct person *ds, int *sllh)
{
    FILE *ptr = fopen("DanhBa.dat", "r+");

    if (ptr == NULL)
    {
        return;
    }

    int i = 0;

    while (!feof(ptr))
    {
        struct person ps;
        fgets(ps.HovaTen.HO, 11, ptr);
        fgets(ps.HovaTen.DEM, 20, ptr);
        fgets(ps.HovaTen.TEN, 20, ptr);
        fgets(ps.viecLam, 20, ptr);
        fgets(ps.soDienThoai, 11, ptr);
        fgetc(ptr);
        fgets(ps.Email, 50, ptr);
        fgetc(ptr);
        fgets(ps.diaChi, 50, ptr);
        fgets(ps.ngaySinh, 15, ptr);
        ps.yeuThich = fgetc(ptr) - '0';
        fgetc(ptr);

        ps.HovaTen.HO[strlen(ps.HovaTen.HO) - 1] = '\0';
        ps.HovaTen.DEM[strlen(ps.HovaTen.DEM) - 1] = '\0';
        ps.HovaTen.TEN[strlen(ps.HovaTen.TEN) - 1] = '\0';
        ps.viecLam[strlen(ps.viecLam) - 1] = '\0';
        ps.Email[strlen(ps.Email) - 1] = '\0';
        ps.diaChi[strlen(ps.diaChi) - 1] = '\0';
        ps.ngaySinh[strlen(ps.ngaySinh) - 1] = '\0';

        ds[i++] = ps;
    }

    fclose(ptr);
    *sllh = i - 1;
}

void hienThiCHiTiet(struct person *ps)
{
    int *sllh;

    char choice, choice1, choice2;
    char BD[20];
    char CV[20];
    char nhaRieng[50];
    printf("Ho: %s\n", ps->HovaTen.HO);
    printf("Dem: %s\n", ps->HovaTen.DEM);
    printf("Ten: %s\n", ps->HovaTen.TEN);
    printf("Cong viec: %s\n", ps->viecLam);
    printf("So lien he: %s\n", ps->soDienThoai);
    printf("Email: %s\n", ps->Email);
    printf("Dia chi: %s\n", ps->diaChi);
    printf("Ngay Sinh: %s\n", ps->ngaySinh);
    printf("---------------------------------\n");
    printf("Nhan mot phim bat ki de tiep tuc...");
    fflush(stdin);
    scanf("%c", &choice1);

    do
    {
        system("cls");
        printf("====================================\n");
        printf("1. Them vao danh sach yeu thich\n");
        printf("2. Cap nhat\n");
        printf("3. Xoa khoi danh sach\n");
        printf("4. Them cac linh vuc\n");
        printf("5. Quay lai menu chinh\n");
        printf("====================================\n");
        printf("  Ban chon: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice)
        {
        case '1':
            system("cls");
            if (ps->yeuThich == 0)
            {
                ps->yeuThich = 1;
                printf("Them thanh cong!\n");
            }

            printf("-----------------------\n");
            printf("Nhan mot phim bat ki de tiep tuc....\n");
            fflush(stdin);
            scanf("%c", &choice1);

            break;
        case '2':

            break;
        case '3':
            system("cls");
            printf("Ban muon xoa lien he ra khoi danh sach yeu thich!\n");
            printf("  1: Co               2: Khong\n");
            printf("Ban chon: ");
            fflush(stdin);
            scanf("%c", &choice1);
            if (choice1 == '1')
            {
                if (ps->yeuThich == 1)
                {
                    ps->yeuThich = 0;
                    printf("Xoa thanh cong!\n");
                }
            }
            if (choice1 == '2')
            {
                printf("Ban chon khong xoa!\n");
            }
            printf("-----------------------\n");
            printf("Nhan mot phim bat ki de tiep tuc....\n");
            fflush(stdin);
            scanf("%c", &choice1);

            break;
        case '4':
            system("cls");
            printf("Biet danh: ");
            fflush(stdin);
            gets(BD);
            printf("Chuc Vu: ");
            fflush(stdin);
            gets(CV);
            printf("Nha Rieng: ");
            fflush(stdin);
            gets(nhaRieng);
            printf("Them thanh cong!\n");
            printf("-----------------------\n");

            printf("Nhan phim 1 de xem cac thong tin vua nhap hoac 0 de quay lai menu: ");
            scanf("%c", &choice2);

            if (choice2 == '1')
            {
                printf("Biet Danh: %s\n", BD);
                printf("Chuc Vu: %s\n", CV);
                printf("Nha Rieng: %s\n", nhaRieng);

                printf("-----------------------\n");
                printf("Nhan mot phim bat ki de tiep tuc....");
                fflush(stdin);
                scanf("%c", &choice1);
            }

            if (choice2 == 0)
            {
            }
            break;
        case '5':

            break;

        default:
            break;
        }

    } while (choice != '5');
}

void hienThiDSYT(struct person *ps, int sllh)
{
    printf("========================\n");
    printf("  Lien He Yeu Thich\n");
    printf("-------------------------\n");
    for (int i = 0; i < sllh; i++)
    {
        if (ps[i].yeuThich == 1)
        {
            hienThiTTLH(ps[i]);
        }
    }
    printf("=======================\n");
}
