#pragma once
#include <iostream>
#include <fstream>
using namespace std;

typedef struct node* REF;
static struct node
{
	int key;
	REF next;
};
