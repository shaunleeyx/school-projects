/*Author:Lee,Shaun
 * CPSC 3200
 * Version 2.0
 * 
 * Description: This class can have multiple factor objects and the query will return the number of divisible objects 
 * 
 * Class Invariant:
 * 1.The factor array is a stack type
 * 2.has a resizable container
 * 3.has a bunch of stats methods which returns highest/lowest successful number and other statistics
 * 
 * Interface Invariant
 * 1.Leave the constructor empty
 * 2.do not pop when container is at 0
 * 3.don't use 1 or 0 for factor numbers for obvious reasons
 * 
 * Implementation Invariant
 * 1.I made the statistics function return the string all together or individual functions for the flexibility for the users
 * 2.remove argument in the constructor it was intended to be the first push to the array but i changed it to none so its more straightforward
 */

using System;
namespace P2
{
    public class multiQ
    {
        private const uint SIZE = 5;
        private Factor[] array;
        private uint count;
        private int divisibleCount;
        private int HighestSuccess;
        private int LowestSuccess;
        private int NumOfSuccess;
        private int HighestDivisibleCount;
        private int MostSuccessfulQuery;


        public multiQ()
        {
            HighestSuccess = 0;
            LowestSuccess = 0;
            NumOfSuccess = 0;
            HighestDivisibleCount = 0;
            MostSuccessfulQuery = 0;
            divisibleCount = 0;
            count = 0;
            array = new Factor[SIZE];
        }
        /*
         * Precondition:value has to be above 1 because everything is divisible by 1
         * Postcondition:adds the factor number to the stack
         */        
        public void pushFactor(int input)
        {
            if (count + 1 > array.Length) resize();
           array[count] = new Factor(input);
            count++;
        }
        /*
         * Precondition: stack has to at least have 1 element
         * Postcondition:stack will have 1 less element
         */        
        public void popFactor()
        { 
            count--;
        }
        /*
         * Precondition:input has to be above 1
         * Postcondition: it will return the frequency of divisible numbers of the entry
         */        
        public int query(int input)
        {
            divisibleCount = 0;
            if (count < 1)
            {
                throw new System.InvalidOperationException("Please add 1 factor");
            }
            if (input == 0)
            {
                throw new System.InvalidOperationException("input cannot be 0");
            }


            for (int i = 0; i < count; i++)
            {
                if(array[i].div(input))
                {
                    if (HighestSuccess == 0 && LowestSuccess == 0)
                    {
                        HighestSuccess = input;
                        LowestSuccess = input;
                    }
                    if (HighestSuccess < input) HighestSuccess = input;
                    if (HighestSuccess > input) LowestSuccess = input;

                    NumOfSuccess++;
                    divisibleCount++;
                    if (HighestDivisibleCount <= divisibleCount)
                    {
                        HighestDivisibleCount = divisibleCount;
                        MostSuccessfulQuery = input;
                    }
                }
            }
            return divisibleCount;

        }

        public uint getCount()
        {
            return count;
        }

        // STATS FUNCTIONS
        public string printStats()
        {
            return "Highest Successful Entry:" + HighestSuccess + " Lowest Successful Entry:" + LowestSuccess + " Number of Successes:" + NumOfSuccess + " Highest Divisible Count:" + HighestDivisibleCount + " MostSuccessfulQuery: " + MostSuccessfulQuery;
        }

        public int getHighest()
        {
            return HighestSuccess;
        }

        public int getLowest()
        {
            return LowestSuccess;
        }
        public int getNumOfSuccess()
        {
            return NumOfSuccess;
        }
        public int getHighestDivisibleCount()
        {
            return HighestDivisibleCount;
        }
        public int getMostSuccessfulQueries()
        {
            return MostSuccessfulQuery;
        }


        /*
         * Precondition:count has to exceed container's capacity
         * Postcondition:container's capacity increase by twice the amount
         */
        private void resize()
        {
            Factor[] temp = new Factor[array.Length * 2];
            for (int i = 0; i < array.Length; i++)
            {
                temp[i] = array[i];
            }
            array = temp;
        }


    }
}
