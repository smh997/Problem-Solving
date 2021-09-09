int n;
int psum[78][78];

int get(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < n)
        return psum[i][j];
    return 0;
}

void build(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> psum[i][j];
			psum[i][j] += get(i-1, j) + get(i, j-1) - get(i-1, j-1);
        }
}

int rect(int x1, int y1, int x2, int y2){
    return psum[x2][y2] - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
}

int torus(){
	int max_sum = INT_MIN;
	for(int x1 = 0; x1 < n; x1++)
		for(int y1 = 0; y1 < n; y1++)
			for(int x2 = 0; x2 < n; x2++)
				for(int y2 = 0; y2 < n; y2++){
					int area;
					if(x2 >= x1 && y2 >= y1)
						area = rect(x1, y1, x2, y2);
					else if(x2 >= x1 && y2 < y1)
						area = rect(x1, 0, x2, y2) + rect(x1, y1, x2, n-1);
					else if(x2 < x1 && y2 >= y1)
						area = rect(0, y1, x2, y2) + rect(x1, y1, n-1, y2);
					else 
						area = rect(0, 0, x2, y2) + rect(x1, y1, n-1, n-1) + rect(x1, 0, n-1, y2) + rect(0, y1, x2, n-1);
					max_sum = max(max_sum, area);
				}
	return max_sum;
}