#include <bits/stdc++.h>
using namespace std;
typedef struct NhanVien
{
    int mnv;
    string hoten;
    string ns;
    float tl;

};
typedef struct DNode
{
    NhanVien info;
    DNode *next;
    DNode *prev;
};
typedef struct DList
{
    DNode *DHead;
    DNode *DTail;
};
struct DList L;
void InPutNV(NhanVien &x)
{
    cout<<"Nhap mnv: ";
    cin>>x.mnv;
    cout<<"Nhap ho ten: ";
    fflush(stdin);
    cin>>x.hoten;
    cout<<"Nhap ngay sinh: ";
    fflush(stdin);
    cin>>x.ns;
    cout<<"Nhap tong luong: ";
    cin>>x.tl;
}

void OutPutNV(NhanVien x)
{
    cout<<"MNV: "<<x.mnv;
    cout<<"\nHo ten: "<<x.hoten;
    cout<<"\nNgay sinh: "<<x.ns;
    cout<<"\nTong luong: "<<(int)x.tl;
}
void init(DList &L)
{
    L.DHead = NULL;
    L.DTail=NULL;
}
DNode *Get_DNode(NhanVien x)
{
    DNode *p;
    p = new DNode;
    p -> info = x;
    p -> next = NULL;
    p -> prev = NULL;
    return p;
}
int Length(DList L)
{
    int length = 0;
    for(DNode *p = L.DHead; p != NULL; p = p->next)
    {
        ++length;
    }
    return length;
}
void AddHead(DList &L, DNode *p)
{
    if(L.DHead==NULL)
    {
        L.DHead=p;
        L.DTail=L.DHead;
    }
    else
    {
        p->next=L.DHead;
        L.DHead->prev=p;
        L.DHead=p;
    }
}
void AddTail(DList &L,DNode *p)
{
    if(L.DHead==NULL)
    {
        L.DHead=p;
        L.DTail=L.DHead;
    }
    else
    {
        L.DTail->next=p;
        p->prev=L.DTail;
        L.DTail=p;
    }
}
void AddBefore(DList &L,DNode *q, DNode *new_ele)
{
    DNode *p;
    p=q->prev;
    if(q!=NULL)
    {
        new_ele-> next = q;
        if(p!=NULL)
        {
            new_ele->prev=p;
            p->next=new_ele;
        }
        q->prev=new_ele;
        if(q==L.DHead)
        {
            L.DHead=new_ele;
        }
        else
            AddTail(L,new_ele);
    }
}
void TLTatCa(DList L)
{
    int tongluong=0;
    for(DNode *p = L.DHead; p != NULL; p = p->next)
    {
        tongluong+=p->info.tl;

    }
    cout<<"Tong luong tat ca nhan vien la: "<<tongluong;
}
void DeleteHead(DList &L)
{
    DNode *p;
    if(L.DHead!=NULL)
    {
        p=L.DHead;
        L.DHead=L.DHead->next;
        L.DHead->prev=NULL;
        delete p;
        if(L.DHead!=NULL)
        {
            L.DTail=NULL;
        }
    }

    cout<<"\nDa xoa xong!!";
}

void DeleteTail(DList &L)
{
    DNode *p;
    if(L.DTail!=NULL)
    {
        p=L.DTail;
        L.DTail=L.DTail->prev;
        L.DTail->next=NULL;
        delete p;
        if(L.DHead==NULL)
        {
            L.DTail=NULL;
        }
    }

    cout<<"\nDa xoa xong!!";
}
void TLCaoNhat(DList L)
{
    if(L.DHead==NULL)
    {
        cout<<"\nDanh sach rong!!\n";
    }
    else
    {
        int cn=L.DHead->info.tl;
        for(DNode *p = L.DHead->next; p != NULL; p = p->next)
        {
            if(p->info.tl>cn)
            {
                cn=p->info.tl;
            }
        }
        cout<<"Danh sach nhan vien co luong cao nhat la: \n";
        for(DNode *p = L.DHead; p != NULL; p = p->next)
        {
            if(p->info.tl==cn)
            {
                OutPutNV(p->info);
            }
        }

    }
}
void TLTren2M(DList L)
{
    cout<<"Danh sach nhan vien co luong tren 2000000 la: \n";
    for(DNode *p = L.DHead; p != NULL; p = p->next)
    {
        if(p->info.tl>2000000)
        {
            OutPutNV(p->info);
        }
    }
}
void SXMNV(DList &L)
{
    for(DNode *p = L.DHead; p != NULL; p = p->next)
    {
        for(DNode *q = p->next; q != NULL; q = q->next)
        {
            if(p->info.mnv>q->info.mnv){
                swap(p->info,q->info);
            }
        }
    }
    cout<<"\nDa sap xep xong!!\n";
}
void InPut(DList &L, int n)
{
    init(L);
    NhanVien x;
    DNode *p;
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien thu " << i+1 << endl;
        InPutNV(x);
        p = Get_DNode(x);
        AddTail(L, p);
    }
}

void OutPut(DList L)
{
    for(DNode *p = L.DHead; p != NULL; p = p->next)
    {
        OutPutNV(p -> info);
        cout<<"\n----------------------------\n";
    }
}
int main()
{
    DList L;
    int luachon;
    while(1)
    {
        fflush(stdin);
        system("cls");
        cout<<"**********************************************\n";
        cout<<"**     CHUONG TRINH LUAN LY NHAN VIEN       **\n";
        cout<<"**     1. Nhap danh sach nhan vien          **\n";
        cout<<"**     2. Hien danh sach nhan vien          **\n";
        cout<<"**     3. Them 1 nhan vien vao dau ds       **\n";
        cout<<"**     4. Tong luong tat ca nhan vien       **\n";
        cout<<"**     5. Xoa 1 nhan vien dau danh sach     **\n";
        cout<<"**     6. Nhan vien co tong luong cao nhat  **\n";
        cout<<"**     7. Nhan vien co tong luong tren 2tr  **\n";
        cout<<"**     8. Sap xep nhan vien theo MNV        **\n";
        cout<<"**     0. Thoat                             **\n";
        cout<<"**********************************************\n";
        cout<<"**         Hay chon chuc nang               **\n";
        cin>>luachon;
        switch(luachon)
        {
        case 1:
            {
                system("cls");
                cout<<"Ban da chon nhap danh sach nhan vien\n";
                int c;
                cout<<"Nhap so nhan vien: ";
                cin>>c;
                InPut(L,c);
                cout<<endl;
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                cout<<"Ban da chon hien danh sach nhan vien\n";
                OutPut(L);
                cout<<endl;
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                cout<<"Ban da chon them 1 nhan vien vao dau danh sach\n";
                NhanVien x;
                DNode *p;
                InPutNV(x);
                p = Get_DNode(x);
                AddHead(L,p);
                cout<<"\nDa them xong!!"<<endl;
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                cout<<"Ban da chon xem tong luong tat ca nhan vien\n";
                TLTatCa(L);
                cout<<endl;
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                cout<<"Ban da chon xoa nhan vien dau danh sach\n";
                DeleteHead(L);
                cout<<endl;
                system("pause");
                break;
            }
        case 6:
            {
                system("cls");
                cout<<"Ban da chon hien nhan vien co tong luong cao nhat\n";
                TLCaoNhat(L);
                cout<<endl;
                system("pause");
                break;
            }
        case 7:
            {
                system("cls");
                cout<<"Ban da chon hien nhan vien co tong luong tren 2000000\n";
                TLTren2M(L);
                cout<<endl;
                system("pause");
                break;
            }
            case 8:
            {
                system("cls");
                cout<<"Ban da chon sap xep nhan vien theo MNV\n";
                SXMNV(L);
                cout<<endl;
                system("pause");
                break;
            }
        case 0:
            system("cls");
            cout<<"Ban da chon thoat chuong trinh!";
            return 0;
        default:
            system("cls");
            cout<<"Khong co chuc nang nay!";
            cout<<endl;
            system("pause");
            break;
        }
    }
}

