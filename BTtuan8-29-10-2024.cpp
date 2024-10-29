  #include<bits/stdc++.h>
using namespace std;

struct Node {
    float heso;
    int somu;
    Node* link;
};

struct ListDT {
    Node* fist, * last;
};

//khoi tao danh sach da thuc
void initDT(ListDT *l) {
    l->fist = l->last = NULL;

}

Node* callNode(float hs,int sm) {
    Node* p;
    p = new Node;
    if (p == NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}

void addNode(ListDT* lDT, Node*p) {
    if (lDT->fist == NULL) //DS rong
    {
        lDT->fist = lDT->last = p;
    }
    else
    {
        lDT->last->link = p; //gan dia chi nut cuoi bang p
        lDT->last = p; //chuyen p thanh nut cuoi
    }
}

void attachNode(ListDT*lDT, float hs, int sm) {
    Node* pDT = callNode(hs,sm);
    if (pDT == NULL) return;
    addNode(lDT, pDT);
}

void taoDT(ListDT *lDT) {
    float hs;
	int sm;
    int i = 0; //dem so phan tu
    cout << "-Bat dau nhap da thuc (nhap he so 0 de ket thuc): " << endl;
    do
    {
        i++;
        cout << "Nhap so phan tu thu " << i << endl;
		 cout << "\nNhap he so = ";
        cin >> hs;
        if (hs == 0) break;
        cout << "\nNhap so mu = ";
        cin >> sm;
        attachNode(lDT, hs, sm);
	} while (hs != 0);
    cout << "ket thuc nhap" << endl;

}

void inDT(ListDT lDT) {
    Node* p;
    p = lDT.fist;
    cout << "\nf(x) = ";
    while (p != NULL) {
        cout << p->heso << " * x^" << p->somu;
        if (p->link != NULL && p->heso!= 0) cout << " + ";
        p = p->link;
    }
}

int main()
{
    ListDT DT1;
    initDT(&DT1);
    taoDT(&DT1);
    inDT(DT1);
}
