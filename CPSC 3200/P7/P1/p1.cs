//Shaun Lee
//CPSC 3200
//Version 1.0

using System;

namespace P1
{
    // DRIVER
    class MainClass
    {
        public static void Main(string[] args)
        {
            const int SIZE = 10;
            Random rng = new Random();
            Factor[] factors = new Factor[SIZE];
            //intialized a factor array with random factor values
            for(int i = 0; i < 10; i++)
            {
                //i picked a smaller number for factor since it doesn't make sense to have it as high as the div's entry
                factors[i] = new Factor(rng.Next(1, 25));
            }
            //tests the factor array through the testFactor() method
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("TestObj" + (i+1));
                testFactor(generateArray(), factors[i]);
            }
        }

        static void testFactor(int[] arrayinput, Factor factorinput)
        {
            //prints all intial field values
            Console.WriteLine("Factor is " + factorinput.getFactor() + " Divcount is " + factorinput.divCount() + " Active is  " + factorinput.isActive());
            // passes 100 integers through the div() method 
            for (int i = 0; i < 100; i++)
            {
                if (factorinput.isActive())
                {
                    //checks to see if the array is also divisible by factor and matches with the return value of div's
                    if ((arrayinput[i] % factorinput.getFactor() == 0) == factorinput.div(arrayinput[i]))
                    {
                        Console.WriteLine("Test Case " + i + " TRUE");
                    }
                    else
                    {
                        Console.WriteLine("Test Case " + i + " FALSE");
                    }

                }
                else
                {
                    Console.WriteLine("not active");
                }

            }
            // prints field values after the div() calls
            Console.WriteLine("Factor is " + factorinput.getFactor() + " Divcount is " + factorinput.divCount() + " Active is  " + factorinput.isActive());
            //see if the factor's field values reset after the reset()
            factorinput.reset();
            Console.WriteLine("factor reset");
            Console.WriteLine("Factor is " + factorinput.getFactor() + " Divcount is " + factorinput.divCount() + " Active is  " + factorinput.isActive());
            Console.WriteLine("DONE");
            Console.WriteLine();

        }
        //generates an array with 100 random numbers  from -200 to 200
        static int[] generateArray()
        {
            const int SIZE = 100;
            int[] array = new int[SIZE];
            Random rng = new Random();
            for(int i = 0; i < 100; i++)
            {
                array[i] = rng.Next(-200, 200);
            }
            return array;
        }
    }
}
