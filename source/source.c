/*
 * source.c
 *
 *  Created on: 27 feb 2023
 *      Author: asier
 */

#include "source.h"
#include <stdio.h>
#include <stdlib.h>

void initializeNode(Node *node, char *name, Node **nodeList, int numRel) {
	node->name = name;
	node->child = (Node**) nodeList;
	node->numRel = numRel;
}

void setName(Node *node, char *name) {
	node->name = name;
}

void setRelationships(Node *node, Node **nodeList, int numRel) {
	node->child = (Node*) nodeList;
}

void appendRelationship(Node *node, Node *nodeIN, int numRel) {
	Node **list = malloc(sizeof(Node*) * (numRel + 1));

	for (int i = 0; i < numRel ; i++) {
		list[i] = (Node*) node->child[i];
	}

	list[numRel] = nodeIN;
	free(node->child);
	node->child = (Node**) list;
	node->numRel++;
}
