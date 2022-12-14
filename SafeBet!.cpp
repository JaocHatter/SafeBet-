#include <bits/stdc++.h>
using namespace std;
struct data{
	double *arr;
};
//now i can use qsort
int comparator(const void *x_void,const void *y_void){
	int *x=(int*)x_void,*y=(int*)y_void;
	return *x-*y;
}
void print(data *matriz){
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<setw(6)<<setprecision(2)<<matriz[i].arr[j];
		}
		cout<<endl;
	}
}
int solve(double mount,double p1,double p2,double p3){
	data *matrix=new data[3];
	//we will work with 3 Random Variables x,y,z=mount-x-y;
	for(int i=0;i<3;i++){
		matrix[i].arr=new double[4];
		memset(matrix[i].arr,0,4*sizeof(double));
	}
	matrix[0].arr[0]=p1;
	matrix[0].arr[2]=-1;
	matrix[0].arr[3]=mount;
	matrix[1].arr[1]=p2;
	matrix[1].arr[2]=-1;
	matrix[1].arr[3]=mount;
	matrix[2].arr[0]=p3;
	matrix[2].arr[1]=p3;
	matrix[2].arr[2]=1;
	matrix[2].arr[3]=mount*(p3-1);
	print(matrix);
	cout<<"Solving..."<<endl;
	for(int i=0;i<3;i++){
		double pivote=matrix[i].arr[i];
		for(int k=i;k<4;k++){
			matrix[i].arr[k]=matrix[i].arr[k]/pivote;
		}
		for(int j=0;j<3;j++){
			if(j==i){
				continue;
			}
			double pivote2=matrix[j].arr[i];
			for(int g=i;g<4;g++){
				matrix[j].arr[g]=matrix[j].arr[g]-pivote2*matrix[i].arr[g];
			}
		}
	}
	print(matrix);
	return matrix[2].arr[3];
}

int main(){
	double p1,p2,p3,monto;
	cout<<"================= s t a k e ================="<<endl;
	cout<<"		    By Jaoc"<<endl;
	cout<<"***** How Works? ******"<<endl;
	cout<<"In the first line you have to introduce the multiplicator that your team wins..."<<endl;
	cout<<"in the second line put the multiplicator if thee counter team wins"<<endl;
	cout<<"Put in the third line the multiplicator that your team draw"<<endl;
	cout<<" 							Ez true?"<<endl;
	cout<<"1) Ingrese el win multiplicador:"<<endl;
	cin>>p1;
	cout<<"2) Ingrese el lose multiplicador:"<<endl;
	cin>>p2;
	cout<<"3) Ingrese el draw multiplicador:"<<endl;
	cin>>p3;
	cout<<"Introduce el monto a apostar"<<endl;
	while(true){
		cout<<"W A R N I N G ! ------Introduzca 666 para terminar con el programa -------"<<endl;
		cin>>monto;
		if(monto==666){
			break;
		}
		double ganancia=solve(monto,p1,p2,p3);
		cout<<"Su ganancia es: "<<ganancia<<endl;
	}
	cout<<"Programa finalizado";
	return 0;
}