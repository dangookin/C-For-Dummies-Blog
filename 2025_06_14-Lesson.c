#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};

#define TRUE 1
#define FALSE 0

/* search for a value */
struct node *search(struct node *r, int v)
{
	/* return on empty or when key found */
	if( r==NULL || r->key == v )
		return(r);

	/* search for values less */
	if( v < r->key )
		return( search( r->left,v ) );
	/* search for values greater */
	return( search(r->right,v ) );
}

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
	struct node *result;
	int x,value;

	/* construct the tree */
	for( x=0; x<count; x++ )
		root = add_node(root,data[x]);

	/* search the tree */
	printf("Locate value: ");
	scanf("%d",&value);
	result = search(root,value);
	if( result!=NULL )
		printf("Value %d found\n",value);
	else
		printf("Value %d not found\n",value);

	/* clean-up */
	free_tree(root);
	return 0;
}
