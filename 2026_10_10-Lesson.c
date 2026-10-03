#include <stdio.h>
#include <string.h>

/* tagged union definition */
struct u_data {
	/* tags */
	enum {
		TYPE_STRING,
		TYPE_LONG
	} data_type;
	/* payload */
	union values {
		char ch[8];
		long li;
	} v;
};

/* generate output based on tag */
void output(struct u_data d)
{
	switch(d.data_type)
	{
		case TYPE_STRING:
			printf("String value is: %s\n",d.v.ch);
			break;
		case TYPE_LONG:
			printf("Long int value: %li\n",d.v.li);
			break;
		default:
			printf("Unknown data type\n");
	}
}

int main()
{
	struct u_data data;

	/* set data type tag and data */
	data.data_type = STRING;
	strcpy(data.v.ch,"Hello!");

	/* output proper data */
	output(data);

	return 0;
}
