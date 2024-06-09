#include "Header.h"

void find_prime(int no_of_primes)
{
    //reserve array size of prime numbers
    int* primes_array = new int[no_of_primes];
    if (no_of_primes > 0) primes_array[0] = 2; //if only one prime is required it is 2 !
    if (no_of_primes > 1)
    {
        //start the array by 3
        primes_array[1] = 3;
        //write no_of_primes times
        for (int i = 2; i < no_of_primes; i++)
        {   //start from the previous prime 
            for (int ii = primes_array[i - 1] + 2; true; ii += 2)
            {
                int is_prime = 1; //flag to know if the number is divisible by any factor
                //start from 2 until half the number we want to test 
                for (int iii = 0; iii < i; iii++)
                {
                    //loop to half the number only
                    if(primes_array[iii]<ii/2)
                    if (!(ii % primes_array[iii]))//if the number is divisible break
                    {
                        is_prime = 0;
                        break;
                    }
                }
                if (is_prime) // if the number has no factors it is a prime and should be stored in the result array
                {
                    primes_array[i] = ii;
                    break;
                }
            }
        }
    }
    //print all values
    if(no_of_primes>1)
    cout << "here are the first " << no_of_primes << " prime numbers:" << endl;
    for (int i = 0; i < no_of_primes; i++)
        cout << primes_array[i] << endl;
