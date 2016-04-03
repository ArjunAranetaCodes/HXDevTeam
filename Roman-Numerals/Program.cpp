#include<iostream>

using namespace std;

int returnDigit(char word){
	if(word == 'I')
		return 1;
	if(word == 'V')
		return 5;
	if(word == 'X')
		return 10;
	if(word == 'L')
		return 50;
	if(word == 'C')
		return 100;
	if(word == 'D')
		return 500;
	if(word == 'M')
		return 1000;
}

string toWord(int num){
	string word = "";
	string strOnes[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string strTens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	string strTens2[] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	
	int counter = 1;
	int intOnes = 0;
	
	for(int i = num; i > 0; i=i/10){
		//cout << i << endl;
		//cout << i % 10 << " - " << strOnes[i % 10] << endl;
		
		if(counter == 1){
			if((i % 10) == 0){
				//do nothing
			}else{
				word = strOnes[(i % 10)] + " " + word;
			}
			intOnes = i % 10;
		}
		
		if(counter == 2){
			if((i % 10) == 1){
				word = strTens[intOnes];				
			}else if((i % 10) == 0){
				//do nothing
			}else{				
				word = strTens2[(i % 10) - 2] + " " + word;
			}
		}
		
		if(counter == 3){
			word = "hundred " + word;
			word = strOnes[i % 10] + " " + word;
		}
		
		if(counter == 4){
			word = "thousand " + word;
			word = strOnes[i % 10] + " " + word;
		}
		
		
		counter++;
	}
	
	return word;
}

int main(){
	
	string input = "";
	int total = 0;
	int intCurrent = 0;
	
	cout << "Enter roman number: ";
	cin >> input;
	
	for(int i = input.length(); i > 0; i--){
		//cout << input[i-1] << " - " << returnDigit(input[i-1]) << endl;
		
		intCurrent = returnDigit(input[i-1]);
		
		if(i >= 2){
			if(returnDigit(input[i-1]) > returnDigit(input[i-2])){						
				intCurrent = returnDigit(input[i-1]) - returnDigit(input[i-2]);		
				//cout << returnDigit(input[i-1]) << " - " << returnDigit(input[i-2]) << " = " << intCurrent << endl;		
				i--;
			}
		}
		
		
		//cout << intCurrent << endl;
			
		total = total + intCurrent;
				
	}
	
	cout << toWord(total);
	//cout << total;
	
	return 0;
}
