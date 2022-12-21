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

