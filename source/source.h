/*
 * source.h
 *
 *  Created on: 27 feb 2023
 *      Author: asier
 */

#ifndef SOURCE_H_
#define SOURCE_H_

typedef struct {
	char *name;
	struct Node **child;
	int numRel;
} Node;

typedef struct {
	struct Node ** nodes;
	int steps;
} Route;

void initializeNode(Node *node, char *name, Node **nodeList, int numRel);
void setName(Node *node, char *name);
void setRelationships(Node *node, Node **nodeList, int numRel);
void appendRelationship(Node *node, Node *nodeIN, int numRel);

#endif /* SOURCE_H_ */
