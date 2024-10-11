bool nt[10000001];

void sang(int n){
	for(int i = 0; i <= n ;i++){
		nt[i]=true;
	}
	nt[0]=nt[1]=false;
	for(int i =2 ;i<=sqrt(n);i++){
		if (nt[i]==true) {
			for(int j = i * i;j<=n;j+=i){
				nt[j]=false;
			}
		}
 	}
}
int check(vector<int>v, int n){
	for(int i = 0 ; i<v.size() ; i++){
		if(n == v[i]) return 1;
	}
	return 0;
}

int main(){
	int n ; cin >> n;
	int m ; cin >> m;
	sang(n);
	vector<int>blum ;
	vector<pair<int, int> > blum2 ;
	for(int i = 0; i <= n; i++){
		for(int j = i+1 ; j < n ; j++){
			if(nt[i] && nt[j]){
			int q = i * j;
			int p = i+j ;
			pair<int, int> pa;
			pa = make_pair(i ,j);
			if(q < n ){
				blum.push_back(q);
				}
			if(p < n && check(blum, p)) blum2.push_back(pa);
			}
		}
	}
	
	if(check(blum,m)) cout << "YES" << endl ;
	for(const auto& pair : blum2){
		cout << "(" << pair.first << " " << pair.second << ")" << " " ;
	}
}
