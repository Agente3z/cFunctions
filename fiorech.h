//Christian Fiore

#include <stdio.h>
#include <stdlib.h>
//IN MAIN
//#include <time.h>

//random int
int randInt(int min, int max){
	//in main
	//srand(time(NULL));
	
	int nCas = rand()%(max-min+1)+min;
	
	return nCas;
}

//random float (x decimals)
float randFloat(float min, float max, int nDecimals){
	int i,decimali=1;
	//in main
	//srand(time(NULL));
	
	for(i=0;i<decimali;i++){
		decimali *= 10;
	}
	
	int intervallo = (max-min+1)*decimali;
	float nCas = rand()%intervallo+min*decimali;
	nCas /= decimali;
	
	return nCas;
}

//swap two int
void swapInt(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

//shuffles an int array
void shuffleIntArray(int array[], int dim, int depht){
	int i;
	//in main
	//srand(time(NULL));
	for(i=0;i<depht;i++){
		swapInt(&array[rand()%dim], &array[rand()%dim]);
	}
}

//round float
float roundFloat(float n,int dec){
	int i,fattore=1;
	
	for(i=0;i<dec;i++){
		fattore *= 10;
	}
	
	n *= fattore;
	n = (int)n;
	n /= fattore;
	
	return n;
}

//raising to a power
int pow(int base, int exponent){
	int i,numero=base;
	if(exponent==0){
		numero=1;
	}else{
		for(i=1;i<exponent;i++){
			numero*=base;
		}
	}
	
	return numero;
}

//splits a number in his digits (create an array with 50 elements)(returns the number of digits)
int digitsInt(int digits[], long long int number, int nDigits){
	int i,j,k,cifreTemp[50];
	
	while(number!=0){
		cifreTemp[i] = number%10;
		number/=10;
		i++;
	}k=i;
	
	for(j=0;j<i;j++){
		digits[j] = cifreTemp[k-1];
		k--;
	}
	nDigits = i;
	
	return nDigits;
}

//square root of an integer (with x decimals)(tells you if it's a perfect square root)
float sqrt(long long int number, int *perfect, int decimals){
	int i,j,k,len,cifre[50],cifre2[25],nCifre,resParziale,radice[25],moltiplicazione,parziale=1;
	float floatRadice=0;
	
	number = number*pow(10, decimals*2);
	
	nCifre = digitsInt(cifre, number, nCifre);
	j=0,i=0;
	if(nCifre%2==1){
		cifre2[0] = cifre[j];
		i++;
		j++;	
	}
	for(k=0;k<nCifre/2;k++){
		cifre2[i] = cifre[j]*10+cifre[j+1];
		j+=2;
		i++;
	}
	len=i;
	for(i=0;i<25;i++){
		radice[i] = 1;
	}
	
	resParziale=0;
	while(radice[0]*radice[0]<=cifre2[0]){
		radice[0]++;
	}radice[0]--;
	resParziale=cifre2[0]-radice[0]*radice[0];
	
	for(j=1;j<len;j++){
		resParziale = resParziale*100 + cifre2[j];
		moltiplicazione=0;
		for(i=0;i<parziale;i++){
			moltiplicazione = moltiplicazione + radice[i] * pow(10, parziale-i);
		}moltiplicazione = moltiplicazione*2;
		
		i=1;
		while((moltiplicazione+i) * i <= resParziale){
			i++;
		}i--;
		radice[j] = i;
		resParziale = resParziale - (moltiplicazione+i) * i;
		parziale++;
	}
	
	for(i=0;i<len;i++){
		floatRadice = floatRadice + radice[i] * pow(10, len-i-1);
	}

	floatRadice /= pow(10, decimals);
	number /= pow(10, decimals*2);
	
	if(floatRadice*floatRadice==number){
		*perfect = 1;
	}else{
		*perfect = 0;
	}
	
	return floatRadice;
}


//creates int array
void createIntArray(int array[],int dim,int min,int max){
	int i;
	
	for(i=0;i<dim;i++){
		array[i] = randInt(min,max);
	}
	
}

//prints int array
void printIntArray(int array[], int dim){
	int i;
	
	for(i=0;i<dim;i++){
		printf("%d ",array[i]);
	}
	
}

//create float array (x decimals)
void createFloatArray(float array[],int dim,float min,float max, int decimals){
	int i;
	
	for(i=0;i<dim;i++){
		array[i] = randFloat(min,max,decimals);
	}
	
}

//print float array (2 decimals)
void printFloatArray(float array[], int dim){
	int i;
	
	for(i=0;i<dim;i++){
		printf("%.2f ",array[i]);
	}
	
}

//finds max in an int array
int maxIntArray(int array[], int dim){
	int max,i;
		
	max=array[0];
	for(i=0;i<dim;i++){
		if(array[i]>max){
			max=array[i];
		}
	}
	
	return max;
}

//finds min in an int array
int minIntArray(int array[], int dim){
	int min,i;
		
	min=array[0];
	for(i=0;i<dim;i++){
		if(array[i]>min){
			min=array[i];
		}
	}
	
	return min;
}

//in place selection sort algorithm for int array
void selectionSort(int array[], int dim){
	int i,max,min,k,c,pos;
	
	for(i=0,max=maxIntArray(array,dim);i<dim;i++){
		min=max+1;
		for(k=i;k<dim;k++){
			if(array[k]<min){
				min=array[k];
				pos=k;
			}
		}
		swapInt(&array[i], &array[pos]);
	}
}

//bubble sort algorithm for int array
void bubbleSort(int array[], int dim){
	int i,flag;
	
	for(i=0; i<dim-i-1; i++){
		flag=1;
		if(array[i] > array[i+1]){
			swapInt(&array[i], &array[i+1]);
			flag=0;
		}
		if(flag==1){
			break;
		}
	}
}

//insertion sort algorithm for int array
void insertionSort(int array[], int dim){
	int i,k,j,c;
	
	for(i=1,k=0;i<dim;i++,k=i-1){
		c = array[i];
		while(c<array[k] && k>=0){
			k--;
		}k++;
		for(j=i;j>k;j--){
			array[j] = array[j-1];
		}
		array[k] = c;
	}
}
