
int main(){
	int n,t,i,j,k,iTemp;	//???????n??n?n????tijk???????iTemp???????????????
	cin>>n;	//??n
	int a[n][n][n],iSum[n];	//??n?n???????????????????
	memset(iSum,0,sizeof(iSum));
	for (i=0;i<=n-1;i++){	//?i???
		for (j=0;j<=n-1;j++){	//?j?
			for (k=0;k<=n-1;k++){	//?k?
				cin>>a[i][j][k];	//??????
			}
		}
	}
	for (i=0;i<=n-1;i++){  //??i???????
	    for (t=1;t<=n-1;t++){	//??????t???
	    	for (j=0;j<=n-1;j++){	//??j?????
	    		if (a[i][j][0]<0){	//???j??????????
	    			continue;	//???????
	    		}
	    		else{	//???iTemp??????
	    			iTemp=a[i][j][0];
	    		}
	    		for (k=0;k<=n-1;k++){	//???????????
	    			if ((a[i][j][k]<iTemp)&&(a[i][j][k]>=0)){
	    				iTemp=a[i][j][k];
	    			}
	    		}
	    		for (k=0;k<=n-1;k++){	//????????????????????
	    			a[i][j][k]=a[i][j][k]-iTemp;
	    		}
	    	}
	    	for (k=0;k<=n-1;k++){	//??k?????
	    		if (a[i][0][k]<0){	//???k??????????
	    			continue;	//???????
	    		}
	    		else{
	    			iTemp=a[i][0][k];	//???????????iTemp
	    		}
	    		for (j=0;j<=n-1;j++){
	    			if ((a[i][j][k]<iTemp)&&(a[i][j][k]>=0)){	//???k???????
	    				iTemp=a[i][j][k];
	    			}
	    		}
	    		for (j=0;j<=n-1;j++){	//???????????????????
	    			a[i][j][k]=a[i][j][k]-iTemp;
	    		}
	    	}
	    	iSum[i]=iSum[i]+a[i][t][t];	//??t,t?????????
	    	for (k=0;k<=n-1;k++){	//???t????
	    		a[i][t][k]=-1;
	    	}
	    	for (j=0;j<=n-1;j++){	//???t????
	    		a[i][j][t]=-1;
	    	}
	    }
	}
	cout<<iSum[0];	//???????????????
	for (i=1;i<=n-1;i++){
		cout<<endl<<iSum[i];
	}
	return 0;
}