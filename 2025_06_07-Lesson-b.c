#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};

/* free the tree's node storage */
void free_tree(struct node *r)
{
	/* stop on NULL */
	if( r==NULL )
		return;

	/* plumb the depths */
	free_tree(r->left);
	free_tree(r->right);
	free(r);		/* the (current) bottom node */
}

/* traverse the tree */
void traverse(struct node *r)
{
	/* stop on NULL, empty node */
	if( r==NULL )
		return;

	/* fetch data */
	printf("%d\n",r->key);
	/* go deeper! */
	traverse(r->right);
	traverse(r->left);
}

/* add a new node */
struct node *add_node(struct node *r,int k)
{

	if( r==NULL )
	/* allocate a new node */
	{
		r = malloc( sizeof(struct node) );
		if( r==NULL )
		{
			fprintf(stderr,"Unable to allocate memory\n");
			exit(1);
		}
		r->key = k;		/* set its key */
		r->right = NULL;
		r->left = NULL;
	}
	else
	{
		/* smaller values go on the left */
		if( k < r->key )
			r->left = add_node(r->left,k);
		/* larger values go on the right */
		else
			r->right = add_node(r->right,k);
	}
	return(r);
}

int main()
{
	static int count = 9;
	int data[] = {
		50, 20, 85, 16, 41, 59, 96, 3, 68
	};
	struct node *root = NULL;
	int x;

	/* construct the tree */
	for( x=0; x<count; x++ )
		root = add_node(root,data[x]);

	/* traverse the tree and output data */
	traverse(root);

	/* clean-up */
	free_tree(root);
	return 0;
}
