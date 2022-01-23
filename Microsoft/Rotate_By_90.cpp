void rotate(int n,int a[][n]){
    //code here
    for(int i=0;i<n/2;i++){
        int m = n - 1;
        for(int j=i;j<m-i;j++){
           int temp = a[i][j];
           a[i][j] = a[j][m-i];
           a[j][m-i] = a[m-i][m-j];
           a[m-i][m-j] = a[m-j][i];
           a[m-j][i] = temp;
        }
    }
}