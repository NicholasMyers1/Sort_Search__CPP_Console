#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
int main(){
	srand(time(0));
	int x[500];//4,294,967,295
	cout<<"Randomly generated numbers:\t";
	for(int n=0;n<(sizeof(x)/sizeof(*x));n++){
		x[n]=rand()% 1000;
		cout<<x[n]<<", ";
	}
	//sorting:
	int length=((sizeof(x)/sizeof(*x))-1);
	int a=1,b=0,c=0,count=0,count1=0;
	while(count<length){
		for(int n=a;n>0;n--){
			if(x[a]<x[b]){
					c=x[b];
					x[b]=x[a];
					x[a]=c;
				a-=1;b-=1;
				count1+=1;
			}
			else{
				n=0;
			}
		}
		a+=1+count1;b+=1+count1;count+=1;count1=0;
	}
	////////////////////////////////////////////////////////////////////////////stuck on ((x/2-1)-1) and ((x/2-1)+1)
	cout<<"\nSorted low to high:\t\t";
	for(int n=0;n<(sizeof(x)/sizeof(*x));n++){
		cout<<x[n]<<", ";
	}cout<<"\n";
////////////////////////////////////////////////////////////////////////////////
	while(1==1){//infinite loop: 
		int input;cout<<"\nSearch the list: ";cin>>input;							//input value of array;
		int arrayVal=((sizeof(x)/sizeof(*x))/2)-1;								//length of array divided by 2 minus 1;
		int arrayValPrev=arrayVal;
		__int8 aboveHalf=0;
		int notFound=0;
		if(input>=x[arrayVal]){
			aboveHalf=1;
		}
		while(aboveHalf==0&&input!=x[arrayVal]&&x[0]<=input){
			while(x[arrayVal]<input&&x[arrayValPrev]>input){
				arrayVal=(arrayVal+arrayValPrev)/2;
				if(arrayValPrev-arrayVal<=1){
					aboveHalf=2;break;
				}
			}
			arrayValPrev=arrayVal;
			if(input>x[arrayVal]){
				arrayVal=(arrayVal+(sizeof(x)/sizeof(*x)-1))/2;
			}
			if(input<x[arrayVal]){
				arrayVal=arrayVal/2;
			}
		}
		while(aboveHalf==1&&input!=x[arrayVal]&&x[(sizeof(x)/sizeof(*x))-1]>=input){
				if(notFound==arrayVal){
					aboveHalf=2;break;
				}
				if(notFound<arrayVal){
					notFound=arrayVal;
				}
			while(x[arrayVal]>input&&x[arrayValPrev]<input){
				arrayVal=(arrayVal+arrayValPrev)/2;
				
				if(arrayValPrev-arrayVal==0){
					aboveHalf=2;break;
				}
			}
			arrayValPrev=arrayVal;
			if(input>x[arrayVal]){
				arrayVal=(arrayVal+(sizeof(x)/sizeof(*x)))/2;
			}
			if(input<x[arrayVal]){
				arrayVal=(arrayVal+arrayValPrev)/2;
			}
		}int count=0,tempArrayVal=arrayVal;
		while(input==x[arrayVal]&&arrayVal<=((sizeof(x)/sizeof(*x))-1)&&arrayVal>=0){
			arrayVal-=1;
			count+=1;
		}arrayVal=tempArrayVal+1;
		while(input==x[arrayVal]&&arrayVal<=((sizeof(x)/sizeof(*x))-1)&&arrayVal>=0){
			arrayVal+=1;
			count+=1;
		}arrayVal=tempArrayVal;
		if(input!=x[arrayVal]){
			cout<<"Your search of: '"<<input<<"' was not found!";
		}
		else{
			cout<<"The position of: '"<<arrayVal<<"' holds the value of your search: '"<<x[arrayVal]<<"', and it appears: '"<<count<<"' time(s).";
		}
	}
}
