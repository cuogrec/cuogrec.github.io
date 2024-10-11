void sx(string a[], int n){
	int R = 0, W = 0 , B = 0;
	for(int i = 0 ; i<n ; i++){
		if(a[i] == "đỏ") R++;
		else if(a[i] == "trắng") W++;
		else B++;
	}
	for(int i = 0 ; i < R ; i++){
		a[i] = "đỏ" ;
	}
	for(int i = R ; i<R+W ; i++){
		a[i] = "trắng";
	}
	for(int i = R+W ; i<R+W+B ; i++){
		a[i] = "xanh" ;
	}
}
int main(){
	int n ; cin >> n;
	string a[n];
	for(int i = 0 ; i<n ; i++){
		cin >> a[i];
	}
	sx(a, n);
	for(int i = 0 ; i<n ; i++){
		cout << a[i] << " " ;
	}
}
