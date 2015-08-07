/*
 * haunted.cpp
 *
 *  Created on: 27-May-2015
 *      Author: aniesh
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;

int main(){
	int no_of_people;
	scanf("%d",&no_of_people);
	int array[no_of_people][2];
	for(int i=0;i<no_of_people;i++){
		scanf("%d %d",&array[i][0],&array[i][1]);
	}

	return 0;
}