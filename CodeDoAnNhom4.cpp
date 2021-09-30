#include<bits/stdc++.h>
FILE *fi, *fo;
	int i,j,d,m,n,k,x;
	double max,max2,dtt1,dtt2;
	double A[100][100],tb,B[100][100],t1,t2,C[100][100],D[100][100],E[100][100];
void swap(int *a, int *b) 
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
void docfile(){
	fi=fopen("input.txt","r");
	fscanf(fi,"%d",&m);
	fscanf(fi,"%d",&n);
	for(i=1;i<=m;i++)						//ham doc du lieu
		for(j=1;j<=n;j++)
			fscanf(fi,"%lf",&D[i][j]); 
	fclose(fi);
}
void chonpp(){
	if(m<n){				//Neu user nhieu hon item, su dung item item va nguoc lai
		swap(&m,&n);
		for(i=1;i<=m;i++)	
			for(j=1;j<=n;j++)
				A[i][j]=D[j][i];
		printf("Su dung phuong phap Item-item:\nChuyen vi ");
	}
	else{
		printf("Su dung phuong phap User-User:\n");
		for(i=1;i<=m;i++)	
			for(j=1;j<=n;j++)
				A[i][j]=D[i][j];}
	printf("mang ban dau:");		
	for(i=1;i<=m;i++){
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%5.2lf ",A[i][j]);}
}
void copymang(){
	for(i=1;i<=m;i++)	
			for(j=1;j<=n;j++)
				E[i][j]=A[i][j];
}
void chuanhoa(){
	for(i=1;i<=n;i++){		//tinh trung binh cot
		tb=0;d=0;
		for(j=1;j<=m;j++){
			if(E[j][i]!=-1){
				d=d+1;
				tb=tb+A[j][i];}}
	tb=tb/d;
	A[m+1][i]=tb;
	for(j=1;j<=m;j++)
			if(A[j][i]==-1)
				A[j][i]=0;
			else
				A[j][i]=A[j][i]-tb;
	}
	printf("\nmang sau chuan hoa :");
	for(i=1;i<=m;i++){
		printf("\n");
		for(j=1;j<=n;j++){
			C[i][j]=A[i][j];
			printf("%5.2lf ",A[i][j]);
			}}
}
void tuongtu(){
		for(i=1;i<=n;i++)		//tinh tich vo huong 2 vector
		for(j=1;j<=n;j++){
			t1=0;t2=0;
			for(k=1;k<=m;k++){
				B[i][j]+=A[k][i]*A[k][j];
				t1+=A[k][i]*A[k][i];
				t2+=A[k][j]*A[k][j];	
				}
			B[i][j]=B[i][j]/sqrt(t1*t2);	
		}	
	printf("\n");
	printf("mang do tuong tu:\n");
	for(i=1;i<=n;i++){
		printf("\n");
		for(j=1;j<=n;j++)
			printf("%5.2lf ",B[i][j]);}
}
void timmax(){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(E[j][i]==-1){
					max=-5;
					dtt1=-1;
				for(int k=1;k<=n;k++){
					if(E[j][k]!=-1 && B[i][k]>=max){		//tim max
					dtt1=A[j][k];
					max=B[i][k];	
					x=k;				
					}
				}
				max2=-10;
				dtt2=-5;
				for(int t=1;t<=n;t++){
					if(E[j][t]!=-1 && B[i][t]>=max2 && t!=x){		//tim max2
						max2=B[i][t];
						dtt2=A[j][t];
						}
				}
				C[j][i]=(max*dtt1+max2*dtt2)/(fabs(max)+fabs(max2));
			}
		}
	}}
void matranhoanthien(){
	fo=fopen("D:/test/test.out","w");
		printf("\nma tran hoan thien:\n");
	if(n<m){
		swap(&m,&n);
		for(i=1;i<=m;i++)	
			for(j=1;j<=n;j++){
				D[i][j]=C[j][i]+A[n+1][i];
		}
		for(i=1;i<=m;i++){
		printf("\n");
		fprintf(fo,"\n");
		for(j=1;j<=n;j++){
			fprintf(fo,"%5.2lf ",D[i][j]);
			printf("%5.2lf ",D[i][j]);}}
	}
	else{
	for(i=1;i<=m;i++){
		printf("\n");
		fprintf(fo,"\n");
		for(j=1;j<=n;j++){
			fprintf(fo,"%5.2lf ",C[i][j]+A[m+1][j]);
			printf("%5.2lf ",C[i][j]+A[m+1][j]);}}
	}
	fclose(fo);
	}
//////////////////////////////////////////////////////////////////////////////////////

main(){
	
	
	docfile();	
	chonpp();
	copymang();	
	chuanhoa();
	tuongtu();
	timmax();
	matranhoanthien();
		
}
