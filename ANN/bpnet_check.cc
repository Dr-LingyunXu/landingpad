#include <bpnet.h>
#include <stdio.h>
#include <math.h>

#define AVERAGE 1

/* This is a short program to test the backpropagation
   neural network class.  It trains a two layer network
   to solve the exclusive-or function.

   INPUTS | OUTPUT
   A    B |
  ----------------
   0    0 |   0
   0    1 |   1
   1    0 |   1
   1    1 |   0

   Compiling with one line using g++:
   g++ -I. -O2 -o bpnet_check bpnet_check.cc bpnet.cc my_misc.cc
*/

int main()
{
  /* create a backprop network with two input neurons, 
     two hidden neurons, and one output neuron */
  bpnet *net = new bpnet(3,2,2,1);

  double inputs[2];
  double outputs[1];
  double errors[1];

  double total_error=0.0;
  int int_inputs[2];
  int targets[1];
  int i,j;

  net->set_output_range(0.0, 1.0);
  // net->set_theta(1.0);
  // net->set_step(0.1);
  // net->set_momentum(0.1);

  for(i=0;i<10000000;i++)
    {
      /* use the two least significant bits of i as inputs */
      int_inputs[0] = (i>>1) & 1;
      int_inputs[1] = i & 1;
      /* exclusive or them together for the desired output */
      targets[0] =  int_inputs[0] ^ int_inputs[1];
      /* Copy the inputs to the input vector */
      inputs[0] = int_inputs[0];
      inputs[1] = int_inputs[1];
      
      /* Have the network compute the output vector (in this case scalar) */
      net->evaluate(inputs,outputs);
      
      /* Calculate the error vector (in this case it is a scalar) */
      errors[0] = targets[0] - outputs[0];

      /* Run the backpropagation algorithm to update the weights */
      net->backprop(errors);

      /* Print a report every 20 iterations. */
      if(!(i%20))
	if(!AVERAGE)
	  {
	    printf("\n");
	    for(j=0;j<4;j++)
	      {
		int_inputs[0] = (j>>1) & 1;
		int_inputs[1] = j & 1;
		targets[1] =  int_inputs[0] ^ int_inputs[1];
		inputs[0] = int_inputs[0];
		inputs[1] = int_inputs[1];
		net->evaluate(inputs,outputs);
		printf("%d %d %lf\n", int_inputs[0], int_inputs[1],outputs[0]);
	      }
	  }
	else
	  {
	    printf("Total Error: %lf\n",total_error/20);
	    total_error = 0.0;
	  }
      else
	total_error += pow(errors[0],2.0);

      /* End of loop */
    }
  
  return 0;
}
