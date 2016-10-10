//
//  main.cpp
//  UE32_1
//
//  Created by Arthur Scharf on 04/10/2016.
//  Copyright © 2016 RT. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;


/**
 * calculates the faculty of given integer n (can't be greater than 12 because integer overflow)
 */
long calcFak(long n){
//	if(n > 12) return -1;
	if(n > ULONG_MAX){
		cout <<" can't calculate faculty for "<<n<<endl;
	}
	if(n == 1) return 1;
	else return n * calcFak(n-1);
}


/** TODO check this shit */

double macLaurinSeries(int iter, int x){
	double xf = x * M_PI / 180;
	double sum = 0.0;
	for (int i=0; i<=iter; i++) {
		
		double u = pow(-1, i);
		
		double a = pow(xf, ((2 * i)+1));
		double fak = calcFak((long)((2*i)+1));
		
		double f = (u * a / fak);
		if(std::isfinite(f)){
			sum += (u * a / fak);
		}
	}
	return sum;
}
int arrRes[2];
/**
 * function to calculate quotient with division rest
 * returns an array of ints, first value is quiotient, second is remainder
 */
int* divmod(int x, int y){
	if(x < y){
		arrRes[0] = 0;
		arrRes[1] = x;
		return arrRes;
	}
	if(x == y){
		arrRes[0] = 1;
		arrRes[1] = 0;
		return arrRes;
	}
	if(x < y){
		int i = 0;
		int tmp = x;
		while(tmp > y){
			tmp -=y;
			i++;
		}
		cout <<"divmod: "<<i<<"for x: "<<x<<" y: "<<y<<endl;
		arrRes[0] = i;
		arrRes[1] = tmp;
		return arrRes;
	}
	return NULL;
}



int main(int argc, const char * argv[]) {
	
	
//	int i;
//	while (i< 10){
//		i++;
//		cout << i<<endl;
//	}
//	c d b a c  b bcd b a c
	/*
	 1: X = A_B and y = B
	 Iterates 10 times
	 displays the content of x
	 writes anywhere int he memory
	 sets x to 0 if x is equal to 3
	 none of the other answers
	 set of possible values information for the compiler to produe machine code set of possible operators
	 copies the value of x into y
	 puts the absolute of x into the value pointed by p
	 sets to 0 the lement of array t
	 
	 
	 */
	
//	int x = 6;
//	int y = 0;
//	int *p = &x;
//	int *q = &y;
//	*q = *p;
//	cout << q << " "<<p;
//	// insert code here...
	if(argc == 1){
		cout << "Usage:\n";
		cout << "parameters: [x] [y]"<<endl;
		cout << "x: 1 - calcs the sum of integers up to [y] provided by user"<<endl;
		cout << "x: 2 - calculates y!, [y] provided by user"<<endl;
		cout << "x: 3 - calculates max and min of n provided [y1...yn] values "<<endl;
		cout << "x: 4 - approximates the sine function using mac laurin series" <<endl;
		cout << "x: 5 - calculates the average, the maximum and the minimum of 5 values (y parameter not needed)"<<endl;
		cout << "x: 6 - calculates k over n combinations, [y] = [k n]"<<endl;
		cout << "x: 7 - d..."<<endl;
		return 0;
	}
	
	if(atoi(argv[1]) == 1){
		// we calculate sum of n first integers
		if(argc != 3){
			cout << "you're doin it wrong.";
			return -1;
		} else {
			int n = atoi(argv[2]);
			cout <<"sum is: "<< (n*(n+1)/2)<<endl;
			return 0;
		}
	} else if(atoi(argv[1]) == 2){
		if(argc != 3){
			cout << "you're doing it wrong."<<endl;
			return -1;
		} else {
			int n = atoi(argv[2]);
			long res = calcFak((long)n);
			if(res < 0){
				cout << "can not use numbers greater than 12 with this shitty software (number overflow in ints....)"<<endl;
				return 0;
			}else {
				cout << "faculty is: "<<res<<endl;
				return 0;
			}
		}
	} else if (atoi(argv[1]) == 3){
		if(argc < 3){
			cout << "too few arguments for this one!"<<endl;
			return -1;
		} else {
			std::vector<int> t;
			for(int i=2;i<argc;i++){
				t.push_back(atoi(argv[i]));
			}
			std::vector<int>::iterator minIt = std::min_element(std::begin(t), std::end(t));
			cout << "min is :"<<t.at(std::distance(std::begin(t), minIt)) << endl;
			std::vector<int>::iterator maxIt = std::max_element(std::begin(t), std::end(t));
			cout << "max is :"<<t.at(std::distance(std::begin(t), maxIt));
			return 0;
		}
	} else if (atoi(argv[1]) == 4){
		if(argc > 2){
			cout << "you can't use arguments here."<<endl;
			return -1;
		} else {
			int n = 0;
			int x = 0;
			cout << "please give a number for iterations:\n";
			cin >> n;
			if(cin.fail()){
				cout << "dude! use numbers.\n";
				return -1;
			}
			cout << n << " iterations, thank you. now give and value for x (the value to calculate the sin for)\n";
			cin >> x;
			if(cin.fail()){
				cout << "dude! use numbers.\n";
				return -1;
			}
			double res = macLaurinSeries(n, x);

			float compRes = sinf((float)(x/180.0*M_PI));

			cout << "macLaurin for "<<x<< " gives: "<<res<<". the sine function in math.h gives "<<compRes<<"\n";
			
			cout << "comparing maclaurin and sin-func in intervall pi to - pi with step size of .2"<<endl;
			cout << "macLaurin | sin | x-value"<<endl;
			float i = -1 * (M_PI);
			while (i < M_PI){
				/** TODO */
				cout << macLaurinSeries(10, i*180/M_PI) << " | " << sin(i)<< " | "<<i*180/M_PI<<endl;
				i += 0.2;
			}
			return 0;
		}
	} else if (atoi(argv[1]) == 5){
		if(argc > 2) {
			cout << "you're doing it wrong."<<endl;
			return -1;
		} else {
			std::vector<int> t;
			for(int i=0;i<5;i++){
				cout<<"please enter 5 numbers:\n";
				int temp = -1;
				cin >> temp;
				if(cin.fail()){
					cout << "dude! use numbers!\n";
					return -1;
				}
				t.push_back(temp);
			}
			
			// calculate the average
			int sum = 0;
			std::for_each(std::begin(t), std::end(t), [&] (int n) {sum +=n;});
			float average = sum /t.size();
			cout << "average is: "<<average<<endl;
			
			// calculate higher numbers
			cout << "numbers higher than the average: ";
			std::for_each(std::begin(t), std::end(t), [&] (int n) {if(n>average) cout << n << " ";});
			cout << endl;
			
			//number equal the average
			cout << "numbers equal the average: ";
			std::for_each(std::begin(t), std::end(t), [&] (int n) {if(n == average) cout << n << " ";});
			cout << endl;
			
			//
		}
	} else if (atoi(argv[1]) == 6){
		if(argc != 4){
			cout<<"wrong amount of parameters provided!\n";
			return -1;
		}
		int n = atoi(argv[2]);
		int k = atoi(argv[3]);
		long res = calcFak(n) / (calcFak(k)*calcFak(n-k));
		cout << n<<" over "<<k<<" is: "<<res;
		return 0;
	}
	
	
    return 0;
}


