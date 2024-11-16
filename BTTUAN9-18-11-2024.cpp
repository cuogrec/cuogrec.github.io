#include<bits/stdc++.h>
using namespace std;

struct Node{
	string word; // data
	Node* next; // la 1 con tro kieu node
};

typedef Node* node ;

node taoNode(string data){
	//cap phat dong 1 node
	node tmp = new Node();
	tmp->word = data ;
	tmp->next = NULL ;
	return tmp;
}

void themCUOI(node &head, string data){
	node moi = taoNode(data);
	if(head == NULL){
		head = moi;
	}
	else{
		node tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = moi;
	}
}

int DemTu(node head){
	int dem = 0;
	while(head != NULL){
		++dem;
		head = head->next;
	}
	return dem;
}

void TuLay(node &head){
	node p = head;
	while(p != NULL && p->next != NULL){
		if(p->word == p->next->word){
			node tmp = p->next;
			p->next = tmp->next;
			delete tmp;
		}
		else{
			p = p->next;
		}
	}
}

void sx(node &head){
	for(node i = head; i != NULL ; i = i->next){
		node min = i;
		for(node j = i->next ; j!= NULL ; j = j->next){
			if(j->word < min->word) min = j;
		}
		string tmp = min->word;
		min->word = i->word;
		i->word = tmp;
	}
}
string tuXHnhieunhat(node &head){
	sx(head);
	node p = head;
	string Tnow = p->word;
	int dem = 1 , max = 1;
	string Tmax = Tnow;
	while(p->next != NULL){
		p = p->next;
		if(p->word == Tnow){
			dem++;
		}
		else{
			Tnow = p->word;
			dem = 1;
		}
		if(dem > max){
			max = dem;
			Tmax = Tnow;
		}
	}
	return Tmax;
}
void giaiPhongBoNho(node head) {
    while (head != NULL) {
        node tmp = head;
        head = head->next;
        delete tmp;
    }
}

void display(node head){
	cout << "DANH SACH LIEN KET : " ;
	while(head != NULL){
		cout << head->word << " " ;
		head = head->next;
	}
}
int main(){
	node head = NULL;
	while(1){
		int n ; cin >> n;
		if(n == 1){
			string word ; cin >> word;
			themCUOI(head, word);
		}
		else if(n == 2){
			string x = tuXHnhieunhat(head);
			cout << x << " " << endl;
		}
		else if(n == 3){
			int dem = DemTu(head);
			cout << dem << " " << endl;
		}
		else if(n == 4){
			TuLay(head);
		}
		else if(n == 5){
			display(head);
		}
		else if(n == 0) break;
	}
}
