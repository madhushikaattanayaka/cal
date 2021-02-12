#include <stdio.h>
#include <string.h> // for strlen
#include <stdlib.h> // for atoi 
#include <assert.h> // for assert 
void splitExpression(char *str, int *v1, int *v2, char *op)
{
  int i,found;
  char buff[20];
  int j=0;
  for(i=0, found=0; i < strlen(str); i++) {
    if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
      *op     = str[i];     // found the operator 
      buff[j] = '\0';       // terminate the string
      j       = 0;          // use the same buffer to get next value
      *v1      = atoi(buff);
      assert(!found); // we found a operator, should not have found one before
      found = 1;
    } // end if we found a op
    
    else { // if not an operator, copy to buffer 
      buff[j++] = str[i];
    }
  }

  buff[j] = '\0';
  *v2 = atoi(buff);
}

int main(int argc, char **argv)
{
  int v1, v2, res;
  
  char op,str[10];
   
		
	while(strcmp(str, "quite") != 0){
		memset(str, '\0', sizeof(str));

		printf("ENTER AN EXPRESSION \n");
		scanf(" %[^\t\n]s",&str);



		splitExpression(str, &v1, &v2, &op);

		switch(op) {
		case '+' :
		res = v1 + v2;
		break;
		case '-':
		 res = v1 - v2;
		 break;
		case '*' :
		 res = v1 * v2;
		break;
		case '/':
		res = v1 / v2;
		break;
		default:
		printf("Unknown operation\n");
		return -1;

		}
	if(strcmp(str, "quite") != 0){
	  printf("%s= %d\n",str, res);
    } 
	
	}
    	
  return 0;
}
//A.M.M.S.Attanayake