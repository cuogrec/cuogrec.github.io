#include<bits/stdc++.h>
using namespace std;
  int dem[100];
	int main(){
		int n ; cin >> n;
		int max = -1 , min = 1e7;
		int a[n+1];
		for(int i = 0; i<=n ; i++){
			cin >> a[i];
			dem[a[i]]++;
			if(a[i] > max){
				max = a[i];
			}
			if(a[i] < min){
				min = a[i];
			}
		}
		// in ra các năm có số lượng người sinh ra là lớn nhất và bé nhất 
		cout << "SO NGUOI SINH RA NHIEU NHAT LA: " << max << " " ;
		for(int i = 0 ; i<=n ; i++){
			if(a[i] == max){
				cout << " VAO NAM " << i+1920 << "  ";
			}
		}
		cout << endl;
		cout << "SO NGUOI SINH RA IT NHAT LA: " << min << " " ;
		for(int i = 0 ; i<=n ; i++){
			if(a[i] == min){
				cout << "VAO NAM " << i+1920 << "  ";
			}
		}
		cout << endl;
		//tìm số năm có cùng số lượng người sinh ra
		for(int i = 0 ; i<=n ; i++){
			if(dem[a[i]] > 1){
				cout << "SO LUONG NGUOI SINH RA: " << a[i] << "  ";
				for(int j = i ; j<=n ; j++){
					if(a[j] == a[i] && dem[a[i]] > 1){
						cout << "VAO NAM " << j+1920 << "  " ;
					}
				}
				cout << endl;
				dem[a[i]] = 0;
			}
		}
}
