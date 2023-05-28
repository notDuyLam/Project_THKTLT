#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX 100

typedef struct node* REF;
static struct node
{
	int key;
	REF next;
};

static fstream file;

struct stack
{
	int top;
	string A[MAX];
};